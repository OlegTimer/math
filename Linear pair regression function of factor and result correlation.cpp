#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
vector<vector<double> >  vec; 
vector<string> arr;
string str ("");
string delim("\t");   
	 	
ifstream file("_input.txt");

cout<<"Linear pair regression function of factor and result correlation\n-\n";
cout<<"Enter 2 columns tab-separated (1.0 for doubles) \n";
cout<<"to _input.txt in program's directory\nFactor	Result\n\n";

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
v.push_back(d);
}
vec.push_back(v);   
    }
    file.close();
}


if (vec.size()<1){
cout<<"\nSeems _input.txt is empty. Fill it, please\n";   				  
system("pause");
return 1;    				  
}

sort (vec.begin(), vec.end());   

double x,y,x2,y2,xy;
x=y=x2=y2=xy=0.0;
for (int i = 0; i<vec.size(); i++){
x+=vec[i][0];
y+=vec[i][1];
x2+=vec[i][0]*vec[i][0];
y2+=vec[i][1]*vec[i][1];
xy+=vec[i][0]*vec[i][1];
}

double a = (vec.size()*xy - y*x)/(vec.size()*x2-x*x);
double b =(y-a*x)/vec.size();

cout<<"\nf(x)= "<<a<<"x";
if (b>0){cout<<"+";}
cout<<b<<"\n";

double r = (xy/vec.size() - (x/vec.size()*y/vec.size()));
double r2=(sqrt(x2/vec.size()-(x/vec.size()*x/vec.size())));
double r3=(sqrt(y2/vec.size()-(y/vec.size()*y/vec.size())));
r=r/(r2*r3);
cout<<"\nPearson's selection linear coefficient of pair correlation r is: "<<r;
cout<<"\nIf r<0, correlation is reverse; the closer to |1|, the stronger corr.";
cout<<"\n\nCoefficient of determination is: "<<r*r*100<<" %\n";
cout<<"\nIn case increasing factor by 1% the result changes as\n";
cout<<"coefficient of elastics, it is: "<<a*(x/vec.size())/(y/vec.size())<<" %\n";
cout<<"\nFactor deviation is: "<<r2<<" Result deviation is: "<<r3<<"\n";
cout<<"In case increasing factor by 1 deviation the result changes as\n";
cout<<"beta-coefficient, which is: "<<a*r2/r3<<" deviation\n";

cout<<"\n\nby OlegTim. ";
system("pause");
return 0;
}
