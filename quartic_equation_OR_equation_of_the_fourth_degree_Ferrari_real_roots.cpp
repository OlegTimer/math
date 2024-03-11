#include <iostream>
#include <cmath>
#include <vector> 
#include <sstream>
#include <cstdlib>
using namespace std;

#define PI 3.14159
#define M 0.0001

int signum (double z){
int r = 0;	
if (z<-M){r=-1; }
if (z>M){r=1; }
return r;	
	}


string square(double a, double b, double c){
string answ = "";
double d = b*b - 4*a*c;
if (d>-0.1 && d<0) {d=-d;}
if (d<0) {answ = "no_real_roots";}else{
double x1 = (-b +sqrt(d))/2*a;
double x2 = (-b -sqrt(d))/2*a;
if (x1==x2){
    string text;
	std::ostringstream strs;
	strs << x1;
 	text = strs.str(); 
	answ=text;
   			}
else{
	 string text;
	std::ostringstream strs;
	strs << x1;
 	text = strs.str(); 
	answ=text +"\t";
 	strs.str("");
	strs << x2;
	text = strs.str(); 
	answ+=text;
	 }
}
return answ;
}


string cubic(double d, double a, double b, double c){//Viete  !! d is x^3 coeff
string answ = "";
double x1,x2, x3;
vector <double> v;

if (d!=1.0){
a= (double)1.0*a/d;
b= (double)1.0*b/d;
c= (double)1.0*c/d;
d=1.0;
}

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
v.push_back(x1); v.push_back(x2); v.push_back(x3); 
}
else{
if (S<-M){ //if S<0 , 1 root

if (Q>M){ 
double fac = (double) 1.0*abs(R)/pow(Q,1.5);
double fac2=(double) 1.0* log(fac+sqrt((fac*fac-1)));
fi= (double) 1.0*1/3*(fac2);
if (fi!=fi) {fi=0;}
x1=(double) -2.0*signum(R)*sqrt(Q)*sinh(fi)-a/3;
v.push_back(x1);
}
else{
if (Q<-M){  		     		    		     		   		   
double fac = (double) 1.0*abs(R)/pow(abs(Q),1.5); 
double fac2=(double) 1.0* log(fac+sqrt((fac*fac-1)));
fi= (double) 1.0*1/3*(fac2);
if (fi!=fi) {fi=0;}
x1=(double) -2.0*signum(R)*sqrt(abs(Q))*sinh(fi)-a/3;
v.push_back(x1);
}
else{
x1=(double) -1.0*cbrt(c-(a*a*a/27))-a/3;
v.push_back(x1);
}
}

}
else{// if S about 0, 2 roots
x1=(double)-2.0*cbrt(R)-a/3;
x2=(double)1.0*cbrt(R)-a/3;
v.push_back(x1); v.push_back(x2);
}}

vector <double> v2; //get unique vals in vector v
for (int i=0; i<v.size();i++){v2.push_back(v[i]);}
v.clear();
for (int i=0; i<v2.size();i++){
int err=0;	
for (int i2=0; i2<v.size();i2++){ if ( v2[i]==v[i2]){err++; break;} }	
if (err==0){v.push_back(v2[i]);}
	}

for (int i=0; i<v.size();i++){
	string text;
	std::ostringstream strs;
	strs << v[i];
 	text = strs.str(); 
	answ+=text;
	if (i!=v.size()-1){answ+="\t";}
	}
return answ;
}


