#include <iostream>
using namespace std;

int main()
{	
double t,t1,t2; 	
cout << "__ Probability in geometry crossing with duration t with random starts __\n\n";
cout << "For example, t=90; t1=10; t2=15; Prob. they will cross (meet) is 26%\n";
cout << "\n\nEnter total duration t: ";
cin >>t;
cout << "Enter first part duration t1: ";
cin >>t1;
cout << "Enter second part duration t2: ";
cin >>t2;

double r = t*t - 0.5*(t-t1)*(t-t2) - 0.5*(t-t2)*(t-t1) ;
cout<<"\nProbability that they will cross is: "<<r/(t*t)*100<<" %\n";
system("pause");
return 0;
}
	
