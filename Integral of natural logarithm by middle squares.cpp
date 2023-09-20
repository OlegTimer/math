#include <iostream>
#include <cmath>
using namespace std;

#define D  0.0001

int main(){
double s,f,in,ir;	
cout << "_Integral of natural logarithm by middle squares_\n\n";
cout<<"Enter start of interval (1.0 for double): ";
cin>>s;
cout<<"Enter end of interval: ";
cin>>f;

if (f<=s){
cout<<"Error. Interval end must be more than start.\n";  
system("pause");
return 1; 		  
			 }

for(double i = s+D/2; i<f; i+=D ){
in+=log(i)*D;
ir+=1/log(i)*D;	  
	  }
cout<<"\nIntegral from "<<s<<" to "<<f<<" of natural logarithm is: "<<in;
cout<<"\nIntegral from "<<s<<" to "<<f<<" of 1/(natural_logarithm) is: "<<ir;
cout<<"\n\nby OlegTim	";
system("pause");
return 0;
}
