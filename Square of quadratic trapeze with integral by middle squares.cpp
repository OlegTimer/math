#include <iostream>
#include <cmath>
using namespace std;

#define D  0.001

int main(){
double a,b,c,s,f;
long double in;	
cout << "_Square of quadratic trapeze with integral by middle squares_\n\n";
cout << "For example, trapeze is defined with y=x^2+2; OX (y=0); x=-2; x=1;  S=9";
cout<<"\nIt is assumed all figure is above OX and lines are continual.";

cout<<"\n\n(1.0 for double)\nEnter a (of ax^2+bx+c): ";
cin>>a;
cout<<"Enter b (of ax^2+bx+c): ";
cin>>b;
cout<<"Enter c (of ax^2+bx+c): ";
cin>>c;
cout<<"Enter vertical separating line value (x=?): ";
cin>>s;
cout<<"Enter another vertical separating line value (x=?): ";
cin>>f;

if (f==s){
cout<<"Error. Interval must be non-zero\n";  
system("pause");
return 1; 		  
			 }
			 
if (s>f){
double t = s;
s=f;
f=t;   		 
			}
						 

for(double i = s+D/2; i<f; i+=D ){
in+=(a*i*i + b*i +c)*D;
	  }
	  
cout<<"\n\nTrapeze is defined with "<<a<<"x^2 + ("<<b<<")x + ("<<c<<"); y=0; ";
cout<<"x="<<s<<"; x="<<f<<";\n";
cout<<"Square (integral) is: "<<in;
cout<<"\n\nby OlegTim	";
system("pause");
return 0;
}
