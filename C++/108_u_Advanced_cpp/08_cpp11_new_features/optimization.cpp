
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
#include <memory.h>
#include <vector>

using namespace std;

class test {
private:
  int *_pBuffer;
  static const int SIZE = 100;

public:
  test() {
    cout << "ctor\n";
    //_pBuffer = new int[SIZE];

    // There are three ways to allocate this equal to zero:
    // 1- memset prone to mistake, you make override other parts of memory if
    // you set the wrong size.
    // memset(_pBuffer, 0, sizeof(int));
    // 2- putting () at the end:  _pBuffer = new int[SIZE]();
    // 3- putting {} at the end:
    _pBuffer = new int[SIZE]{};
  }
  test(int i) {
    cout << " parametrized ctor\n";
    _pBuffer = new int[SIZE]{};
    for (int i = 0; i < SIZE; i++) {
      _pBuffer[i] = 7 * i;
    }
  }
  test(const test &lhs) {
    cout << "copy ctor\n";
    _pBuffer = new int[SIZE]{};
    memcpy(_pBuffer, lhs._pBuffer, SIZE * sizeof(int));
  }
  test &operator=(const test &lhs) {
    cout << "assigment\n";

    _pBuffer = new int[SIZE]{};
    memcpy(_pBuffer, lhs._pBuffer, SIZE * sizeof(int));

    return *this;
  }
  ~test() {
    delete[] _pBuffer;
    cout << "dtor\n";
  }

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
