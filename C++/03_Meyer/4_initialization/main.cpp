
/*

Babak Poursartip
11/09/2020

source: Effective C++, Meyer

Topic: initialization
item 4 

The correct method to initialize items in an object is the initialization list, not assingning. By assigning, you first call the ctor of the A class, and then use a copy assignment, which is not needed. For built-in types it does not matter. 

In the initialization list, though, the copy constructor is only called. A call to copy-constructor is more efficient than a call to the default constructor followed by a copy assignment.

*/

#include <iostream>


class A{
  public:
    A(){std::cout << "ctor A \n";}
    A(const A &a){std::cout << "copy ctor A \n";} // copy constructor
    A &operator=(const A &a){
      A b(a);
      std::cout << "copy assingment A \n";
      return *this;
    } // copy assignment constructor
};


// assingment
class B{
  public:
    B(A aa){
      Aobj = aa;
      std::cout << "ctor B \n";
    }
  A Aobj;
};


// initialization list, 
class C{
  public:
    C(A &Aobj):Aobj(Aobj){
      std::cout << "ctor C \n";
    }
  A Aobj;
};

int main(){

std::cout << " starts ...\n";

A aobj;
std::cout << " checkpiont 1 \n";
B bobj(aobj);
std::cout << " checkpiont 2 \n";
C cobj(aobj);

std::cout << " finished! \n";

return 0;
}
