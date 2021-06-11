

// 05/08/2021
#include <iostream>

/*
- none of the derived classes can access anything that is private in A.
- B_pub inherits the public members of A as public, the protected ones as protected. 
- B_pr inherits the pulic and protected members of A as private.

Casing
- Any pointer can cast a B_pub* to A*. B_pub is-a A.
- private and protected inheritance is not an is-a relation.

*/


class A
{
public:
  void a_public(){std::cout << " a_public is called \n";}
protected:
  void a_protected(){std::cout << " a_protected is called \n";}
private:
  void a_private(){std::cout << " a_private is called \n";}
};

class B_public:public A
{
public:
 void f()
 {
   std::cout << " ===B_public f \n";
   a_public();     // ok
   a_protected(); // ok
   //a_private();    // Error: private to A
 }
};

class B_protected:protected A
{
public:
 using A::a_public; // brings the declaration of a_public here, so we can call it from B_protected
 void f()
 {
   std::cout << " ===B_protected f \n";
   a_public();     // ok, now a protected function of B_proteced
   a_protected(); // ok, now a protected function of B_proteced
   //a_private();    // Error: private to A
 }
};

class B_private:private A
{
public:
 void f()
 {
   std::cout << " ===B_private f \n";
   a_public();     // ok, a private function of B_private
   a_protected(); // ok a private function of B_private
   //a_private();    // Error: private to A
 }
};




int main()
{
  std::cout << " starts ... \n";

  A a1;
  a1.a_public();
  //a1.a_protected();  // error
  //a1.a_prrivate();   // error

  B_public b1;
  b1.f();
  b1.a_public();
  //b1.a_protected();  // error
  //b1.a_prrivate();   // error

  B_protected b2;
  b2.f();
  b2.a_public();    // error if not using in B_protected
  //b1.a_protected(); // error
  //b1.a_prrivate();  // error

  B_private b3;
  b3.f();

  A *pA1 = &b1;
  //A *pA2 = &b2; // Error

  std::cout << " ends \n";
  return 0;
}
