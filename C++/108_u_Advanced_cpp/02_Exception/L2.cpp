
// Babak Poursartip
// 08/27/2020

// Exception
// Udemy: Advanced c++

// Use Exceptions for things that your program cannot recover from
// After the first throw, nothing will be executed

#include <iostream>
using namespace std;

// =========================================
class canGoWrong {
public:
  canGoWrong() {
    // char *pMemory = new char[100000000000000];
    // we cannot allocate this memory, throws a bad_alloc error
    char *pMemory = new char[100000000000000];
    delete[] pMemory;
  }
};

int main() {
  puts(" starts \n");

  try {
    canGoWrong wrong;
  } catch (bad_alloc &e) {
    cout << "exception: " << e.what() << endl;
  }

  puts(" code is still running");
  puts(" \n ends");

  return 0;
}
