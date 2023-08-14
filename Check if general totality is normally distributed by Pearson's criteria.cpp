#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

#define PI 3.14159
#define E  2.71828

int main()
{
vector<double>  vst;
vector<double>  ven;
vector<double>  vav;
vector<double>  vfr; 
double sum = 0.0;
double sumsq = 0.0;
vector<string> arr;
string str ("");
string delim("\t");   
	 	
ifstream file("_input.txt");

cout<<"Check if general totality is normally distributed by Pearson's criteria\n-\n";
cout<<"Enter 3 columns tab-separated (1.0 for doubles)\n";
cout<<"to _input.txt in program's directory\n";
cout<<"Start	End	Freq	( if totality is discreet, start=end )\n";
cout<<"It is estimated intervals duration are equal. \n\n";

if(!file) {
cout<<"_input.txt is absent. Creating new. Fill it, please\n";
ofstream outo("_input.txt"); 
if(!outo) {
cout << "Cannot create _input.txt\n";
return 1;
}
outo <<"";
outo.close();
system("pause");
return 1; 
} 

if (file.is_open()) {  					
    std::string line;
while (std::getline(file, line)) {
arr.clear();		  
    str = line.c_str();
  size_t prev = 0;
  size_t next;
  size_t delta = delim.length();
  while( ( next = str.find( delim, prev ) ) != string::npos ){
    arr.push_back( str.substr( prev, next-prev ) );
    prev = next + delta;
  }
 arr.push_back( str.substr(prev ) ); 
vector<double> v;
for (int i = 0; i < arr.size(); i++) {
double d = atof(arr[i].c_str());
switch (i){
case 0: { vst.push_back(d);  break;  }
case 1: { ven.push_back(d);  break;  }
case 2: { vfr.push_back(d);  break;  }	   
	   }
}  
    }
    file.close();
}


if (vst.size()<1){
cout<<"\nSeems _input.txt is empty. Fill it, please\n";   				  
system("pause");
return 1;    				  
}

double frtotal = 0.0;
for (int i=0; i<vst.size(); i++){
vav.push_back((vst[i]+ven[i])/2);
sum+=vav[i]*vfr[i]; 
sumsq+=vav[i]*vav[i]*vfr[i];
frtotal += vfr[i];
}

double mean = sum/frtotal;
double disp = sumsq/frtotal - mean*mean;
double deviation = sqrt(disp);
double h = vav[1]-vav[0];

vector<double>  z;
vector<double>  f;
vector<double>  n;

for (int i=0; i<vst.size(); i++){
z.push_back((vav[i]-mean)/deviation);
double d = 1/sqrt(2*PI) * pow(E,-0.5*z[i]*z[i]);
f.push_back(d);	
d = h*frtotal/deviation*f[i];
n.push_back(d);	
	}

cout<<"\nStart	End	Mid	Freq	z	f	n\n";
for (int i=0; i<vst.size(); i++){
cout<<vst[i]<<"\t"<<ven[i]<<"\t"<<vav[i]<<"\t"<<vfr[i]<<"\t";
printf("%.3f", z[i]);
printf("\t%.3f", f[i]);	
printf("\t%.2f\n", n[i]);	

	}

cout<<"\nFreq	n	Diff	(fact. and theor. freq united if less 5)\n";
vector<double>  fu;
vector<double>  nu;
double s1,s2;
s1=s2=0.0;
for (int i=0; i<vst.size(); i++){
s1+=vfr[i]; 
s2+=n[i];
if (s1 >4.999 && s2 >4.999){
fu.push_back(s1);
nu.push_back(s2);
s1=s2=0.0;	   	   
		  }	
	}

if (s1 <5 || s2< 5){
fu[fu.size()-1] +=s1;
nu[nu.size()-1] +=s2;    	   
   	   }

sum=0;
for (int i=0; i<fu.size(); i++){ 
cout<<fu[i]<<"\t";
printf("%.2f\t", nu[i]);
double d=(fu[i]-nu[i])*(fu[i]-nu[i])/nu[i];
sum+=d;
cout <<d<<"\n";		
	}

//Critical point X^2 table for level of importance 0.05
double pear[30] = {3.8,6,7.8,9.5,11.1,12.6,14.1,15.5,16.9,18.3,19.7,21,
22.4,23.7,25,26.3,27.6,28.9,30.1,31.4,32.7,33.9,35.2,36.4,37.7,38.9,
40.1,41.3,42.6,43.8} ;

double st = pear[fu.size()-4];
cout<<"\nEmpirical X^2 point is: "<<sum;
cout<<"\nWith level of importance 0.05 with "<< fu.size()-3;
cout<<" degrees of freedom \ncritical point of theoretical X^2 is: "<<st;
cout<<"\nBy Pearson's criteria, because empirical X^2 ";

if (sum>st){
cout<<"> theoretical X^2 \ngeneral totality is NOT normally distributed.";   			
   			}
else{
cout<<"< theoretical X^2 \ngeneral totality is normally distributed.";	 
	 }

cout<<"\n\n\nYou can find theor. critical point X^2 table for another level of importance";
cout<<"\nby OlegTim. ";
system("pause");
return 0;
}
