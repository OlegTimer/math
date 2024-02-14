#include <cmath>
#include <iostream>
using namespace std;
#define PI 3.14159
#define E  2.71828
int main(){
double f=0.0;
double n = 0.0;
cout<<"_ Factorial_approximation_by_Sterling _\n";
cout<<"Enter an argument (say, 5.0) to get factorial (120 for 5):\n";
cin>>n;
f=  n*log(n) - n*log(E) + log( sqrt(2*PI*n) );
f= pow(E, f);
cout<<f;
cout<<"\nby_OlegTim\t"; system("pause");
return 0;
}
