
// Babak Poursartip
// 08/31/2020

// passing function to function
// Udemy: Advanced c++

#include <iostream>

using namespace std;

void test() { cout << "hello\n"; }

int testFunc(int val) {
  cout << "hello" << val << endl;
  return 2 * val;
}

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";
  test();

  // This is a suitable pointer to point to Test, which returns void and has not
  // parameter
  void (*pTest)();
  pTest = &test; // setting the pointer to the test function.
  // This is how to call the func test() using the pointer.
  (*pTest)();

  void (*pTest2)() = test;
  pTest();

  cout << "\n2-----\n";
  int (*pTestFunc)(int) = testFunc;
  int out = pTestFunc(8);
  cout << "output is: " << out << endl;

  puts(" \n ends");

  return 0;
}
