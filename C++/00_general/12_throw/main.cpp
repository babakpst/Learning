
// throw(): dynamic exception specifications. They are now deprecated in C++.

#include <iostream>

// exception_specification.cpp
// compile with: /EHs
#include <stdio.h>

void handler() {
   printf("in handler\n");
}

void f1(void) throw(int) {
   printf("About to throw 1\n");
   if (1)
      throw 1;
}

void f5(void) throw() {
   try {
      f1();
   }
   catch(...) {
      handler();
    }
}

// invalid, doesn't handle the int exception thrown from f1()
// void f3(void) throw() {
//   f1();
// }

//void __declspec(nothrow) f2(void) {
void f2(void) {
   try {
      f1();
   }
   catch(int) {
      handler();
    }
}

// only valid if compiled without /EHc
// /EHc means assume extern "C" functions don't throw exceptions
extern "C" void f4(void);
void f4(void) {
   f1();
}

// ======================
int main() {
  std::cout << " starts ...\n";
   f2();

   try {
      f4();
   }
   catch(...) {
      printf("Caught exception from f4\n");
   }
   f5();

  std::cout << "\n ends \n";
  return 0;

}
