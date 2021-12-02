/*

Babak Poursartip

12/1/2021

topic: auto, decltype

*/

#include <iostream>
#include <vector>

int fun1() { return 10; }
char fun2() { return 'g'; }


int main()
{
std::cout << " starts here ... \n";

std::cout << "1 auto ========================= \n";
// Since we are initializing the var, we can use auto instead of directly defining the type

auto x = 2;
auto y = 3.5;
auto z = 4.f;

auto iptr = &x;
auto dptr = &y;
auto fptr = &z;

std::cout << typeid(x).name() << std::endl;  // returns i for integer
std::cout << typeid(y).name() << std::endl;  // returns d
std::cout << typeid(z).name() << std::endl;  // returns f
std::cout << typeid(iptr).name() << std::endl; // returns Pi: means pointer to integer
std::cout << typeid(dptr).name() << std::endl; // returns Pd: means pointer to integer
std::cout << typeid(fptr).name() << std::endl; // returns Pf: means pointer to integer

std::cout << "2 decltype ========================= \n";

decltype(fun1()) xx; // Data type of x is same as return type of fun1()
decltype(fun2()) yy; // data type of y is same as return type of fun2()
decltype(fptr) fptr2;
decltype((y)) zz = y; // type of z is const double& (lvalue expression)
std::cout << typeid(xx).name() << std::endl;
std::cout << typeid(yy).name() << std::endl;
std::cout << typeid(zz).name() << std::endl;
std::cout << typeid(fptr2).name() << std::endl; // returns Pf: means pointer to integer

std::cout << "3 value_type ========================= \n";
std::vector<int> vec;
decltype(vec)::value_type ii = 5; // int ii = 5
std::cout << sizeof(decltype(vec)::value_type) << std::endl;

std::cout << " ========================= \n";
std::cout << " done.  \n";
return 0;
}

