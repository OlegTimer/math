#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<vector<double> >  matrix;

double get33(){
double n = matrix[0][0]*matrix[1][1]*matrix[2][2] +
matrix[2][0]*matrix[0][1]*matrix[1][2] +
matrix[1][0]*matrix[2][1]*matrix[0][2] -
matrix[2][0]*matrix[1][1]*matrix[0][2] -
matrix[0][0]*matrix[2][1]*matrix[1][2] -
matrix[1][0]*matrix[0][1]*matrix[2][2] ;
return n;	
}

int main ()
{ 	
vector<vector<double> >  matrix1;	
vector<string> arr;
string str ("");
string delim("\t");

for (int i2 = 0; i2 < 3; i2++) {
vector<double> v2;
for (int i = 0; i < 3; i++) {
v2.push_back(0.0);
}
matrix.push_back(v2); 
}

cout << "__ Matrix determinant for 2*2 and 3*3 and 4*4 by OlegTim __\n";
cout << "Fill _matrixin1.txt  in the program's directory.\n";
cout << "If absent, program will create new.\n";
cout << "Columns are tab-separated. \n";
cout << "Make sure columns num of matrix1 are 2*2 or 3*3 or 4*4\n\n";

   
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

   					
	cout<<"Matrix: \n"; 
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

if (matrix1[0].size()== 2 || matrix1[0].size()== 3 || matrix1[0].size()== 4) {
   					}   					
else{
cout<<"\n! Columns num of matrix1 is not 2 or 3 or 4.\nFill and run again\n";
   				 system("pause"); 
					return 1;	 
	 }

if (matrix1.size()== 2 || matrix1.size()== 3 || matrix1.size()== 4) {
   					}   					
else{
cout<<"\n! Rows num of matrix1 is not 2 or 3 or 4.\nFill and run again\n";
   				 system("pause"); 
					return 1;	 
	 }
	 
	 if (matrix1.size()== matrix1[0].size()) {
   					}   					
else{
cout<<"\n! Rows num of matrix1 is not equal to columns num.\nFill and run again\n";
   				 system("pause"); 
					return 1;	 
	 }

double n = -999999999.0;
if (matrix1.size()== 2 || matrix1[0].size()== 2) {
n=matrix1[0][0]*matrix1[1][1]   - matrix1[0][1]*matrix1[1][0];				 
   					} 

if (matrix1.size()== 3 || matrix1[0].size()== 3) {
matrix[0][0] = matrix1[0][0]; matrix[0][1] = matrix1[0][1]; matrix[0][2] = matrix1[0][2];
matrix[1][0] = matrix1[1][0]; matrix[1][1] = matrix1[1][1]; matrix[1][2] = matrix1[1][2];
matrix[2][0] = matrix1[2][0]; matrix[2][1] = matrix1[2][1]; matrix[2][2] = matrix1[2][2];
 n = get33();
}

if (matrix1.size()== 4 || matrix1[0].size()== 4) {
matrix[0][0] = matrix1[1][1]; matrix[0][1] = matrix1[1][2]; matrix[0][2] = matrix1[1][3];
matrix[1][0] = matrix1[2][1]; matrix[1][1] = matrix1[2][2]; matrix[1][2] = matrix1[2][3];
matrix[2][0] = matrix1[3][1]; matrix[2][1] = matrix1[3][2]; matrix[2][2] = matrix1[3][3];
double a = get33();
matrix[0][0] = matrix1[1][0]; matrix[0][1] = matrix1[1][2]; matrix[0][2] = matrix1[1][3];
matrix[1][0] = matrix1[2][0]; matrix[1][1] = matrix1[2][2]; matrix[1][2] = matrix1[2][3];
matrix[2][0] = matrix1[3][0]; matrix[2][1] = matrix1[3][2]; matrix[2][2] = matrix1[3][3];
double b = get33();
matrix[0][0] = matrix1[1][0]; matrix[0][1] = matrix1[1][1]; matrix[0][2] = matrix1[1][3];
matrix[1][0] = matrix1[2][0]; matrix[1][1] = matrix1[2][1]; matrix[1][2] = matrix1[2][3];
matrix[2][0] = matrix1[3][0]; matrix[2][1] = matrix1[3][1]; matrix[2][2] = matrix1[3][3];
double c = get33();
matrix[0][0] = matrix1[1][0]; matrix[0][1] = matrix1[1][1]; matrix[0][2] = matrix1[1][2];
matrix[1][0] = matrix1[2][0]; matrix[1][1] = matrix1[2][1]; matrix[1][2] = matrix1[2][2];
matrix[2][0] = matrix1[3][0]; matrix[2][1] = matrix1[3][1]; matrix[2][2] = matrix1[3][2];
double d = get33();

n = matrix1[0][0]*a -matrix1[0][1]*b + matrix1[0][2]*c -matrix1[0][3]*d;
}					    


if (n==-999999999.0){
cout<<"\n! Matrix must be 2*2 or 3*3 or 4*4.\nFill and run again\n";
   				 system("pause"); 
					return 1;   				   
   				   }

cout<<"\nDeterminant is: "<<n;
   					
cout<<"\n";  system("pause");
  return 0;
}