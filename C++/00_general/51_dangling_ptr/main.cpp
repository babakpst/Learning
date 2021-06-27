
// Babak Poursartip
// 09/14/2020

//
// dangling pointer

// dangling pointer: A pointer pointing to a memory location that has been
// deleted (or freed) is called dangling pointer. There are three different ways
// where Pointer acts as dangling pointer

#include <iostream>

using namespace std;

//====================================================
// The pointer pointing to local variable becomes dangling when local variable
// is not static.
int *fun() {
  // x is local variable and goes out of scope after an execution of fun() is
  // over.
  int x = 5;
  return &x;
}

int *fun2() {
  // x is a static variable and will stored in the global memory, and not in the
  // stack.
  static int x = 50;
  return &x;
}

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  // Deallocating a memory pointed by ptr causes dangling pointer
  int *pInt = new int;

  // After below free call, ptr becomes a  dangling pointer
  delete pInt;
  pInt = nullptr; // not a dangling any more.

  cout << "\n2-----\n";
  // p points to something which is not valid anymore
  pInt = fun	();
  // cout << *pInt << endl; // segmentation fault.

  pInt = fun2();
  cout << *pInt << endl; // ok

  cout << " \n ends\n";

  return 0;
}
