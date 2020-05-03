
/*
Babak Poursartip
05/02/2020

Linkedin: advanced topics in cpp

chapter 1: member function

important notes:
1-Any method that is called on a const qualify object must be const saved.
2- We can have two func members with the exact same name (one is const
qualified, the other is not)
3- Rule of thumb:
   3a: const functions can always be called(mutable or not).
   3b: non-const objects/funcs may only be called by non-const objects.
   3c: if you have a const func, you need a const obj to call it.


*/

#include <cstdio>

class A {
private:
  int _value = 0;

public:
  void setv(const int a) { _value = a; };
  int getv();
  int getv() const;
};

int A::getv() {
  puts("mutable getv");
  return _value;
};

int A::getv() const {
  puts("const getv");
  return _value;
}; // const qualify

int main() {

  printf(" program starts ... \n\n");

  A a;
  a.setv(12);
  printf(" this is a: %d \n", a.getv()); // calls mutable

  const A b = a;
  printf(" this is a: %d \n", b.getv()); // calls const

  printf(" \n program ends! \n");

  return 0;
}
