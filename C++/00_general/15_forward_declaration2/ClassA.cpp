
#include "ClassA.h"

A::A():avar{5}{ std::cout << " A default ctor\n";}
A::A(int a):avar{a}{ std::cout << " A ctor\n";}

void A::set(int a)
{
  std::cout << " setter \n";
  avar = a;
}

int A::get()
{
  std::cout << " getter \n";
  return avar;
}

