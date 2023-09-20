#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector> 
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string> 
using namespace std;

#define PI 3.14159
#define W 999999999
#define M 0.0000001
#define D  0.001

int t;
string s("");
long double d, a, b, c, x1,x2,x3,f1,f2,f3;
int console_line_length = 41;
int console_line_num = 41;
vector<vector<long double> >  f;
vector<string>   result;
int onlyonefunction =0;
long double xmax, ymax, xmin, ymin;


int signum (long double z){
int r = 1;	
if (z<0){r=-1; }
return r;	
	}


void calc3(){
a= (double)1.0*a/d;
b= (double)1.0*b/d;
c= (double)1.0*c/d;
d=1.0;

double Q = (a*a-3*b)/9;
double R = (2*a*a*a-9*a*b+27*c)/54;
double S = Q*Q*Q - R*R;
double fi = 0.0;
double fi2 = 0.0;

if (S>M){// if S>0 , 3 roots
double fac = (R/sqrt(Q*Q*Q));
fi = (1.0*acos(fac))/3;

x1=-2*sqrt(Q)*cos(fi) - a/3;
fi2= (double)1.0*2/3*PI;
x2=(double)-2.0*sqrt(Q)*cos(fi+fi2) - a/3;
x3=(double)-2.0*sqrt(Q)*cos(fi-fi2) - a/3;
}
else{
if (S<-M){ //if S<0 , 1 root

if (Q>M){ 
double fac = (double) 1.0*abs(R)/pow(Q,3.0/2);
double fac2=(double) 1.0* log(fac+sqrt((fac*fac-1)));
fi= (double) 1.0*1/3*(fac2);
x1=(double) -2.0*signum(R)*sqrt(Q)*cosh(fi)-a/3;
}
else{
if (Q<-M){ 
double fac = (double) 1.0*abs(R)/pow(abs(Q),3.0/2);
double fac2=(double) 1.0* log(fac+sqrt((fac*fac-1)));
fi= (double) 1.0*1/3*(fac2);
x1=(double) -2.0*signum(R)*sqrt(abs(Q))*cosh(fi)-a/3;
}
else{
x1=(double) -1.0*cbrt(c-(a*a*a/27))-a/3;
}
}

}
else{// if S about 0, 2 roots
x1=(double)-2.0*cbrt(R)-a/3;
x2=(double)1.0*cbrt(R)-a/3;
}}						 	 
}


void calc2(){
long double dif = pow(b,2)-4*a*c;
x1=(-b+sqrt(dif))/(2*a);
x2=(-b-sqrt(dif))/(2*a);	 
}


void calc1(){
x1=-c/b;	 
}


void calc0(){
result.push_back("y(x)=const. That line is parallel to OX.\n");	  
}


void show(){
for (int i=0; i<result.size(); i++){
cout<<result[i];	
}
ofstream outw("./_output.txt"); 
if(!outw) {
cout << "Cannot create _output.txt\n";
cout<<"\n"; system("pause");
exit(1);
}
for (int i=0; i<result.size(); i++){
outw<<result[i];	
}
outw.close();	 
	 }


string funcshow (int t, double d, double a, double b, double c ){
string s2("");
if (t==1){
s2+="y = ";
ostringstream strs;
strs << abs(d);
string nt = strs.str(); 
if (d!=0){if(d<0){s2+="-";} if(abs(d)!=1){s2+=nt;}s2+="x^3 ";}
strs.str("");
strs << abs(a);
nt = strs.str();
if (a!=0){if(a<0){s2+="-";}else{s2+="+";} if(abs(a)!=1){s2+=nt;}s2+="x^2 ";}
strs.str("");
strs << abs(b);
nt = strs.str();
if (b!=0){if(b<0){s2+="-";}else{s2+="+";} if(abs(b)!=1){s2+=nt;}s2+="x ";}
strs.str("");
strs << abs(c);
nt = strs.str();
if(c<0){s2+="-";}else{s2+="+";} s2+=nt;
}//if t==1 end
return s2;
	   }


