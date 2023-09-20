#include <iostream>
#include <cmath>
using namespace std;

int main(){
double m,f,s,r;	
cout << "_Tsiolkovsky formula_\n\nEnter mass (tons) at start (1.0 for double): ";
cin >> m;
cout << "Enter mass at end: ";
cin >> f;
cout << "Enter specific impulse (i.e. 450 H2-O2; 350 kerosene-O2): ";
cin >> s;
r=(log(m/f))*9.8*s;
cout<<"Delta speed is: "<<r<<" m/s\n\n";
system("pause");
return 0;
}
