/*
Babak Poursartip
05/02/2020

Linkedin: advanced topics in cpp

chapter 1: Explicit constructor

important note:
To avoid that we need to put explicit in front of the name of the class
constructor.

*/

#include <cstdio>

class c1 {
  int _value = 0;
  c1(); // prevents the compiler to call the private constructor

public:
  c1(const int &value) : _value(value) {}
  // explicit c1(const int &value) : _value(value) {}  <====== important
  void setvalue(const int &value) { _value = value; }
  int getvalue() const { return _value; }
};

void func(const c1 &o) { printf(" value is: %d \n", o.getvalue()); }

int main() {

  printf(" program starts ... \n\n");
  // c1 x; // error because it cannot call the private constructor
  // this type of calling the constructor is only possible if you have a
  // constructor with only one argument.

  // this is implicit conversion. converts the ASCII value to number
  // To avoid that we need to put explicit in front of the name of the class
  // constructor.
  c1 o = 'x';
  printf(" value is %d \n", o.getvalue());
  func('x');

  printf(" \n program ends! \n");

  return 0;
}
