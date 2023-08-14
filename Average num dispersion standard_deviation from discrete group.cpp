#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
vector<double>  vec; 	 	
ifstream file("_input.txt");
double sum = 0.0;
double sumsq = 0.0;

cout<<"Average num, dispersion, standard deviation from discrete group\n";
cout<<"Enter column of nums (1.0 for doubles) to _input.txt in program's directory\n\n";

if(!file) {
cout<<"_input.txt is absent. Creating new. Fill it, please\n";
ofstream outo("_input.txt"); 
if(!outo) {
cout << "Cannot create _input.txt\n";
return 1;
}
outo <<"";
outo.close();
system("pause");
return 1; 
} 

if (file.is_open()) {  					
    std::string line;
    while (std::getline(file, line)) {
double d = atof(line.c_str());
sum+=d;
sumsq+=d*d;
vec.push_back(d);
    }
    file.close();
}

if (vec.size()<1){
cout<<"Seems _input.txt is empty. Fill it, please\n";   				  
system("pause");
return 1;    				  
					 }

cout<<"\nGroup of tests is: \n";
	for (int i = 0; i < vec.size(); i++) {
cout<<vec[i]<<"\n";
	}

cout<<"\nAverage num is: "<<sum/vec.size();
double d = (sumsq/vec.size()) - (sum/vec.size())*(sum/vec.size());
cout<<"\nDispersion is: "<<d;
cout<<"\nStandard deviation is: "<<sqrt(d);

cout<<"\n\nby OlegTim. ";
system("pause");
return 0;
}
