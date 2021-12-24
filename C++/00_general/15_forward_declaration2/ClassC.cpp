
#include "ClassC.h"

C::C():cvar{7}{ std::cout << " C default ctor\n";}
C::C(int c):cvar{c}{ std::cout << " C ctor\n";}

void C::set(int c)
{
  std::cout << " setter \n";
  cvar = c;
}

int C::get()
{
  std::cout << " getter \n";
  return cvar;
}

