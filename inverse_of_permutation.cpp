#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
vector< vector<int> >   vec;
	 	
cout<<"__ Inverse of permutation (count starts from 1) __\n\n";
cout<<"For example, for permutation 5 9 1 8 2 6 4 7 3 inverse is: 3 5 9 7 1 6 8 4 2\n";
cout<<"Enter column of integers to _input.txt in program's directory\n";
cout<<"Result is in _output.txt\n\n";


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
int i =1;   					  					 					
    std::string line;
    while (std::getline(file, line)) {
int d = atoi(line.c_str());
vector<int> arrd;  
arrd.push_back(d);
arrd.push_back(i);
i++;
vec.push_back(arrd);
    }
    file.close();
}

					 
if (vec.size()<1 ){
cout<<"Seems _input.txt is empty. Fill it, please\n";   				  
system("pause");
return 1;    				  
					 }

cout<<"\nYou entered:\n";  
for (int i=0; i<vec.size();i++) {cout<<vec[i][0]<<" "; }

sort (vec.begin(), vec.end()); 

cout<<"\nInverse of permutation is:\n";  
for (int i=0; i<vec.size();i++) {cout<<vec[i][1]<<" "; }


ofstream outw("./_output.txt"); 
if(!outw) {
cout << "Cannot create _output.txt\n";
cout<<"\n"; system("pause");
exit(1);
}
for (int i=0; i<vec.size();i++) {outw<<vec[i][1]<<"\n"; }
outw.close();
	
cout<<"\n\nby OlegTim. ";
system("pause");
return 0;
}
