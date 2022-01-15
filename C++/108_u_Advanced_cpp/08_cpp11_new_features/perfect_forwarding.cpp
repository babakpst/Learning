

// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// perfect forwarding + reference collapsing + rvalue/lvalue

#include <iostream>

using namespace std;
class test {};
void check(test &tst) { cout << "lvalue\n"; }
void check(test &&tst) { cout << "rvalue\n"; }

// this function can be called with either rvalue or lvalue.
template <typename T>
void call(T &&arg) { check(arg); }

template <typename T>
void call2(T &&arg) { check(static_cast<T>(arg)); }

template <typename T>
void call3(T &&arg) { check(forward<T>(arg)); }

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  test tst;   // tst is lvalue

  // an rvalue reference, auto = test
  auto &&t = test();

  // reference collapsing rule: if the right side is lvalue, the rvalue reference collapses to an lvalue -> t2 is lvalue
  auto &&t2 = tst;

  // Not perfect forwarding:
  // passing rvalue, but it returns lvalue, if we do not cast it.
  call(test()); // return lvalue
  call(tst);    // return lvalue

  // Perfect forwarding:
  // passing rvalue, and returns rvalue, if we do cast it.
  call2(test()); // return rvalue
  call2(tst);    // return lvalue

  // Perfect forwarding:
  // passing rvalue, and returns rvalue, if we do cast it.
  call3(test()); // return rvalue
  call3(tst);    // return lvalue

  cout << " \n ends\n";

  return 0;
}
