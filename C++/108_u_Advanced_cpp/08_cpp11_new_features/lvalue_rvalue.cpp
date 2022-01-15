
// Babak Poursartip
// 09/10/2020

// Udemy: Advanced c++
// lvalue rvalue
// lvalue: we can get the address of the variable, rvalue, we cannot.

#include <iostream>

using namespace std;

class tst {
public:
  tst() {}
};

tst getTest() { return tst(); }

// lvalue/rvalue version of the check (never be called bcs other functions always proceed here.)
void check(const tst &value) { cout << "lvalue/rvalue func\n"; }

// lvalue version of the check
void check(tst &value) { cout << "lvalue func\n"; }

// rvalue version of the check
void check(tst &&value) { cout << "rvalue func\n"; }

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  int value = 4;
  int *pVal = &value; // possible because value is lvalue.
  // int *pVal = &7;  // error, 7 is not lvalue, it is rvalue.


  tst test = getTest(); // test is lvalue.
  tst *pTest = &test;
  // tst *pTest2 =&getTest(); // Error, the return values of funcs are rvalues, temporary values.

  int *pVal2 = &++value; // prefix is fine, lvalue.
  cout << " pval2 is: " << *pVal2 << endl;

  // int *pVal3 = &value++; // postfix is not. It creates a temp value, rvalue.
  // int *s = &(7 + value); error, rvalue.

  tst &rTest = test; // This is fine.
  // tst &rTest2 = getTest(); error
  // important rvalue: const lvalue references can be binded by the rvalues.
  // The getTest object will exist beyond the life time of the object.
  const tst &rTest2 = getTest();

  // =====================
  // && means rvalue.
  // tst &&rtest1 = test; error
  tst &&rtest1 = tst();     // but this is fine.
  tst &&rtest2 = getTest(); // but this is fine.

  check(test);      // calls the lvalue of check
  check(tst());     // calls the rvalue of check
  check(getTest()); // calls the rvalue of check

  cout << " \n ends\n";

  return 0;
}
