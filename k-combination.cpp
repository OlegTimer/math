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
int t,k; 	
cout << "(k-combination)	Enter total size t: ";
t = getval();
cout << "Enter k of t: ";
k= getval();
long long int kcomb(int t, int k);
long long int r = kcomb(t,k);
printf ("Number k of t is: %d \n", r);
system("pause");
return 0;
}

long long int kcomb(int t, int k){
long long int r=1;
long long int fctr(long long int t);
if (k!=t){
r = fctr(t)/(fctr(k)*fctr(t-k));
}
return r;	
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
