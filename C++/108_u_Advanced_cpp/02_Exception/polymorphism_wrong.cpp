
// Babak Poursartip
// 08/28/2020

// Exception polymorphism
// Udemy: Advanced c++

// foo throws the base and not the derived class. Thus, it goes through the
// catch all.

#include <iostream>

struct ExceptionBase {};
struct ExceptionDerived : ExceptionBase {};

void foo(ExceptionBase &e) {
  throw e; // Uses static type of e while rasing an exception.
}
int main(void) {
  puts(" starts \n");

  ExceptionDerived e;
  try {
    foo(e);
  } catch (ExceptionDerived &e) {
    // Exception raised in foo does not match this catch.
    puts(" caught the derived object. \n");
  } catch (...) {
    // Exception raised in foo is caught here.
    puts(" did not catch the derived object. \n");
  }
  puts(" \n ends");
}