#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
int n;
double p;
	
cout << "__ Dispersion of k independent events with p probability __\n";
cout << "\n\nEnter total number of events: ";
cin >> n;
cout << "Enter event probability p (0-1.0): ";
cin >> p;

cout <<"Dispersion is: "<<n*p*(1-p)<<"\n";
system("pause");
return 0;
}
