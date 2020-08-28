
// Babak Poursartip
// 08/27/2020

// Exception
// Udemy: Advanced c++
// It is recommended to catcg objects that are derived from exception library
// rather than the built-in objects

#include <exception>
#include <iostream>
using namespace std;

class MyException : public exception {

public:
  // override the what function
  virtual const char *what() const throw() { return "sth bad happpened"; }
};

class Test {
public:
  void wentWrong() { throw MyException(); }
};

int main() {
  puts(" starts \n");
  Test test;
  try {
    test.wentWrong();
  } catch (MyException &e) {
    cout << " overridden exception: " << e.what() << endl;
  }

  puts(" \n ends");

  return 0;
}
