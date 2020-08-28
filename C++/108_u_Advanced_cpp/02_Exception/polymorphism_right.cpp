// Babak Poursartip
// https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Polymorphic_Exception#:~:text=When%20a%20polymorphic%20exception%20is,original%20exception%20object%20is%20propagated.

// 08/28/2020

// The throw statement has been moved into virtual functions. The raise function
// invoked in function foo is polymorphic and selects the implementation in
// either ExceptionBase or ExceptionDerived class depending upon what is passed
// as a parameter (dependency injection). Type of *this is obviously known at
// compile-time, which results into raising a polymorphic exception. The
// structure of this idiom is very similar to that of Virtual Constructor idiom.

#include <iostream>

struct ExceptionBase {
  virtual void raise() { throw *this; }
  virtual ~ExceptionBase() {}
};
struct ExceptionDerived : ExceptionBase {
  virtual void raise() { throw *this; }
};

void foo(ExceptionBase &e) {
  e.raise(); // Uses dynamic type of e while raising an exception.
}
int main(void) {

  puts(" starts \n");

  ExceptionDerived e;

  try {
    foo(e);
  } catch (ExceptionDerived &e) {
    // Exception raised in foo now matches this catch.
    puts(" caught the derived object. \n");
  } catch (...) {
    // not here anymore!
    puts(" did not catch the derived object. \n");
  }

  puts(" ends \n");
}