int check2(){
int err=0;	
if (f.size()!=0){//	
 
if (f.size()==1){
if (f[0][0] ==0){
cout << "\nSeems both functions are absent (0 - no function). err\n"; 
cout<<"\n\n\nMust be an error in functions. Restart program, read info and retry\n";   			
cout<<"\n"; system("pause");
exit(1);      			
			   }   				 
err++;   				 
cout << "//Seems one of functions is absent \n";
cout << "It is not an error, if you want to see only one function//\n";    				 
   				 }
   				 
if (f.size()>1){
if (f[0][0] ==0 || f[1][0]==0){ 
err++;   			  				
cout << "//Seems one of functions is absent (0 - no function)\n";
cout << "It is not an error, if you want to see only one function//\n";   				 
   				 }}
					   				 
				 } 	 //
if (err>0){onlyonefunction=1;}				 
return err;		 
	 }


int check(){ //if err is not zero  - error
int err=0;
if (f.size()==0){
   				 err++;
cout << "_input.txt seems to be empty. err\n";   				 
   				 }

if (f.size()>1){  // 
				 
if (f[0][0] ==0 && f[1][0]==0){
   			 err++;
cout << "Seems both functions are absent (0 - no function). err\n";   				 
   				 }

int q=0;
for (int i=1; i<5; i++){
if (f[0][i]==f[1][i]){q++;}
	}
if (q==4){cout << "Seems both functions are the same. err\n";  err++;}   				 
					}//
return err;						
	}


void addfunc (){
vector<long double> v;
v.push_back(t);
v.push_back(d); 
v.push_back(a); 
v.push_back(b); 
v.push_back(c);        
f.push_back(v); 	
	}


void enterfunc (){
cout<<"Enter function type: (0 - no function; 1 - y;): ";
cin>>t;
cout<<"Enter d (of dx^3 +ax^2 + bx+ c): ";
cin>>d;
cout<<"Enter a (of dx^3 +ax^2 + bx+ c): ";
cin>>a;
cout<<"Enter b (of dx^3 +ax^2 + bx+ c): ";
cin>>b;
cout<<"Enter c (of dx^3 +ax^2 + bx+ c): ";
cin>>c;	 
addfunc ();
	 }


