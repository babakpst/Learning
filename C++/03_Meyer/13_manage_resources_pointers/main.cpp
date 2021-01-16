
/*

Babak Poursartip
01/16/2020

source: Effective C++, Meyer


item 13: Use objects to manage resources

Remarks(from my studies)
auto_ptr is deprecated at c++11. Only works with earlier editions.
auto_ptr is similar to unique_ptr

*/

#include <iostream>
#include <memory>

// ===================================
class A{
private:
  int m_int;
public:
  A(int a=0):m_int(a){std::cout << "ctor\n";}
  ~A(){std::cout << "dtor\n";}
  
  int getter(){return m_int;}
  void setter(int a){m_int=a;}
};

// ===================================
void f(){

std::cout << "1 =====\n";
std::auto_ptr<A> pA0(new A);
std::cout << "int var of pA0 is: " << pA0->getter() << std::endl;

std::cout << "2 =====\n";
std::auto_ptr<A> pA1(pA0);
  if (pA0.get()) std::cout << "int var of pA0 is: " << pA0->getter() << std::endl;
  else std::cout << " pA0 is null\n";
std::cout << "int var of pA1 is: " << pA1->getter() << std::endl;

  if(!NULL) std::cout << " print !null == true\n";

std::cout << "3 =====\n";
std::auto_ptr<A> pA2(new A);
std::cout << "int var of pA2 is: " << pA2->getter() << std::endl;
pA1->setter(5);
pA2 = pA1;
  if (pA1.get()) std::cout << "int var of pA1 is: " << pA1->getter() << std::endl;
  else std::cout << " pA1 is null\n";
std::cout << "int var of pA2 is: " << pA2->getter() << std::endl;


std::cout << "4=====\n";
pA2 = pA0;
  if (pA0.get()) std::cout << "int var of pA0 is: " << pA1->getter() << std::endl;
  else std::cout << " pA0 is null\n";

  if (pA2.get()) std::cout << "int var of pA2 is: " << pA2->getter() << std::endl;
  else std::cout << " pA2 is null\n";

}

// ===================================
int main(){

std::cout << " starts ...\n";

f();

std::cout << " finished!\n";

return 0;
}
