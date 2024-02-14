#include <cmath>
#include <iostream>
using namespace std;
#define PI 3.14159
#define E  2.71828
double fctr (double n){
double f=0.0;
f=  n*log(n) - n*log(E) + log( sqrt(2*PI*n) );
f= pow(E, f);
return f;
}
int main(){
double a=0.0;
double t,k; 
cout<<"_ k-combination w factorial_approximation_by_Sterling _\n";	
cout << "Enter total size t: ";
cin>>t;
cout << "Enter k of t: ";
cin>>k;
a = fctr(t)/(fctr(k)*fctr(t-k));
cout<<"Number k of t is about: "<<a;
cout<<"\nby_OlegTim\t"; system("pause");
return 0;
}
