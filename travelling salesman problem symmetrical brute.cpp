#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<vector<int> >  matrix1;	
vector<int>  coeff;
vector<int>  coeffway;
int minim  = 2147483647;


int getdist(){
int z =0;
for (int i = 0; i < coeff.size()-1; i++) {
int a = coeff[i];
int b = coeff[i+1];
if (a>b){a=coeff[i+1]; b=coeff[i];}
if (matrix1[a][b]==0){z=0;break;}
z+=matrix1[a][b];
}
if (z!=0){ //if path exist check the return way to start
int a = coeff[coeff.size()-1];
int b = coeff[0];
if (a>b){a=coeff[0]; b=coeff[coeff.size()-1];}
if (matrix1[a][b]==0){z=0;}
z+=matrix1[a][b];
}
return z;	
}


int checkzero(){ //zero  makes while false
int z=0;	
for (int i = 0; i < coeff.size(); i++) {z+=coeff[i];}
return z;	
}


int checkdouble(){ //visit city once
		int z =0;
for (int i = 0; i < coeff.size(); i++) {
	if (z==1){break;}
	for (int i2 = 0; i2 < coeff.size(); i2++) {
			if (i==i2){ continue;}
			if (coeff[i]==coeff[i2]){z=1;break;}
		}
	}
	return z;	
}


void decrease(){ //decrease the cities number order
for (int i = coeff.size()-1; i >-1; i--) {
if (coeff[i]>0){//
coeff[i]--; 
for (int j = i; j < coeff.size(); j++) {if (i<coeff.size()-1){coeff[j+1]= coeff.size()-1;} }
break;
}//
	}
	
}


void brute(){
int dist = minim;	
while (checkzero()){	
decrease();
while(checkdouble() && checkzero()){decrease();}
dist = getdist();
// for (int i = 0; i < coeff.size(); i++) {cout<<coeff[i]<<"-";}	cout<<" _ "<<dist<<"\n";	
if (dist>0 && dist<minim){
		for (int i = 0; i < coeff.size(); i++) {coeffway[i]=coeff[i];}
		minim=dist;
		}
	}
}


int main ()
{
cout << "__ Travelling Salesman Problem Symmetrical Brute-Force __\n";
cout << "(with return) \nFill _matrixin1.txt  in the program's directory.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n";
cout<<"Say, for 2 cities (positive distance between is 5):\n";
cout<<"\tCity0\tCity1\n";
cout<<"City0\t0\t5\n"; //map is mirror-like, it's simplier to write half
cout<<"City1\t0\t0\n";
cout<<"Input must be:\n";
cout<<"0\t5\n";
cout<<"0\t0\n\n";
 	
vector<string> arr;
string str ("");
   
ifstream file("./_matrixin1.txt");
if(!file) {
cout << "Cannot open file _matrixin1.txt. Trying to create new\n";
ofstream out3("_matrixin1.txt"); 
if(!out3) {
cout << "Cannot create _matrixin1.txt\n";
return 1;
}
out3 << "";
out3.close();
cout<<"\n"; system("pause");
return 1;
} 
 
if (file.is_open()) {  					
    std::string line;
    while (std::getline(file, line)) {
arr.clear();		  
    str = line.c_str();
  string delim("\t");
  size_t prev = 0;
  size_t next;
  size_t delta = delim.length();
  while( ( next = str.find( delim, prev ) ) != string::npos ){
    arr.push_back( str.substr( prev, next-prev ) );
    prev = next + delta;
  }
 arr.push_back( str.substr(prev ) ); 
vector<int> v;
for (int i = 0; i < arr.size(); i++) {
int d = atoi(arr[i].c_str());
v.push_back(d);
}
 matrix1.push_back(v);   
    }
    file.close();
}	

if(matrix1.size()<1){cout<<"ERR_empty entry\n";system("pause");return 1;} 
if(matrix1.size()<2){cout<<"ERR_at least 2 cities\n";system("pause");return 1;} 	
if(matrix1.size()!=matrix1[0].size()){cout<<"entry not square\n";system("pause");return 1;}

for (int i = 0; i < matrix1.size(); i++) {
coeff.push_back(matrix1.size()-1); 
coeffway.push_back(0); 
}
 
cout<<"Input:\n"; 
for (int i = 0; i < matrix1.size(); i++) {
	for (int i2 = 0; i2 < matrix1[i].size(); i2++) {
cout<<matrix1[i][i2]<<"\t";
	}
	cout<<"\n";
} 
cout<<"\n";

brute();
if (coeffway[0]==0 && coeffway[1]==0){cout<<"no_way_found\n";system("pause");return 1;}
cout<<"Min_distance is: "<<minim<<"\nWay through (cities num start from 0):\n";
for (int i = 0; i < coeffway.size(); i++) {cout<<coeffway[i]<<"-";}	cout<<coeffway[0]<<"\n";

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}