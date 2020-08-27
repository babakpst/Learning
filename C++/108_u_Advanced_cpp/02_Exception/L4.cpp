
// Babak Poursartip
// 08/27/2020

// Exception
// Udemy: Advanced c++

// C++ library has a standard exception class which is base class for all
// standard exceptions. All objects thrown by components of the standard library
// are derived from this class. Therefore, all standard exceptions can be caught
// by catching this type

// See the chart here for the superclasses and subclasses in exception:
// https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
// Also read what command throws what exception

// bad_alloc is a subclass of exception, so bad_alloc fits in exception but not
// the other way arround.

#include <exception>
#include <iostream>

using namespace std;

void wrongFunc() {
  bool error1 = true;
  bool error2 = false;

  if (error1)
    throw bad_alloc();
  if (error2)
    throw exception();
}

int main() {
  puts(" starts \n");
  try {
    wrongFunc();

    // if we put catch exception here, by mistake, it throws exception for both
    // error, because bad_alloc is a subclass of exception.
  } catch (bad_alloc &e) {
    std::cerr << "catching bad_alloc" << e.what() << '\n';
  } catch (const std::exception &e) {
    std::cerr << "catching exception" << e.what() << '\n';
  }

  puts(" \n ends");

  return 0;
}
