#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159
#define E  2.71828
 
int main(){
double flaplacerev(double x);	
double p,q,x,a;
int n;
std::cout<<"Check if zero hypothesis a=a0, if opposite hypothesis a!=a0 \n";
std::cout<<"( if a is selected mean and a0 is hypothetical general mean ) \n";
std::cout<<"if level of importance is p of general totality with normal distribution\n";
std::cout<<"if standard deviation is q; sample mean is x; sample size is n\n";
std::cout<<"( Calculation is with Reverse Laplace Integral Function F(x) )\n-\n";
std::cout<<"For example, a=26; p=0.05; q=5.2; z=27.56; n=100;\n";
std::cout<<"U overseen value of criteria is: 3 > 1.96 U value of critical point\n";
std::cout<<"Zero hypothesis a=a0 is rejected. \n";
std::cout<<"Selected mean and hypothetical general mean differ much.\n";

std::cout << "\n\nEnter a=a0 value (for example 26): "; 
cin >> a;
std::cout << "Enter level of importance p (for example 0.05): "; 
cin >> p;
std::cout << "Enter standard deviation q (for example 5.2): "; 
cin >> q;
std::cout << "Enter sample mean x (for example 27.56): "; 
cin >> x;
std::cout << "Enter sample size n (for example 100): "; 
cin >> n;

double r=(1-p)/2;
if (r<-4 || r>4){
std::cout<<"Error in F(x) value, it must be:	F(x) <= |4|\n"; 
system("pause"); 
return 1;  		 
			}

double sign =1.0;	   
if (r<0){r=-r; sign=-1.0;}
double t = flaplacerev(r)*sign; 
double u = (x-a)*sqrt(n) / q;


std::cout<<"-\nU overseen value of criteria is: "<<u;
if (u>t){
std::cout<<" > ";   		 
   		 }
   		 else{
std::cout<<" < "; 		 	  
		 	  		   }
std::cout<<t<<" U value of critical point\n";


if (u>t){
std::cout<<"Zero hypothesis a=a0 is rejected. \n";
std::cout<<"Selected mean and hypothetical general mean differ much.\n"; 		 
}
else
{
std::cout<<"Zero hypothesis a=a0 is NOT rejected. \n";
std::cout<<"Selected mean and hypothetical general mean are close.\n";	 	  
}
 
std::cout<<"\n"; system("pause"); 
    return 0;
}


double flaplacerev(double x){
double delta =   0.01;
double margin =   0.0001;
double res = 0;
double flaplace(double x);
double d;

while (res<4){
d = flaplace(res);	  
if (d-margin<x && d+margin>x){break;}
res+=delta;
}
return res;
	   }

 
double flaplace(double x){
double delta =   0.0001;
double res = 0;
for (double i = 0; i < x; i+=delta){        
res += delta*fabs(pow(E,-0.5*pow(i,2))+pow(E,-0.5*pow((i+delta),2)))/2;   
}
res =  res/sqrt(2*PI);
return res;
}
