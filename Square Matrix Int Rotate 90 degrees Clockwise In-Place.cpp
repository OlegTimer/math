#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
cout << "__ Square Matrix Int Rotate 90 degrees Clockwise In-Place __\n";
cout << "Fill _matrixin1.txt  in the program's directory.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n";
 	
vector<vector<int> >  matrix1;	
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
double d = atof(arr[i].c_str());
v.push_back(d);
}
 matrix1.push_back(v);   
    }
    file.close();
}	


if(matrix1.size()<1){cout<<"ERR empty entry\n";system("pause");return 1;} 	
if(matrix1.size()!=matrix1[0].size())
{cout<<"ERR entry not square\n";system("pause");return 1;}


cout<<"\nInput:\n"; 
for (int i = 0; i < matrix1.size(); i++) {
	for (int i2 = 0; i2 < matrix1[i].size(); i2++) {
cout<<matrix1[i][i2]<<"\t";
	}
	cout<<"\n";
}


for (int i = 0; i < matrix1.size()/2+1; i++) {
	for (int i2 = i; i2 < matrix1[i].size()-i-1; i2++) {		
int leftup = matrix1[i][i2];
int rightup = matrix1[i2][matrix1.size()-i-1];
int leftdown = matrix1[matrix1.size()-i2-1][i];
int rightdown = matrix1[matrix1.size()-i-1][matrix1.size()-i2-1];
//cout<<leftup<<" "<<rightup<<" "<<leftdown<<" "<<rightdown<<"\n";
matrix1[i][i2] = leftdown;
matrix1[i2][matrix1.size()-i-1] = leftup;
matrix1[matrix1.size()-i-1][matrix1.size()-i2-1] = rightup;
matrix1[matrix1.size()-i2-1][i] = rightdown; 
	}
}


cout<<"\nOutput:\n"; 
for (int i = 0; i < matrix1.size(); i++) {
	for (int i2 = 0; i2 < matrix1[i].size(); i2++) {
cout<<matrix1[i][i2]<<"\t";
	}
	cout<<"\n";
}

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}