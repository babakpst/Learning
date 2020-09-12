
// Babak Poursartip
// 09/11/2020

// Udemy: Advanced c++
// bind

#include <functional>
#include <iostream>

using namespace std;
using namespace placeholders;

//====================================================
int add(int a, int b, int c) {
  cout << a << ", " << b << ", " << c << endl;
  return a + b + c;
}

//====================================================
// this means that run accepts a function the accepts two int args and returns
// an int.
int run(function<int(int, int)> func) { return func(7, 17); }

//====================================================
class Test {
public:
  int add(int a, int b, int c) {
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
  }
};

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  cout << add(1, 2, 3) << endl;

  // in the old c++ we should have & before the name of func, but in C++11 not.
  // auto calculator = bind(&add, 3, 4, 5);
  auto calculator = bind(add, 3, 4, 5);
  cout << " cal: \n" << calculator() << endl;

  auto calculator2 = bind(add, _1, _2, _3);
  cout << " cal2: \n" << calculator2(10, 20, 30) << endl;

  // changing the order of placeholders

  auto calculator3 = bind(add, _2, _1, _3); // output 20 10 30
  cout << " cal3: \n" << calculator3(10, 20, 30) << endl;

  // setting the second argument to 100, always, _2 means take the second arg of
  // the callee function and put it in a.
  //               int add(int a, int b, int c) {
  //                           /\   /\    /\
  //                           |    |     |
  auto calculator4 = bind(add, _2, 100, _1); // output: 20 100 10
  cout << " cal4: \n" << calculator4(10, 20) << endl;

  cout << "\n2 function -----\n";
  cout << run(calculator4) << endl;

  cout << "\n3 class -----\n";
  Test test;

  // & is obligatory
  auto calculator5 = bind(&Test::add, test, _2, 100, _1);

  cout << " cal5: \n" << calculator5(10, 20) << endl;
  cout << " \n ends\n";

  return 0;
}