string quartic(double k, double a, double b, double c, double d){
string answ = "";
if (k!=1.0){
a= (double)1.0*a/k;
b= (double)1.0*b/k;
c= (double)1.0*c/k;
d= (double)1.0*d/k;
k=1.0;
}

double p = b - 3*a*a/8;
double q = a*a*a/8 - a*b/2 +c;
double r = -3*a*a*a*a/256 +a*a*b/16 -c*a/4 +d;

double k1 = -p/2;
double k2 = -r;
double k3 = r*p/2-q*q/8;

string cubic_answ = cubic(1, k1, k2, k3);

vector<string> arr;
  string str = cubic_answ;
  string delim("\t");
  size_t prev = 0;
  size_t next;
  size_t delta = delim.length();
  while( ( next = str.find( delim, prev ) ) != string::npos ){
    arr.push_back( str.substr( prev, next-prev ) );
    prev = next + delta;
  }
arr.push_back( str.substr(prev ) );

vector<double> cubic_answ_arr;
for (int i = 0; i < arr.size(); i++) {
	cubic_answ_arr.push_back( atof(arr[i].c_str()) );}	

double s = cubic_answ_arr[0];
if (2*s-p>0){}else{ s = cubic_answ_arr[1]; if (2*s-p>0){}
else{s = cubic_answ_arr[2];} }

double sq = sqrt((2*s-p));
string fromsq  = square(1, -sq,  q/(2*sq)+s );
string fromsq2 = square(1, sq, -q/(2*sq)+s );

if (fromsq!="no_real_roots" && fromsq2!="no_real_roots") {
answ= fromsq+"\t"+fromsq2;
   							}
   							else{
if (fromsq!="no_real_roots")  {answ= fromsq;}
if (fromsq2!="no_real_roots") {answ= fromsq2;}
   							  }

if (answ!=""){
arr.clear();
   str = answ;
  string delim("\t");
  size_t prev = 0;
  size_t next;
  size_t delta = delim.length();
  while( ( next = str.find( delim, prev ) ) != string::npos ){
    arr.push_back( str.substr( prev, next-prev ) );
    prev = next + delta;
  }
arr.push_back( str.substr(prev ) );
answ="";

vector<double> v;
for (int i = 0; i < arr.size(); i++) {
	v.push_back( atof(arr[i].c_str()) );}
	
vector <double> v2; //get unique vals in vector v
for (int i=0; i<v.size();i++){v2.push_back(v[i]);}
v.clear();
for (int i=0; i<v2.size();i++){
int err=0;	
for (int i2=0; i2<v.size();i2++){ if ( v2[i]==v[i2]){err++; break;} }	
if (err==0){v.push_back(v2[i]);}
	}

for (int i=0; i<v.size();i++){
	string text;
	std::ostringstream strs;
	strs << (v[i] - a/4);
 	text = strs.str(); 
	answ+=text;
	if (i!=v.size()-1){answ+="\t";}
	}
	
}else{answ="no_real_roots";}

return answ;	   
}


int main(){	
double k, a, b, c, d;
cout<<"_ Quartic equation OR equation of the fourth degree Ferrari Real roots_";
cout<< "\n\nkx^4 + ax^3 + bx^2 + cx + d = 0";
cout<<"\n(1.0 for double)";
cout<<"\nFor example:\t3x^4 + \t6x^3\t-123x^2\t-126x\t+1080 = 0";
cout<<"\nEnter:\t\t3\t6\t-123\t-126\t 1080";
cout<<"\nUnique real roots: -6	-4	3	5";
cout<<"\nWarning. Roots may be close. i.e. 0.199996~0.2\t;\t1.85128e-017~0";

cout<<"\n\n\nEnter k (of kx^4 + ax^3 + bx^2 + cx + d): ";
cin>>k;
if(k==0){
cout<<"\nError! In Quartic Equation k is not zero kx^4 \n";
system("pause");
return 1;		 
		 }
cout<<"Enter a (kx^4 + ax^3 + bx^2 + cx + d): ";
cin>>a;
cout<<"Enter b (kx^4 + ax^3 + bx^2 + cx + d): ";
cin>>b;
cout<<"Enter c (kx^4 + ax^3 + bx^2 + cx + d): ";
cin>>c;
cout<<"Enter d (kx^4 + ax^3 + bx^2 + cx + d): ";
cin>>d;

cout<<"\n\n"<<k<<"x^4 ";
if (a>=0){cout<<"+";}
cout<<a<<"x^3 ";
if (b>=0){cout<<"+";}
cout<<b<<"x^2 ";
if (c>=0){cout<<"+";}
cout<<c<<"x ";
if (d>=0){cout<<"+";}
cout<<d<<" = 0\n";

cout<<"Unique real roots: \n";
cout<<quartic(k,a,b,c,d);

cout<<"\n\nby OlegTim	";
system("pause");
return 0;
}
