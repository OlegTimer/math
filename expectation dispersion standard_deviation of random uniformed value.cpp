#include <iostream>
#include <cmath>
using namespace std;

int main()
{
double a,b; 		
cout << "__ Mathematical expectation, dispersion, standard sq. deviation \n\
of random value uniformly distributed over interval __\n\n";

cout << "Enter start of interval: ";
cin >> a;
cout << "Enter end of interval: ";
cin >> b;

if (b<a)	{
cout << "\n Error in interval borders "<<"\n"; 
system("pause");
exit(0);  		 
			}

cout << "\nMathematical expectation is: "<<(a+b)/2<<"\n";
double d = ((b-a)*(b-a))/12;
cout << "Dispersion is: "<<d<<"\n";
cout << "Standard square deviation is: "<<sqrt(d)<<"\n";
system("pause");
return 0;
}
