#include <iostream>
#include <cmath>
using namespace std;

#define E  2.71828

int main()
{	
int k;
double t,h;
	
cout << "__ Puanson flow probability of flow h of k events during t time __\n";
cout << "For example, flow h is 3 events per sec, k 4 events, time t is 2 sec\n";
cout << "What's is probability? ~ 13%\n";
cout << "\n\nEnter flow stream h (events per time): ";
cin >> h;
cout << "Enter the exact num of evets k: ";
cin >> k;
cout << "Enter time of flow t: ";
cin >> t;

long long int fctr(long long int t);
double ht = h*t;
double r =100*((pow(ht,k)*pow(E,-ht))/fctr(k));

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
