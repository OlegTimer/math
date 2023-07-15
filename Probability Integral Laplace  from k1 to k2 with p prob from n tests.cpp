#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159
#define E  2.71828

int getval(){
char str[20];
int x;
gets(str);
x=atoi(str);
return x;	
	}
	
double getvald(){
char str[20];
double x;
gets(str);
x=atof(str);
if (x>0 && x<1){
return x;
}
else{
return 0.0;	 
	 }	
	}	

int main()
{
int getval(); 	
int n,k1,k2;
double p,q; 	
cout << "Probability Integral Laplace  from k1 to k2 with p prob. from n tests\n";
cout << 	"\n\nEnter total num of tests: ";
n = getval();
cout << "Enter num of event happens not less, than k1: ";
k1= getval();
cout << "Enter num of event happens not more, than k2: ";
k2= getval();
cout << 	"Enter probability of event (0-1, for example 0.5): ";
p = getvald();
q=1-p;

double sq_npq = sqrt(n*p*q);
double x1 = (k1-n*p)/sq_npq;
double x2 = (k2-n*p)/sq_npq;
double flaplace(double x);
double r =flaplace(x2)-flaplace(x1);
r=r*100;

cout <<"Probability is: "<<r<<" %\n";
system("pause");
return 0;
}


double flaplace(double x){
double sign =1.0;	   
if (x<0){x=-x; sign=-1.0;}	   
double delta =   0.0001;
double res = 0;
for (double i = 0; i < x; i+=delta){        
res += delta*fabs(pow(E,-0.5*pow(i,2))+pow(E,-0.5*pow((i+delta),2)))/2;   
}
res =  res/sqrt(2*PI);
return res*sign;
}
