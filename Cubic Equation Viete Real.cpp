#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159
#define W 999999999
#define M 0.0000001

int signum (long double z){
int r = 1;	
if (z<0){r=-1; }
return r;	
	}

int main(){
long double a, b, c, d, x1,x2, x3;
x1=x2=x3 = W; //start val max double. most likely NOT a root

cout<< "_ Cubic Equation Viete Real _\n\n";
cout<< "dx^3 + ax^2 + bx + c = 0";
cout<<"\n(1.0 for double)";
cout<<"\nFor example:\t5x^3\t-x^2\t-20x\t+4=0 \nEnter:\t\t5\t-1\t-20\t 4";
cout<<"\nRoots: -2;	0.2;	2";
cout<<"\nWarning. Roots may be close. i.e. 0.199996~0.2\t;\t1.85128e-017~0";

cout<<"\n\n\nEnter d (of dx^3 +ax^2 + bx+ c): ";
cin>>d;

if(d==0){
cout<<"\nError! In Cubic Equation d is not zero dx^3 \n";
system("pause");
return 1;		 
		 }

cout<<"Enter a (of dx^3 +ax^2 + bx+ c): ";
cin>>a;
cout<<"Enter b (of dx^3 +ax^2 + bx+ c): ";
cin>>b;
cout<<"Enter c (of dx^3 +ax^2 + bx+ c): ";
cin>>c;

cout<<"\n\n"<<d<<"x^3 ";
if (a>=0){cout<<"+";}
cout<<a<<"x^2 ";
if (b>=0){cout<<"+";}
cout<<b<<"x ";
if (c>=0){cout<<"+";}
cout<<c<<" = 0\n";

a= (double)1.0*a/d;
b= (double)1.0*b/d;
c= (double)1.0*c/d;
d=1.0;

double Q = (a*a-3*b)/9;
double R = (2*a*a*a-9*a*b+27*c)/54;
double S = Q*Q*Q - R*R;
double fi = 0.0;
double fi2 = 0.0;

if (S>M){// if S>0 , 3 roots
double fac = (R/sqrt(Q*Q*Q));
fi = (1.0*acos(fac))/3;

x1=-2*sqrt(Q)*cos(fi) - a/3;
fi2= (double)1.0*2/3*PI;
x2=(double)-2.0*sqrt(Q)*cos(fi+fi2) - a/3;
x3=(double)-2.0*sqrt(Q)*cos(fi-fi2) - a/3;
}
else{
if (S<-M){ //if S<0 , 1 root

if (Q>M){ 
double fac = (double) 1.0*abs(R)/pow(Q,3.0/2);
double fac2=(double) 1.0* log(fac+sqrt((fac*fac-1)));
fi= (double) 1.0*1/3*(fac2);
x1=(double) -2.0*signum(R)*sqrt(Q)*cosh(fi)-a/3;
}
else{
if (Q<-M){ 
double fac = (double) 1.0*abs(R)/pow(abs(Q),3.0/2);
double fac2=(double) 1.0* log(fac+sqrt((fac*fac-1)));
fi= (double) 1.0*1/3*(fac2);
x1=(double) -2.0*signum(R)*sqrt(abs(Q))*cosh(fi)-a/3;
}
else{
x1=(double) -1.0*cbrt(c-(a*a*a/27))-a/3;
}
}

}
else{// if S about 0, 2 roots
x1=(double)-2.0*cbrt(R)-a/3;
x2=(double)1.0*cbrt(R)-a/3;
}}						 

if (x1==x2 || x1==x3){x1=W;}
if (x2==x1 || x2==x3){x2=W;}
if (x3==x1 || x3==x2){x3=W;}

cout<<"Root(s):\n";
if(x1!=W){cout<<x1<<"\n";}
if(x2!=W){cout<<x2<<"\n";}
if(x3!=W){cout<<x3<<"\n";}

cout<<"\n\nby OlegTim	";
system("pause");
return 0;
}
