
#include "myClass.h"
#include "ClassC.h"
//class C;


myClass::myClass():cvar{0}, aClassVar{A()}, bPnt{nullptr}
{
  std::cout << " myClass default ctor\n";
}


myClass::myClass(int a, A aclass):cvar{a}, aClassVar{aclass}, bPnt{nullptr}
{
  std::cout << " myClass ctor 1 \n";
}

myClass::myClass(int a, A aclass, B* bpnt):cvar{a}, aClassVar{aclass}, bPnt{bpnt}
{
  std::cout << " myClass ctor 2 \n";
}

void myClass::func()
{
  C myC;
  std::cout << " c Class in func:  " <<myC.get() << std::endl;
} 

void myClass::setter(int a, A aclass, B* bpnt)
{
  cvar = a;
  aClassVar = aclass;
  bPnt = bpnt;
}   

int myClass::getInt()
{
  return cvar;
}

A myClass::getA()
{
  return aClassVar;
}

B* myClass::getBPnt()
{
  return bPnt;
}
