#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main ()
{ 	
vector<vector<double> >  matrix1;
vector<vector<double> >  matrix2;
vector<vector<double> >  res;	
vector<string> arr;
string str ("");
string delim("\t");


cout << "__ Matrix multiplier by OlegTim v 0.7 __\n";
cout << "Fill _matrixin1.txt and _matrixin2.txt in the program's directory.\n";
cout << "If absent, program will create new.\nOrder of multiply is important! A*B!=B*A\n";
cout << "Columns are tab-separated. Result will be in _matrixout.txt\n";
cout << "Make sure columns num of matrix1 are equal to rows num of matrix2\n\n";
   
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


ifstream file2("./_matrixin2.txt");
if(!file2) {	   
cout << "Cannot open file _matrixin2.txt. Trying to create new\n";
ofstream out32("_matrixin2.txt"); 
if(!out32) {
cout << "Cannot create _matrixin2.txt\n";
return 1;
}
out32 << "";
out32.close();
} 
 
if (file2.is_open()) {  					
    std::string line;
    while (std::getline(file2, line)) {
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
 matrix2.push_back(v);   
    }
    file2.close();
}	

   					
	cout<<"Matrix 1: \n"; 
for (int i = 0; i < matrix1.size(); i++) {
	for (int i2 = 0; i2 < matrix1[i].size(); i2++) {
cout<<matrix1[i][i2]<<"\t";
	}
	cout<<"\n";
}
	cout<<"\nMatrix 2: \n";
for (int i = 0; i < matrix2.size(); i++) {
	for (int i2 = 0; i2 < matrix2[i].size(); i2++) {
cout<<matrix2[i][i2]<<"\t";
	}
	cout<<"\n";
}


if (matrix1.size()<1 || matrix2.size()<1) {
cout<<"\n! matrixin1.txt 1 or/and _matrixin2.txt seems empty. Fill and run again\n";
   				 system("pause"); 
					return 1;
   					}

if (matrix1[0].size()!= matrix2.size()) {
cout<<"\n! Columns num of matrix1 are NOT equal to rows num of matrix2.\nFill and run again\n";
   				 system("pause"); 
					return 1;
   					}   					

for (int i2 = 0; i2 < matrix1.size(); i2++) {
vector<double> v;
for (int i = 0; i < matrix2[0].size(); i++) {
v.push_back(0);
}
res.push_back(v);
}

//
for (int r = 0; r < matrix2[0].size(); r++) {
for (int i = 0; i < matrix1.size(); i++) {
double sum=0;
for (int i2 = 0; i2 < matrix1[i].size(); i2++) {	
sum+=	matrix1[i][i2]*matrix2[i2][r];
	}
res[i][r]=sum;
}
}
//

cout<<"\nResult: \n";
for (int i = 0; i < res.size(); i++) {
	for (int i2 = 0; i2 < res[i].size(); i2++) {
cout<<res[i][i2]<<"\t";
	}
	cout<<"\n";
}


ofstream outr("_matrixout.txt"); 
if(!outr) {
cout << "Cannot create _matrixout.txt\n";
return 1;
}

for (int i = 0; i < res.size(); i++) {
	for (int i2 = 0; i2 < res[i].size(); i2++) {
outr<<res[i][i2]<<"\t";
	}
	outr<<"\n";
}
outr.close();
   					
cout<<"\n";  system("pause");
  return 0;
}
