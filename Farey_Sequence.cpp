#include <iostream>
#include <vector> 
using namespace std;
int main () {
cout <<"_ John Farey Sequence  _\n";
cout <<"The ascending sequence of all reduced fractions between 0 and 1\n";
cout <<"which have demominators <=n is Farey sequence\n";
cout <<"or Farey series of order n\n";
cout <<"( Whole positive nums are taken only to x and y in x/y )\n";
cout <<"For example, for n=3:\n0/3	1/3	1/2	2/3	3/3";

cout <<"\n\nPlease, type the n (from 2) and press <Enter>\n";
int n = 1;
cin >> n;
if (n<2){n=2;}

cout<<"\n0/1\n1/"<<n<<"\n";

int x=0;
int y=1;
int x1=1;
int y1=n;
int x2=-1;
int y2=1;

while (x2/y2<1){
x2 = ((y+n)/y1)*x1 -x;
y2 = ((y+n)/y1)*y1 -y;
cout<<x2<<"/"<<y2<<"\n";
x=x1;
y=y1;
x1=x2;
y1=y2;
}

cout <<"\n\nby OlegTim\t"; system("pause");
  return 0;
}
