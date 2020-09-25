// Babak Poursartip

// 09/25/2020

// copy constructor

#include <iostream>

class A{
public:
A (){std::cout<<"ctor\n";}
A (const A &a){std::cout<<"copy ctor\n";}
A &operator=(const A &a){std::cout<<"copy assignemtn\n";}
};

int main(){

A obj1;
A obj2;
obj2 = obj1;

A obj3(obj1);

return 0;
}