int main(){		
f1=f2=f3=x1=x2=x3 = W; //start val max double. most likely NOT a root

cout<< "Calculate double integral_D dxdy      ( f(x;y)=1 ) \n";
cout<< "with D domain (plain figure), created with 2 functions y(x) \n";
cout<< "y(x) can be  cubic/quadratic/linear polynoms \n";
cout<< "y = dx^3 + ax^2 + bx + c\n";
cout<<"Also this integral is a square of D domain (plain figure), if it is closed\n\n";

cout<< "For example, with D y=x^2 -1; y=5-x; double integral_D dxdy = 20.83  \n\n";

cout << "Functions are in _input.txt in program's directory. ";
cout<< "\n( Columns are tab-separated ). You can edit files manually";
cout<< "\nNote: first value is function type: (0 - no function; 1 - y)\n";
cout<< "Next - coefficents of x^n. Second val is dx^3; third val ax^2...etc";
cout<< "\nFor example, for: '' y = 3x^3 - 4x +5 '' line would be:\n";
cout<< "1	3	0	-4	5\n";
cout<< "\nResult is in _output.txt\n";
cout<<"Options are in _options.txt First line is columns num, second - rows in graph\n";
cout << "If absent, program will create/rewrite new.\n";
cout << "( To view graph fine, it's better to use monotype font, like Lucida Console )\n\n";

cout<<"To enter function, at first select function type: \n(0 - no function; 1 - y;)";
cout<<"\nNext enter the coefficents of x^n (1.0 for double)";
cout<<"\nFor example:\t5x^3\t-x^2\t-20x\t+4=0 \nEnter:\t\t5\t-1\t-20\t 4";
cout<<"\nRoots: -2;	0.2;	2";
cout<<"\nWarning. Values may be close. i.e. 0.199996~0.2\t;\t1.85128e-017~0\n";


cout<<"\n\n... Trying to read _options.txt and _input.txt ...\n";
ifstream ino("./_options.txt", ios::in | ios::binary);
if(!ino) {
cout<<"_options.txt is absent. Creating new. Update it and console, if needed.\n";
ofstream outo("./_options.txt"); 
if(!outo) {
cout << "Cannot create _options.txt\n";
return 1;
}
outo << console_line_length<<"\n";
outo << console_line_num;
outo.close();
}
string line;
int counter=0;
    while (getline(ino, line)) {
	 line.c_str();
          if (counter==0){console_line_length=atoi( line.c_str() );}
           if (counter==1){console_line_num=atoi( line.c_str() );}
        counter++;
    }
cout << "_options.txt OK\n";   
ino.close();


ifstream file2("./_input.txt");
if(!file2) {
cout << "Cannot open _input.txt\n";
cout << "Creating default _input.txt \n";
ofstream out3("./_input.txt"); 
if(!out3) {
cout << "Cannot create ./_input.txt\n";
cout<<"\n"; system("pause");
exit(1);
}
out3.close();
}
file2.close();


ifstream file("./_input.txt");
if (file.is_open()) {	     					
    std::string line;
    while (std::getline(file, line)) {
        line.c_str();
        vector<string> arr;
  string delim("\t");
  size_t prev = 0;
  size_t next;
  size_t delta3 = delim.length();
  while( ( next = line.find( delim, prev ) ) != string::npos ){
    arr.push_back( line.substr( prev, next-prev ) );
    prev = next + delta3;
  }
arr.push_back( line.substr(prev ) );
t =  atoi(arr[0].c_str()) ;
d =  atof(arr[1].c_str()) ;
a =  atof(arr[2].c_str()) ;
b =  atof(arr[3].c_str()) ;
c =  atof(arr[4].c_str()) ;
addfunc();   
    }
    file.close();
}


ofstream out("./_output.txt"); 
if(!out) {
cout << "Cannot create _output.txt\n";
cout<<"\n"; system("pause");
return 1;
}
out.close(); 


int err=check();  				  				 					   				 
if (err!=0){
cout<<"\n\nAs functions are incomplete, you need to enter new info\n";   			
cout<<"Enter function(s), please\n";
cout<<"In this version only 2 functions of y(x)\n\n";
cout<<"Enter first function:\n";
enterfunc ();
cout<<"\nEnter second function:\n";
enterfunc ();
err=check();
if (err!=0){
cout<<"\n\n\nMust be an error in functions. Restart program, read info and retry\n";   			
cout<<"\n"; system("pause");
exit(1);   			
   			}

ofstream outw2("./_input.txt"); 
if(!outw2) {
cout << "Cannot create _input.txt\n";
cout<<"\n"; system("pause");
exit(1);
}
for (int i = 0; i<f.size();i++){
outw2<<f[i][0]<<"\t"<<f[i][1]<<"\t"<<f[i][2]<<"\t"<<f[i][3]<<"\t"<<f[i][4]<<"\n" ;
	}
outw2.close();   			
}
else{
cout<<"_input.txt with functions OK";	 
	 }

cout<<"\n"; 
err=check2();
string sf1("");
string sf2("");
cout<<"\n_________________________________\n\n\n";
result.push_back("f(x;y)=1; Double integral_D dxdy with D domain:\n");
for (int i=0; i<f.size(); i++){
t=(int) f[i][0]; 
d=f[i][1];
a=f[i][2];
b=f[i][3];
c=f[i][4];
if (t==1)				{
s=  funcshow(t,d,a,b,c)	;				
result.push_back(s); 
if (i==0){sf1=s;}
if (i==1){sf2=s;}
result.push_back("\n");	
						}
}
result.push_back("\n");	
//let's get coeff from both func
long double t1,d1, a1, b1, c1, t2, d2, a2, b2, c2;
t1=d1= a1= b1= c1 =t2=d2= a2= b2= c2 =0;
t1=f[0][0]; 
if  (t1==1){
d1=f[0][1];
a1=f[0][2];
b1=f[0][3];
c1=f[0][4];
}

if (f.size()>1){//
t2=f[1][0];
if  (t2==1){
d2=f[1][1];
a2=f[1][2];
b2=f[1][3];
c2=f[1][4];
}   				
				   }//


//by this step input is OK. let's calculate
d=d1-d2;
a=a1-a2;
b=b1-b2;
c=c1-c2;

int decide=0;
if (b!=0){decide=1;}
if (a!=0){decide=2;}
if (d!=0){decide=3;}

if (decide!=0){
t=1;
string tmp = (funcshow(t,d,a,b,c));
string sub = tmp.substr(4, 80);
result.push_back(sub);
result.push_back(" = 0\n");
}

switch(decide){ 
case 3: { calc3();  break;  }
case 2: { calc2();  break;  }
case 1: { calc1();  break;  }
default:{ calc0();  break;  }
}

if (x1==x2 || x1==x3){x1=W;}
if (x2==x1 || x2==x3){x2=W;}
if (x3==x1 || x3==x2){x3=W;}

if (onlyonefunction!=0){
result.push_back("For single function root(s) are at y(x)=0 Crossing OX\n");  						
						}

if (x1!=W && t1==1){f1=d1*x1*x1*x1 + a1*x1*x1 + b1*x1 +c1; }			  
if (x1!=W && t2==1){f1=d2*x1*x1*x1 + a2*x1*x1 + b2*x1 +c2;}
if (x2!=W && t1==1){f2=d1*x2*x2*x2 + a1*x2*x2 + b1*x2 +c1; }			  
if (x2!=W && t2==1){f2=d2*x2*x2*x2 + a2*x2*x2 + b2*x2 +c2;}
if (x3!=W && t1==1){f3=d1*x3*x3*x3 + a1*x3*x3 + b1*x3 +c1; }			  
if (x3!=W && t2==1){f3=d2*x3*x3*x3 + a2*x3*x3 + b2*x3 +c2;}
						
result.push_back("Root(s)  (x\ty):\n"); 						
ostringstream strs;
strs << x1;
string nt = strs.str();
if (x1==W){nt="none";}
result.push_back("("+nt);
strs.str("");
strs << f1;
nt = strs.str();
if (x1==W){nt="";}
result.push_back("\t"+nt+")\n");

strs.str("");
strs << x2;
nt = strs.str();
if (x2==W){nt="none";}
result.push_back("("+nt);
strs.str("");
strs << f2;
nt = strs.str();
if (x2==W){nt="";}
result.push_back("\t"+nt+")\n");

strs.str("");
strs << x3;
nt = strs.str();
if (x3==W){nt="none";}
result.push_back("("+nt);
strs.str("");
strs << f3;
nt = strs.str();
if (x3==W){nt="";}
result.push_back("\t"+nt+")\n"); 

int xnum=0;
if (x1!=W){xnum++;}
if (x2!=W){xnum++;}
if (x3!=W){xnum++;}
int ifclosedfigure=1; //0 yes
if (onlyonefunction==0 && xnum ==2){ifclosedfigure=0;}

if (ifclosedfigure==0){
s="2 functions, 2 roots - closed figure may exist.\n";   					   
   					   }
   					   else{
s="Not 2 roots and/or one function  - closed figure may not exist.\n" ;					   		
					   		}
result.push_back(s); 

//graph start
char matrix[console_line_num ][console_line_length]; 
for (int i2 = 0; i2 < console_line_num;  i2++) {
for (int i3 = 0; i3 < console_line_length;  i3++) {	
matrix[i2][i3]=' '; }}

double defaultsize = 5;

if (x1!=W){xmax=x1;}
if (x2!=W){if (xmax<x2){xmax=x2;}}
if (x3!=W){if (xmax<x3){xmax=x3;}}

if (x1!=W){xmin=x1;}
if (x2!=W){if (xmin>x2){xmin=x2;}}
if (x3!=W){if (xmin>x3){xmin=x3;}}


if (xnum==0){
 xmax = defaultsize;  	
 xmin = -defaultsize;
 ymax=defaultsize; 
 ymin=-defaultsize;
   			 }

if (xnum==1){
xmax+=defaultsize;  
xmin-=defaultsize;
   			 }
// cout<<xmin<<" <=x<= "<<xmax<<"\n";
//min and max for 2 points is exact, for 0/1 point\root min\max +/-INFINITY

long double xs,ys, height;
xs=(xmax-xmin)/(console_line_length-1);  
//at this step we know only x dimensions, for y - roots only

vector<long double> y1var;
vector<long double> y2var;

if (t1==1){ //if first function exist start
long double xp, yp;
xp=xmin;   		   
for (int i=0; i<console_line_length; i++){ 
yp =d1*xp*xp*xp + a1*xp*xp + b1*xp +c1;
y1var.push_back(yp);
if (yp>ymax){ymax=yp;}
if (yp<ymin){ymin=yp;}
xp+=xs;	
	}
}//if first function exist end

if (t2==1){ //if second function exist start
long double xp, yp;
xp=xmin;   		   
for (int i=0; i<console_line_length; i++){ 
yp =d2*xp*xp*xp + a2*xp*xp + b2*xp +c2;
y2var.push_back(yp);
 if (yp>ymax){ymax=yp;}
 if (yp<ymin){ymin=yp;}
xp+=xs;	
	}
}//if second function exist end

height=ymax-ymin;
ys=(height)/(console_line_num-1); 
long double m;
int yn;

if (xmin<0 && xmax>0){ //build OX start
m=((0-xmin)/(xmax-xmin))*console_line_length;
yn = (int)m;
for (int i=0; i<console_line_num; i++){
matrix[i][yn]='|';	
	} 		   
			  }  //build OX end
			  
if (ymin<0 && ymax>0){ //build OY start
m=(1-((0-ymin)/(ymax-ymin)))*console_line_num;
yn = (int)m;
for (int i=0; i<console_line_length; i++){
matrix[yn][i]='-';	
	} 		   
			  }  //build OY end				  		  		  


for (int i=0; i<y1var.size(); i++){
m=y1var[i];
m=(1-((m-ymin)/height))*console_line_num;
yn = (int)m;
if (yn<0){yn=0;}
if (yn>console_line_num-1){yn=console_line_num-1;}
matrix[yn][i]='*';
	}
	
for (int i=0; i<y2var.size(); i++){
m=y2var[i];
m=(1-((m-ymin)/height))*console_line_num;
yn = (int)m;
if (yn<0){yn=0;}
if (yn>console_line_num-1){yn=console_line_num-1;}
matrix[yn][i]='~';
	}	
//graph end


if (ifclosedfigure==0){//let's find the domain if it exist start
string xmins("");
string xmaxs("");
strs.str("");
strs << xmin;
nt = strs.str();
xmins = nt;
result.push_back(nt+" <x< ");
strs.str("");
strs << xmax;
nt = strs.str();
xmaxs = nt;
result.push_back(nt+"\n");

strs.str("");
strs << ymin;
nt = strs.str();
result.push_back(nt+" <y< ");
strs.str("");
strs << ymax;
nt = strs.str();
result.push_back(nt+" \t(on graph)\n");

long double mx,m1,m2,mt;
mx = xmin+((xmax-xmin)/2);
m1 =d1*mx*mx*mx + a1*mx*mx + b1*mx +c1;
m2 =d2*mx*mx*mx + a2*mx*mx + b2*mx +c2;

int top =0;
if (m1<m2){top=2;}
if (top !=0){ //if first function is not on top
s=sf1;
sf1=sf2;
sf2=s; //sf1 is from now top func  
long double dq, aq, bq, cq;
dq=d1; aq=a1; bq=b1; cq=c1;
d1=d2; a1=a2; b1=b2; c1=c2;
d2=dq; a2=aq; b2=bq; c2=cq; //d1,a1,b1,c1 are from now coeff of top func  		
		   }//if first function is not on top end

string tmp = sf2;
string sub = tmp.substr(4, 80);
sf2 = sub;
result.push_back(sub);
result.push_back(" <y< ");
 tmp = sf1;
 sub = tmp.substr(4, 80);
 sf1 = sub;
result.push_back(sub+" \t(on order of integration)\n");
result.push_back("Proceed to repeated integrals: \n");
s="integral from "+xmins+" to "+xmaxs+" dx integral from ";
s+=sf2+" to "+sf1+" f(x;y)dy";
result.push_back(s+"\n");

//let's calulate inner integral
//as f(x;y)=1 it is simply calculated with Newton-Leibnitz
t=1;
d=d1-d2;
a=a1-a2;
b=b1-b2;
c=c1-c2;
string inner("");
inner = funcshow(t,d,a,b,c)	;
sub = inner.substr(4, 80);
inner=sub;
s="inner integral is: "+inner;
result.push_back(s+"\n");

result.push_back("Proceed to definite integral: \n");
s="integral from "+xmins+" to "+xmaxs+" ( "+inner+" ) dx";
result.push_back(s+"");

long double in; //calc defin integral by middle squares
for(double i = xmin+D/2; i<xmax; i+=D ){
in+=(d*i*i*i + a*i*i + b*i + c)*D;
	  }
strs.str("");
strs << in;
nt = strs.str();	  
result.push_back(" = "+nt+"\n");
}//let's find the domain if it exist end

result.push_back("\nGraph. OX increases to right. OY to up\n\n"); //write matrix start
for (int i=0; i<console_line_num; i++) {
s="";	
for (int i2=0; i2<console_line_length; i2++) {
s+=matrix[i][i2];	
}
s+="\n";
result.push_back(s); 
} //write matrix end
 
// show and write to file results
show();
cout<<"\n\nYou can update functions in _input.txt or remove it and enter new info";
cout<<"\nby OlegTim	";
system("pause");
return 0;
}
