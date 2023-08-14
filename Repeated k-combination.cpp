#include <iostream>
using namespace std;

int main()
{	
int t,k; 	
cout << "__ Repeated k-combination __\n\n";
cout << "For example, how many ways to take 5 elements from 3 of a kind?	21\n";
cout << "5 of first kind; 1 of 1 & 4 of 2... etc \n\nEnter group types number t: ";
cin >>t;
cout << "Enter selected group size k: ";
cin >>k;
long long int fctr(long long int t);
double r = fctr(t+k-1)/(fctr(t-1)*fctr(k));
cout<<"Repeated k-combination is: "<<r<<"\n";
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
