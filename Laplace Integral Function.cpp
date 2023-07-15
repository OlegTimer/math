#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159
#define E  2.71828
 
int main(){
double x;	
double flaplace(double);
std::cout << "Enter x ( for example 2.5) of Laplace Integral Function F(x): "; 
cin >> x;
std::cout << flaplace(x); 
std::cout<<"\n"; system("pause"); 
    return 0;
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
