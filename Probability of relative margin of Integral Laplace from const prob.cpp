#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159
#define E  2.71828	

int main()
{	
int n,k;
double p,q,d; 	
cout << "Probability of relative margin of Integral Laplace from const prob. \n\
is not more than delta d with p prob. from n independent tests\n";
cout << 	"\n\nEnter total num of tests: ";
cin >> n;
cout << 	"Enter probability of event (0-1, for example 0.8): ";
cin >> p;
cout << 	"Enter delta d( for example 0.04): ";
cin >> d;
q=1-p;

 double x = d*sqrt((n/(p*q)));
double flaplace(double x);
double r =200*flaplace(x);

cout <<"Margin is: "<<r<<" %\n";
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
