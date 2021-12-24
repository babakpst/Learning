
#include "ClassB.h"

B::B():bvar{6}{ std::cout << " B default ctor\n";}
B::B(int b):bvar{b}{ std::cout << " B ctor\n";}

void B::set(int b)
{
  std::cout << " setter \n";
  bvar = b;
}

int B::get()
{
  std::cout << " getter \n";
  return bvar;
}

