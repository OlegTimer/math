#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159
#define E  2.71828
 
int main(){
double flaplacerev(double x);	
double p,q,a;
int n;
std::cout<<"Get confidence interval ci for expected value with probability p\n";
std::cout<<"of general totality with normal distribution\n";
std::cout<<"if standard deviation is q; sample mean is a; sample size is n\n";
std::cout<<"( Calculation is with Reverse Laplace Integral Function F(x) )\n\n";
std::cout<<"For example, p=0.95; q=5; a=24.15; n=100;	23.17 < ci < 25.13 \n\n";

std::cout << "\nEnter probability p (for example 0.95): "; 
cin >> p;
std::cout << "Enter standard deviation q (for example 5.0): "; 
cin >> q;
std::cout << "Enter sample mean a (for example 24.15): "; 
cin >> a;
std::cout << "Enter sample size n (for example 100): "; 
cin >> n;

double x=p/2;
if (x<-4 || x>4){
std::cout<<"Error in F(x) value, it must be:	F(x) <= |4|\n"; 
system("pause"); 
return 1;  		 
			}

double sign =1.0;	   
if (x<0){x=-x; sign=-1.0;}

double t = flaplacerev(x)*sign; 
double marg = t*q/(sqrt(n));

std::cout <<"\n"<<a-marg<<" < confidence interval < "<<a+marg; 
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
