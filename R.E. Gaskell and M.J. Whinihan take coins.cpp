#include <iostream>
using namespace std;
int main () {
cout <<"Code by OlegTim of task by R.E. Gaskell & M.J. Whinihan at\n";
cout <<"D. Knuth's The Art of Computer Programming. Vol. 1. p. 124(el) (85?print)\n-\n";
cout <<"Given n coins. The winner is who takes the last pack.\n";
cout <<"First player takes some coins (not all and at least 1).\n";
cout <<"After that players can take 2X or less of that opponent took on previous turn\n";

cout <<"\n\nPlease, type the number of coins (from 2) and press <Enter>\n";
int num = 2;
int input = 1;
int prev=1;
cin >> num;
if (num<2){num=2;}
cout <<"Good! Total number of coins is: "<<num<<"\n";

cout <<"Type the number of coins you take and press <Enter>\n";
cin >> input;
if (input<1 || input>=num){input=1;}
prev = input;
num=num-input;


while (num>0){
cout <<"\nTotal number of coins is: "<<num<<"\n";	  
if (prev*2 >=num)
{
cout <<"Computer takes: "<<num<<" and wins.\n";
num = 0; 
break;  		   
   		   }else{
if (num%3==0){input=num/3 -1;} else{input=num/3;}
if (input>2*prev){input=2*prev; } 
if (input<1 ){input=1; } 
num-=input;
prev=input;
cout <<"Computer takes: "<<input<<"\n";
cout <<"Total number of coins is: "<<num<<"\n";	
		   		 }
cout <<"Type the number of coins you take and press <Enter>\n";
cin >> input;
if (input<1 || input>prev*2){input=1; cout <<"err!\n";} 
prev=input;
num-=input;
cout <<"You take: "<<input<<"\n";
if (num<1){cout <<"You WON!\n";}
}

  
cout <<"\n"; system("pause");
  return 0;
}
