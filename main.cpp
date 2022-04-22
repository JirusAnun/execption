#include <iostream>
#include <exception> 

using namespace std;

class my_cin: public exception 
{ public:
     virtual const char* what() const throw() {
        return "Stupid it\'s not a number"; 
     }
}; 

class zero_cin: public exception 
{ public:
     virtual const char* what() const throw() { 
			return "Divided by 0";
     }
}; 


void check0(int);

int main(){
	int x,y,a; 
	double d;
  my_cin myex;
  zero_cin myex_zero;

do{  
  a=0;

try{
  cout<<"Input 2 numbers:";
 	 cin>>x>>y;
	if(cin.fail()) throw myex;
	if (y==0) throw myex_zero;  
  //check0(y);
  
	d=(double) x/y;
	cout<< "The result is "<<d<<endl;	
}

catch(exception &e){
  cout<<e.what();
  cout<<endl;
  a=1;
  
  cin.clear();// error 
  cin.ignore(10,'\n');
}
/*catch(int ){
   cout<<"Error divided by zero!!"<<endl;
   a=1;
}*/

  }while(a);


	return 0;
}
	
/*
  void check0(int n)  {
  my_cin temp;
  if(n==0) throw n ;

  
}
*/