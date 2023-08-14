#include <iostream>
#include <cmath>
using namespace std;

int main()
{
int n; 		
double p,k,k1,k2;	
cout << "Chebushev Probab. that events num starts from k1 and ends with k2 \n";
cout << "with n events with p probab. each \n\n";
	cout << "For example, n=100 tests, p=0.5 , k1=40, k2=60	  P=0.75 \n\n";

cout << "\nEnter events  num n: ";
cin >> n;
cout << "Enter event probability p (0-1.0): ";
cin >> p;
cout << "Enter events num starts from k1: ";
cin >> k1;
cout << "Enter events num ends with k2: ";
cin >> k2;

double m = n*p;
k = abs(m-k1);
if (abs(m-k2)>k)
{
   				k=abs(m-k2);
				   }

cout <<"Chebushev Probability is: "<<1-(n*p*(1-p))/(k*k)<<"\n";
system("pause");
return 0;
}
