#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159
#define E  2.71828
 
int main(){
double x;	
std::cout << "Enter F(x) ( for example 0.475) of Laplace Integral Function F(x): "; 
cin >> x;

if (x<-4 || x>4){
std::cout<<"Error in F(x) value, it must be:	F(x) <= |4|\n"; 
system("pause"); 
return 1;  		 
			}

double sign =1.0;	   
if (x<0){x=-x; sign=-1.0;}

double flaplacerev(double x);
std::cout <<"\nArgument x is: "<<flaplacerev(x)*sign; 
std::cout<<"\n"; system("pause"); 
    return 0;
}


double flaplacerev(double x){
double delta =   0.01;
double margin =   0.0001;
double res = 0;
double flaplace(double x);
double d;

while (res<4){
d = flaplace(res);	  
if (d-margin<x && d+margin>x){break;}
res+=delta;
}
return res;
	   }

 
double flaplace(double x){
double delta =   0.0001;
double res = 0;
for (double i = 0; i < x; i+=delta){        
res += delta*fabs(pow(E,-0.5*pow(i,2))+pow(E,-0.5*pow((i+delta),2)))/2;   
}
res =  res/sqrt(2*PI);
return res;
}
