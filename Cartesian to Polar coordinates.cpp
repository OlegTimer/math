#include <iostream>
#include <cmath>
#define PI 3.14159265359
int main() {
	std::cout << "_ Cartesian to Polar coordinates _\n";
	double x,y;
	std::cout << "Enter x coord (point for fractional num):\n";
	std::cin >> x;
	std::cout << "Enter y coord (point for fractional num):\n";
	std::cin >> y;
	
	double r = sqrt(x*x+y*y);
	double f = atan2(y,x);
	std::cout <<"\nCartsesian: x="<<x<<" y="<<y<<"\n";
std::cout<<"Polar:r="<<r<<"\nf="<<f<<" rad OR "<<f/PI<<" Pi OR "<<f*180/PI<<" degrees\n";
    system("pause");
    return 0;
}