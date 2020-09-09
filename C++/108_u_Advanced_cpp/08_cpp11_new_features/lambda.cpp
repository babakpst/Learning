

// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// lambda

#include <iostream>

using namespace std;

// function pointer: void (*pFunc)()
void test(void (*pFunc)()) { pFunc(); }
void test2(int (*pFunc)()) {
  int here = pFunc();
  cout << here << endl;
}

//====================================================
void testGreet(void (*greet)(string)) { greet("shiva"); }

//====================================================
void runDivide(double (*divide)(double, double)) {
  double val = divide(4.2, 3.1);
  cout << val << endl;
}

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1---------------------\n";

  // bracket party
  []() {}(); // does nothing but valid.
  []() { cout << "lambda func\n"; }();

  auto func = []() { cout << "lambda func\n"; };
  func();

  test(func);
  test([]() { cout << "lambda func\n"; });
  test2([]() {
    cout << "lambda2 func\n";
    return 2;
  });

  cout << "\n2-----------------\n";
  auto pGreet = [](string name) { cout << "Hello, " << name << endl; };
  pGreet("Bob");
  testGreet(pGreet);

  cout << "\n3-----------------\n";
  // trailing return type syntax: ->
  auto pDivide = [](double a, double b) -> double {
    if (b == 0.0)
      return 0;
    return a / b;
  };

  cout << pDivide(4.2, 2.0) << endl;
  cout << pDivide(4.2, 0.0) << endl;

  runDivide(pDivide);

  cout << "\n4-----------------\n";
  int one = 1, two = 2, three = 3;

  // capture one and two by value
  [one, two]() { cout << "Hello, " << one << endl; }();

  // capture all by value
  [=]() { cout << "Hello, " << one << endl; }();

  // capture all by value, but three by reference
  [=, &three]() {
    three = 7;
    cout << "Hello, " << one << endl;
  }();
  cout << three << endl;

  // capture all by referencce
  [&]() {
    three = 30;
    cout << "Hello, " << one << endl;
  }();
  cout << three << endl;

  // capture all by referencce, but two by value
  [&, two]() {
    // two = 30; // error immutable
    one = 10;
    cout << "Hello, " << one << endl;
  }();
  cout << one << endl;

  cout << " \n ends";

  return 0;
}
