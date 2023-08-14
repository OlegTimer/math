#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
vector<double>  vec; 	 	
ifstream file("_input.txt");
double sum = 0.0;
double sumsq = 0.0;

cout<<"Typical characteristics of Sturges subgroups in discrete group\n";
cout<<"Mean, dispersion, deviation, median, mode in general totality\n-\n";
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


cout<<"\n\nIn general totality: ";
cout<<"\nAverage num (mean) is: "<<sum/vec.size();
double d = (sumsq/vec.size()) - (sum/vec.size())*(sum/vec.size());
cout<<"\nDispersion is: "<<d;
cout<<"\nStandard deviation is: "<<sqrt(d);

sort (vec.begin(), vec.end());

double median = 0.0;
if (vec.size()%2==0){
median = (vec[vec.size()/2] + vec[vec.size()/2+1])/2;   					 
   					}
else{
median = vec[vec.size()/2+1];	 
	 }   					
cout<<"\nMedian is: "<<median;


int ster = 1 + 3.322* log10(vec.size());
double min = vec[0];
double max = vec[vec.size()-1];
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
if (vec[i]<=compare) {freq[grnum]++; freqsum[grnum]+=vec[i];}
else{
grnum++;
compare +=step;
freq[grnum]++;
freqsum[grnum]+=vec[i];	 
	 }
	}

int maxfreq = 0;
int maxfreqindex = 0;
for (int i = 0; i<ster; i++){
if (freq[i]>maxfreq){maxfreq=freq[i]; maxfreqindex=i;}
}

double mode=0.0;
mode=(freq[maxfreqindex]-freq[maxfreqindex-1])*step;
mode = mode/((freq[maxfreqindex]-freq[maxfreqindex-1])
+(freq[maxfreqindex]-freq[maxfreqindex+1]));
mode += min+maxfreqindex*step;

cout<<"\nMode is: "<<mode<<"\n";
cout<<"( Mode is based on Sturges num with equal duration intervals )";
cout<<"\nSturges subgroups num is: "<<ster;


cout<<"\n\nEqual duration intervals:\n";
cout<<"Start\tEnd\tMean\tFreq\tRelative_freq\n";
for (int i = 0; i<ster; i++){
double r = 	freq[i]/ (1.0*vec.size());
double m = freqsum[i]/freq[i];
int m2 = m*1000;
m=m2/1000.0;
cout<<min+i*step<<"\t"<<min+(i+1)*step<<"\t"<<m<<"\t"<<freq[i]<<"\t"<<r<<"\n";
}

cout<<"\nEqual subgroups size intervals:\n";
cout<<"Start\tEnd\tMean\tFreq\tRelative_freq\n";
double start = min;
double fin = 0.0;
int grsize = vec.size()/ster;
for (int i = 0; i<ster; i++){	
double sum = 0.0;
int counter =0;	
for (int i2 = 0; i2<grsize; i2++){//
if (i*grsize+i2 <vec.size()){
double d = vec[i*grsize+i2];
sum+=d; 
counter++;
fin = d;				  
   				  }
		 }//
if ((i+1)*grsize <vec.size()){fin=0.5*(vec[(i+1)*grsize]+vec[(i+1)*grsize-1]);}		 
double m = sum/counter;
int m2 = m*1000;
m=m2/1000.0;
m2=fin*1000;
fin = m2/1000.0;		 
cout<<start<<"\t"<<fin<<"\t"<<m<<"\t"<<counter<<"\t"<<1.0*counter/vec.size()<<"\n";
start=fin; 		 	
	}

cout<<"\n\nby OlegTim. ";
system("pause");
return 0;
}
