#include <iostream>
#include <cmath>
using namespace std;

int main()
{
int n; 		
double p,k;	
cout << "Chebushev Probab. that absolute difference between events and Math expectation\n";
cout << "is less, than k with n events with p probab. each\n\n";
	cout << "For example, n=10 tests, p=0.05 , k=2 ( abs. diff.<2 ).	  P=0.88 \n\n";

cout << "\nEnter events  num n: ";
cin >> n;
cout << "Enter event probability p (0-1.0): ";
cin >> p;
cout << "Enter abs. diff. between events and Math expect.  is less, than k: ";
cin >> k;

cout <<"Chebushev Probability is: "<<1-(n*p*(1-p))/(k*k)<<"\n";
system("pause");
return 0;
}
