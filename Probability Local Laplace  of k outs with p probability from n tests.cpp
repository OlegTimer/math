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
int n,k;
double p,q; 	
cout << "Probability Local Laplace of k outs with p probability from n tests\n";
cout << 	"\n\nEnter total num of tests: ";
n = getval();
cout << "Enter the exact num (of n) k: ";
k= getval();
cout << 	"Enter probability of event (0-1, for example 0.5): ";
p = getvald();
q=1-p;

double sq_npq = sqrt(n*p*q);
double x = (k-n*p)/sq_npq;
double xn = -x*x/2;
double f = 1/sqrt(2*PI)*pow(E, xn);
double r =1/sq_npq*f*100;

cout <<"Probability is: "<<r<<" %\n";
system("pause");
return 0;
}

