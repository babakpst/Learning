
// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// elision and optimization
// In C++ computer programming, copy elision refers to a compiler optimization
// technique that eliminates unnecessary copying of objects.

// to see unoptimize compile with this flag:  // not working?
// g++ -std=c++98 ‑fno‑elide‑constructors optimization.cpp -o opt
// g++ optimization.cpp  ‑fno‑elide‑constructors  -o opt

#include <iostream>
#include <vector>

using namespace std;

class test {
public:
  test() { cout << "ctor\n"; }
  test(int i) { cout << " parametrized ctor\n"; }
  test(const test &lhs) { cout << "copy ctor\n"; }
  test &operator=(const test &lhs) {
    cout << "assigment\n";
    return *this;
  }
  ~test() { cout << "dtor\n"; }

  friend ostream &operator<<(ostream &o, const test &lhs);
};

ostream &operator<<(ostream &o, const test &lhs) {
  o << "hi from test";
  return o;
};

test getTest() { return test(); }

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  test tst1 = getTest();
  cout << tst1 << endl;

  vector<test> vec;
  vec.push_back(test());

  cout << " \n ends\n";

  return 0;
}
