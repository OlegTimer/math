#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
double p;	
cout << "__ Make  independent tests with p probability each until event happens__\n";
cout << "Math expectation? Dispersion? (algorithm by Gmurman) \n\n";
cout << "Enter event probability p (0-1.0): ";
cin >> p;

cout <<"Math expectation is: "<<1/p<<"\n";
cout <<"Dispersion is: "<<(1-p)/(p*p)<<"\n";
system("pause");
return 0;
}
