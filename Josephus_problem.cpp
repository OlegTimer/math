#include <iostream>
#include <vector> 
using namespace std;
int main () {
cout <<"_ Josephus' problem by OlegTim _\n";
cout <<"Given n people in circle.\n";
cout <<"Every m person is removed. After removal process continues.\n";
cout <<"Which position to take at start to become the last standing? (Count from 1)\n";

cout <<"\n\nPlease, type the number of people (from 2) and press <Enter>\n";
int n = 2;
cin >> n;
if (n<2){n=2;}
cout <<"Type the number of people in removal count and press <Enter>\n";
int m = 1;
cin >> m;
if (m<1||m>=n){m=1;}
cout <<"OK. "<<n<<" people with removal group of "<<m<<"\n";
cout<<"\nIn order:\n";

vector<int> v;
for (int i=1;i<n+1;i++){
v.push_back(i);
	}

int order = 1;
int count =0;
int pos =0;
int t = 0;

while (order<n+1){//
count =0;
while (count<m){
	  if (v[pos]!=0){count++;}
	t=pos;
	  	  pos++; if (pos==v.size()){pos=0;}
	  }
cout<<order<<")\tremoved person at position:\t"<<v[t]<<"\n";
order++;
v[t]=0;
}//  
cout <<"\n\n"; system("pause");
  return 0;
}
