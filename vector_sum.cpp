#include <iostream>
int main() {
std::cout << "_ Sum vectors knowing their dots coord in 3D _\n";
int x,y,z,x2,y2,z2;
std::cout << "Enter x of first vector: \n";
std::cin >> x;
std::cout << "Enter y of first vector: \n";
std::cin >> y;
std::cout << "Enter z of first vector: \n";
std::cin >> z;
std::cout << "Enter x of second vector: \n";
std::cin >> x2;
std::cout << "Enter y of second vector: \n";
std::cin >> y2;
std::cout << "Enter z of second vector: \n";
std::cin >> z2;
std::cout << "\nSum of vector("<<x<<", " <<y<<", "<<z<<") and vector ("<<x2<<", "<<y2<<", "<<z2<<") is: \n";
std::cout <<"("<<(x+x2)<<", "<<(y+y2)<<", "<<(z+z2)<<")\n";
system("pause");
return 0;
}