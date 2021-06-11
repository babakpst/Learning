
#include "iostream"

class A
{

public:
virtual void func1()=0;
virtual void func2(){};

};

class B:public A
{
public:
virtual void func1(){}
virtual void func2(){}
};


int main()
{
std::cout << " starts ...\n";

//A a;
B b;

std::cout << " ends \n";
return 0;
}
