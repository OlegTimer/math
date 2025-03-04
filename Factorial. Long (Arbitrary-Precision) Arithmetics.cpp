#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

#define  PI 3.14159

int main ()
{
cout << "__ Factorial. Long (Arbitrary-Precision) Arithmetics. __\n";
cout << "Enter int (for example, 100) to get factorial of it\n";
int num=0;
cin >> num;
cout << "\nIn the program's directory _output.txt will be created.\n";
if (num<1){cout<<"\nERR_\n";system("pause");return 1;}
if (num==1){cout<<"\n 1!=1 \n";system("pause");return 1;}

int vol = (log(sqrt(2*PI*num))/log(num)+num-num/log(num))/(log(10)/log(num))+1;

int arr [vol];
for (int j =0; j<vol; j++){arr[j]=0;}
arr[vol-1]=1;

for (int i =2; i<num+1; i++){
	int temp = 0;	
	for (int j =vol-1; j>-1; j--){
	int q = (arr[j]*i)+temp;	
	arr[j] =q%10;
	temp = q/10;
	//cout<<i<<" _ "; for(int z =0; z<vol; z++){cout<<arr[z];} cout<<"\n";	
	}
}

cout<<num<<"! = ";
for(int z =0; z<vol; z++){cout<<arr[z];} 

ofstream outw("./_output.txt"); 
if(!outw) {
cout << "Cannot create _output.txt\n";
cout<<"\n"; system("pause");
exit(1);
}
	for (int i = 0; i<vol; i++){
outw<<arr[i];
	}	
outw.close();

cout<<"\n\nby OlegTim\t";  system("pause");
  return 0;
}