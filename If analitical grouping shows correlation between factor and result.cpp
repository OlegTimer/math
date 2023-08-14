#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

#define PI 3.14159
#define E  2.71828

int main()
{
vector<vector<double> >  vec; 
vector<string> arr;
string str ("");
string delim("\t");   
	 	
ifstream file("_input.txt");

cout<<"If analitical grouping shows correlation between factor and result\n-\n";
cout<<"Enter 2 columns tab-separated (1.0 for doubles) \n";
cout<<"to _input.txt in program's directory\nFactor	Result\n";

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
vec.push_back(v);   
    }
    file.close();
}


if (vec.size()<1){
cout<<"\nSeems _input.txt is empty. Fill it, please\n";   				  
system("pause");
return 1;    				  
}

sort (vec.begin(), vec.end());   

int ster = 1 + 3.322* log10(vec.size());
double min = vec[0][0];
double max = vec[vec.size()-1][0];
double step = abs(max-min)/ster;

vector<int>  freq;
vector<double>  freqsum;
for (int i = 0; i<ster; i++){
freq.push_back(0);
freqsum.push_back(0);
}

double compare = min+step;
int grnum = 0;
for (int i = 0; i<vec.size(); i++){
if (vec[i][0]<=compare) {freq[grnum]++; freqsum[grnum]+=vec[i][1];}
else{
grnum++;
compare +=step;
freq[grnum]++;
freqsum[grnum]+=vec[i][1];	 
	 }
	}

int maxfreq = 0;
int maxfreqindex = 0;
for (int i = 0; i<ster; i++){
if (freq[i]>maxfreq){maxfreq=freq[i]; maxfreqindex=i;}
}



cout<<"\n\nEqual duration Sturges intervals of factors with mean result:\n-\n";
cout<<"Start\tEnd\tMean\tFreq\tRelative_freq\n";
for (int i = 0; i<ster; i++){
double r = 	freq[i]/ (1.0*vec.size());
double m = freqsum[i]/freq[i];
int m2 = m*1000;
m=m2/1000.0;
cout<<min+i*step<<"\t"<<min+(i+1)*step<<"\t"<<m<<"\t"<<freq[i]<<"\t"<<r<<"\n";
}

cout<<"\nFactors (start-end) are supposed to be growing (at least not decreasing).\n";
cout<<"If Result (mean) is growing too - correlation is positive.\n";
cout<<"If Result (mean) is decreasing - correlation is negative (reverse).\n";
cout<<"If Result (mean) is chaotical - correlation may not exist.\n";

cout<<"\nby OlegTim. ";
system("pause");
return 0;
}
