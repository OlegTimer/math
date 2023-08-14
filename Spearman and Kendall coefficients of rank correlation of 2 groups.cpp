#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
vector<double>  vec;
vector<double>  vec2;
vector<double>  vec2s; 	 
vector<double>  vecy; 		 	

cout<<"Spearman and Kendall coefficients of rank correlation of 2 groups\n\n";
cout<<"Enter column of nums (1.1 for doubles) to _input.txt and _input2.txt\n";
cout<<"in program's directory (groups must be same size, no repeats)\n\n";

ifstream file("_input.txt");
if(!file) {
cout<<"_input.txt is absent. Creating new. Fill it, please\n";
ofstream outo("_input.txt"); 
if(!outo) {
cout << "Cannot create _input.txt\n";
return 1;
}
outo <<"";
outo.close();
} 

if (file.is_open()) {  					
    std::string line;
    while (std::getline(file, line)) {
double d = atof(line.c_str());
vec.push_back(d);
    }
    file.close();
}

ifstream file2("_input2.txt");
if(!file2) {
cout<<"_input2.txt is absent. Creating new. Fill it, please\n";
ofstream outo2("_input2.txt"); 
if(!outo2) {
cout << "Cannot create _input2.txt\n";
return 1;
}
outo2 <<"";
outo2.close();
} 

if (file2.is_open()) {  					
    std::string line;
    while (std::getline(file2, line)) {
double d = atof(line.c_str());
vec2.push_back(d);
vec2s.push_back(d);
    }
    file2.close();
}

					 
if (vec.size()<1 || vec2.size()<1){
cout<<"Seems _input.txt and/or _input2.txt is empty. Fill it, please\n";   				  
system("pause");
return 1;    				  
					 }

if (vec.size() != vec2.size()){
cout<<"Error. Seems _input.txt and _input2.txt have groups of different size\n";   				  
system("pause");
return 1;    				  
					 }						 					 


//if input is correct
cout<<"\nG1\tG2\n~\t~\n";
	for (int i = 0; i < vec.size(); i++) {
cout<<vec[i]<<"\t"<<vec2[i]<<"\n";
	}
	
sort (vec2s.begin(), vec2s.end());
vector<double>  v;
	for (int i = 0; i < vec.size(); i++) {
v.push_back(vec2s[i]);
	}
vec2s.clear();
	for (int i = vec.size()-1; i >-1 ; i--) {
vec2s.push_back(v[i]);
	}

for (int i = 0; i < vec.size(); i++) {//
double t = vec2[i];
double t2 = 0;
	for (int i2 = 0; i2 < vec.size(); i2++) {
t2=vec2s[i2];
if (t2==t){t2=i2+1; break;}		
		}
vecy.push_back(t2);	
	}//	

double sum = 0.0;
for (int i = 0; i < vec.size(); i++) {
sum+= ((i+1)-vecy[i]) * ((i+1)-vecy[i]);
	}

double res = 1 - ( 6*sum/( vec.size()*vec.size()*vec.size() - vec.size() ) );
cout<<"\nSpearman's selection coefficient is: "<<res;

sum=0.0;
for (int i2 = 0; i2 < vec.size(); i2++) {
for (int i = i2+1; i < vec.size(); i++) {
if (vecy[i2]<vecy[i]){sum++;}
	}
}

res = 4*sum/ (vec.size()*(vec.size()-1));
cout<<"\nKendall's   selection coefficient is: "<<res-1;
	
cout<<"\n\nby OlegTim. ";
system("pause");
return 0;
}
