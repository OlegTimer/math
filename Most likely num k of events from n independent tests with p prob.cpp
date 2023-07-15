#include <iostream>
#include <cmath>
using namespace std;

#define D 0.0001

int main()
{	
int n;
double p,q,k1,k2;
k1=k2=-1;	
cout << "Most likely num k of events from n independent tests with p prob.";
cout << 	"\n\nEnter total num of tests: ";
cin >> n;
cout << 	"Enter probability of event (0-1, for example 0.8): ";
cin >> p;
q=1-p;

double l = n*p-q;
double r = n*p+p;

if (abs(n*p-ceil(n*p))<D){
k1= ceil(n*p);
							} else {
k1=ceil(l);							  	   
									 }
									 
if (abs(l-ceil(l))<D){k2=k1+1; }									 									 

if (k1>= l-D && k1<r+D){}else{k1=-1;}
if (k2>= l-D && k2<r+D){}else{k2=-1;}

if (k1!=-1){
   			cout <<"Most likely num k of events is: "<<k1;
			   }
else{
	 cout<<"Err";
	 }
if (k2!=-1){cout<<"\t"<<k2;}
cout<<"\n";
system("pause");
return 0;
}
