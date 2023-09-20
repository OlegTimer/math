#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main ()
{ 	
vector<vector<double> >  matrix1;	
vector<string> arr;
string str ("");
string delim("\t");


cout << "__ Matrix determinant for 2*2 and 3*3 by OlegTim __\n";
cout << "Fill _matrixin1.txt  in the program's directory.\n";
cout << "If absent, program will create new.\n";
cout << "Columns are tab-separated. \n";
cout << "Make sure columns num of matrix1 are 2*2 or 3*3\n\n";

   
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
} 
 
if (file.is_open()) {  					
    std::string line;
    while (std::getline(file, line)) {
arr.clear();		  
    str = line.c_str();
  size_t prev = 0;
  size_t next;
  size_t delta = delim.length();
  while( ( next = str.find( delim, prev ) ) != string::npos ){
    arr.push_back( str.substr( prev, next-prev ) );
    prev = next + delta;
  }
 arr.push_back( str.substr(prev ) ); 
vector<double> v;
for (int i = 0; i < arr.size(); i++) {
double d = atof(arr[i].c_str());
v.push_back(d);
}
 matrix1.push_back(v);   
    }
    file.close();
}

   					
	cout<<"Matrix 1: \n"; 
for (int i = 0; i < matrix1.size(); i++) {
	for (int i2 = 0; i2 < matrix1[i].size(); i2++) {
cout<<matrix1[i][i2]<<"\t";
	}
	cout<<"\n";
}


if (matrix1.size()<1 ) {
cout<<"\n! matrixin1.txt 1  seems empty. Fill and run again\n";
   				 system("pause"); 
					return 1;
   					}

if (matrix1[0].size()== 2 || matrix1[0].size()== 3) {
   					}   					
else{
cout<<"\n! Columns num of matrix1 is not 2 or 3.\nFill and run again\n";
   				 system("pause"); 
					return 1;	 
	 }

if (matrix1.size()== 2 || matrix1.size()== 3) {
   					}   					
else{
cout<<"\n! Rows num of matrix1 is not 2 or 3.\nFill and run again\n";
   				 system("pause"); 
					return 1;	 
	 }

double n = -999999999;
if (matrix1.size()== 2 || matrix1[0].size()== 2) {
n=matrix1[0][0]*matrix1[1][1]   - matrix1[0][1]*matrix1[1][0];				 
   					} 
//
if (matrix1.size()== 3 || matrix1[0].size()== 3) {
n=matrix1[0][0]*matrix1[1][1]*matrix1[2][2] +
matrix1[2][0]*matrix1[0][1]*matrix1[1][2] +
matrix1[1][0]*matrix1[2][1]*matrix1[0][2] -
matrix1[2][0]*matrix1[1][1]*matrix1[0][2] -
matrix1[0][0]*matrix1[2][1]*matrix1[1][2] -
matrix1[1][0]*matrix1[0][1]*matrix1[2][2] ;
}					    


if (n==-999999999){
cout<<"\n! Matrix must be 2*2 or 3*3.\nFill and run again\n";
   				 system("pause"); 
					return 1;   				   
   				   }

cout<<"\nDeterminant is: "<<n;


   					
cout<<"\n";  system("pause");
  return 0;
}
