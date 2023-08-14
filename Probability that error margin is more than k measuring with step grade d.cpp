#include <iostream>
using namespace std;

int main()
{
double d,k; 		
cout << "__ Probability that error margin is more than k measuring with step grade d __\n\n";
cout << "For example, what is the probability P that  \n";
cout << "error margin k is more than 0.02 if step grade d is 0.1 ?	P = 0.6 \n\n";
cout << "Enter error margin k: ";
cin >> k;
cout << "Enter step grade d: ";
cin >> d;

double f = 1/d;
double a = k;
double b = d-k;
double r=f*b-f*a;
cout << "Probability is: "<<r<<"\n";
system("pause");
return 0;
}
