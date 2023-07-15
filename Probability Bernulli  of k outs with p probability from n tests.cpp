#include <iostream>
using namespace std;

int getval(){
char str[20];
int x;
gets(str);
x=atoi(str);
return x;	
	}
	
double getvald(){
char str[20];
double x;
gets(str);
x=atof(str);
if (x>0 && x<1){
return x;
}
else{
return 0.0;	 
	 }	
	}	

int main()
{
int getval(); 	
int n,k;
double p; 	
cout << "Probability Bernulli  of k outs with p probability from n tests\n";
cout << 	"\n\nEnter total num of tests: ";
n = getval();
cout << "Enter the exact num (of n) k: ";
k= getval();
cout << 	"Enter probability of event (0-1, for example 0.5): ";
p = getvald();

 int kcomb( int t,  int k);
 double r1 = kcomb(k,n);
 
double t=p; 
for (int i =1; i<k; i++){
	t=t*p;
	} 

double b=1-p;
for (int i =1; i<n-k; i++){
b=b*(1-p);
	} 

 double r = r1*t*b*100;
cout <<"Probability is: "<<r<<" %\n";
system("pause");
return 0;
}

int kcomb( int k,   int t){
long long int r=1;
long long int fctr(long long int t);
if (k!=t){
   		  r = fctr(t)/(fctr(k)*fctr(t-k));
		  }
int res = (int) r;
return res;	
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
