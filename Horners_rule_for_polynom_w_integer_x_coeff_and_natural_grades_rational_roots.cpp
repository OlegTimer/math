#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <set> 
using namespace std;

string s="_Horner's rule for polynom w integer x coeff and natural grades; \
Ration. roots_\n\n\
Enter tab-separated line of x coeff to _input.txt in program's directory. \n\
\nFor example:\t3x^4 + \t6x^3\t-123x^2\t-126x\t+1080 = 0 \
\nEnter:\t\t3\t6\t-123\t-126\t 1080 \
\nUnique rational roots: -6	-4	3	5 \
\nWarning. Roots may be close. i.e. 0.199996~0.2\t;\t1.85128e-017~0 \
\nRun the program to find rational roots.\n\n\n";
vector<int> v;
vector<int> v2;


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
	v.push_back( atoi(arr[i].c_str()) );}	
if (v.size() <2) {cout<<"\n!Error in input!\n"; system("pause"); return 1;}

for (int i = 0; i < v.size(); i++) {v2.push_back(v[i]);}
cout<<show_fun()<<" =0\n\n";

vector<int> l;
vector<int> m;
set<double> proots;
int free_member = abs (v[v.size()-1]);
int top_grade = v[0];
l.push_back(1);
for (int i = 2; i < free_member +1; i++) {
if (free_member%i==0){l.push_back(i);}
}
int pp=  l.size();
for (int i = 0; i < pp; i++) {l.push_back(-l[i]);}

m.push_back(1);
for (int i = 2; i < top_grade +1; i++) {
if (top_grade%i==0){m.push_back(i);}
}

for (int i=0; i<m.size();i++){	
for (int i2=0; i2<l.size();i2++){
double o =  1.0*l[i2]/m[i];
proots.insert(o);
}}

set<double>:: iterator p = proots.begin();
while(p!= proots.end()) {
double proot = *p ;
double h = horner(proot);
if (h>-0.1 && h< 0.1){
string sig="-"; if (proot<0){sig="+";}
double mm =  proot;
if (proot<0) {mm=-mm;} 			
cout<<"(x"<<sig<<mm<<")( "<<show_fun()<<" ) =0 Root: "<<proot<<"\n";}
p++;
}

cout<<"\n\nby OlegTim	";
system("pause");
return 0;
}
