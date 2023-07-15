#include <iostream>
#include <cmath>
using namespace std;

#define E  2.71828

int main()
{	
int n,k;
double p,q,;
	
cout << "Puanson probability from big num n tests of k events with small p prob.";
cout << 	"\n\nEnter total num of tests (for example 10000): ";
cin >> n;
cout << "Enter the exact num of evets k: ";
cin >> k;
cout << 	"Enter probability of event (0-1, for example 0.001): ";
cin >> p;
q=1-p;

long long int fctr(long long int t);
double np = n*p;
double r =100*((pow(np,k)*pow(E,-np))/fctr(k));

cout <<"Puanson probability: "<<r<<" %\n";
cout<<"\n";
system("pause");
return 0;
}

long long int fctr(long long int t){
long long int r=-1;
if (t==0){r=0;}
if (t==1){r=1;}
if (t>1){
r=1;   		 
for (int i=2; i<t+1; i++){
r=r*i;	
		}
	}
return r;	
	}
