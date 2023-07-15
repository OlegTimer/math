#include <iostream>
using namespace std;

int getval(){
char str[20];
int x;
gets(str);
x=atoi(str);
return x;	
	}

int main()
{
int getval(); 	
int t,n,m,k; 	
cout << "Probability of exact num k of n from m random of t \n";
cout << "Pr. of k men in random group of m from total t people with n men";
cout << 	"\n\nEnter total size t: ";
t = getval();
cout << 	"Enter size of sub-group n: ";
n = getval();
cout << 	"Enter size of random select m: ";
m = getval();
cout << "Enter the exact num (of n) k: ";
k= getval();
 int kcomb( int t,  int k);
 double r1 = kcomb(k,n);
 double r2;
 if (k!=m)
 {r2 = kcomb(m-k,t-n);}
 else
 {r2=1;}
 double r3 = kcomb(m,t);
 double r = (r1*r2/r3)*100;
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
