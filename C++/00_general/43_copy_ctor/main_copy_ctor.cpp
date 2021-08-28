// Babak Poursartip

// 09/25/2020

// copy constructor

#include <iostream>

class A{
private:
 int myVal;
public:
 A ():myVal{0}{std::cout<<"default ctor\n";}
 A (int a):myVal{a}{std::cout<<"ctor\n";}
 A (const A &a):myVal(a.myVal){std::cout<<"copy ctor\n";} // copy constructor
 
 A &operator=(const A &a){
   if(this != &a) myVal =a.myVal;
   return *this;
   std::cout<<"copy assignemtn\n";} // assingnment constructor
   
 int get(){return myVal;}
};

int main(){

std::cout<< "1===========\n";
A obj1;

std::cout<< "2===========\n";
A obj2(2);
std::cout <<"obj2: " << obj2.get() <<"\n";
std::cout<< "3===========\n";
obj2 = obj1;
std::cout <<"obj2: " << obj2.get() <<"\n";

std::cout<< "4===========\n";
A obj3(obj1);
std::cout <<"obj3: " << obj3.get() <<"\n";

std::cout<< "5===========\n";
A obj4 = A(5);
std::cout <<"obj4: " << obj4.get() <<"\n";

return 0;
}
