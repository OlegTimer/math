#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define I 20000 //number of iterations
#define M 0.01 //error margin to zero 

string s="Horner's iteration for polynom w real x coeff and natural grades; \
Ration. roots\n\n\
Enter tab-separated line of x coeff to _input.txt in program's directory. \n\
Add tab-separated Start and End to _input.txt in program's directory. \n\
\nTry:\t3x^4 + \t6x^3\t-123x^2\t-126x\t+1080=0 S=-10; \tE=10\
\nEnter:\t3\t6\t-123\t-126\t 1080\t-10\t10 \
\nUnique rational roots: -6	-4	3	5 \
\n\nWarning. Roots may be close. i.e. 0.199996~0.2\t;\t1.85128e-017~0 \n\
(Dot for fraction nums, i.e. 1.0). \n\
Program will make many steps in the S<=duration<=E\
\nRun the program to find rational roots\n\n\n";
vector<double> v;
vector<double> v2;


string show_fun(){//shows function of v2 coeff: k1*x^n1 + k2*x^n2 ...
string answ = "";
string text;
std::ostringstream strs;
int grade = v2.size();
for (int i = 0; i < v2.size(); i++){	
grade--;
strs.str("");
if (v2[i]!=0)	{//
if (i>0 && v2[i]>=0){answ+="+";}   			  	
if(v2[i]!=1 && v2[i]!=-1)			{
strs << v2[i];
text = strs.str(); 
	   			   					}
if( v2[i]==-1)						{
text="-";
									}
if( v2[i]==1)						{
text="";
									}										   			   					
answ+=text;
if (i<v2.size()-1 )			{
answ+="x";
if (grade!=1){
answ+="^";
strs.str("");
strs << grade;
text = strs.str();
answ+=text;
} 
answ+=" ";
			   	   		  	}
else{if (v2[i]==1 || v2[i]==-1){answ+="1";}}
			   }//
} 	
return answ;
}


double horner(double proot){//takes coeff from v and writes to v2. root, if t=0
v2.clear();
v2.push_back(v[0]);
double t;
for (int i = 1; i < v.size(); i++) {
t=v2[i-1]*proot+v[i];	
if (i < v.size()-1) {v2.push_back(t);}
}
return t;
}


int main()
{
cout<<s;
ifstream in("_input.txt", ios::in | ios::binary);
if(!in) {
ofstream out3("_input.txt"); 
if(!out3) {
cout << "Cannot create _input.txt\n";
return 1;
}
out3 << s;
out3.close();
}
s="";
char ch;
while(in) {
in.get(ch);
if(in) { 
s+=ch;}
}
in.close();

vector<string> arr;
  string str = s;
  string delim("\t");
  size_t prev = 0;
  size_t next;
  size_t delta = delim.length();
  while( ( next = str.find( delim, prev ) ) != string::npos ){
    arr.push_back( str.substr( prev, next-prev ) );
    prev = next + delta;
  }
arr.push_back( str.substr(prev ) );

for (int i = 0; i < arr.size(); i++) {
	v.push_back( atof(arr[i].c_str()) );}	
if (v.size() <4) {cout<<"\n!Error in input!\n"; system("pause"); return 1;}

double start = v[v.size()-2];
double end = v[v.size()-1];
if (end==start){cout<<"\n!Error in input! S!=E\n"; system("pause"); return 1;}
if (start>end){double ee = start; start = end; end = ee;}
v.pop_back();
v.pop_back();

for (int i = 0; i < v.size(); i++) {v2.push_back(v[i]);}
cout<<show_fun()<<" =0 ; S="<<start<<"; E="<<end<<"\n\n";

double step = (end-start)/I;

double proot = start;
double h = horner(proot);
string sig="-"; if (proot<0){sig="+";}
double mm =  proot;
if (proot<0) {mm=-mm;} 			
cout<<"(x"<<sig<<mm<<")( "<<show_fun()<<" ) = "<<h<<" S_Root: "<<proot<<"\n";
proot = end;
h = horner(proot);
sig="-"; if (proot<0){sig="+";}
mm =  proot;
if (proot<0) {mm=-mm;} 			
cout<<"(x"<<sig<<mm<<")( "<<show_fun()<<" ) = "<<h<<" E_Root: "<<proot<<"\n\n";

cout<<"Approx. potential roots:\n";
double cur = start;
int prevsign=0;
int prevsign2=0;
while (cur<end+step){
h = horner(cur);
prevsign2=0;
if (h>M){prevsign2 = 1;}
if (h<-M){prevsign2 = -1;}
if (prevsign<0  && h>0 && prevsign2!=0){cout<<cur-step<<"\n";}
if (prevsign>0  && h<0 && prevsign2!=0){cout<<cur-step<<"\n";}
if (prevsign2!=0){prevsign = prevsign2;	 }
cur+=step;
}

cout<<"\n\nby OlegTim	";
system("pause");
return 0;
}
