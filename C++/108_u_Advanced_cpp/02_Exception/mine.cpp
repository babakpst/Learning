
// Babak Poursartip
// 08/27/2020

// Exception
// Udemy: Advanced c++

#include <iostream>
using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Base {};
class Derived : public Base {};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Test {
public:
  Test() { cout << "Constructor of Test " << endl; }
  ~Test() { cout << "Destructor of Test " << endl; }
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Function to find factorial of N and throws error if occurs
void findFactorial(int N) {
  // Initialise variable by 1
  int factorial = 1;

  // Check for errors
  try {
    // If N is less than zero then, it shows errors as factorial of negative
    // number can't be calculated
    if (N < 0) {

      // Exception object which
      // returns the message passed
      // to it
      throw invalid_argument("negative not allowed\n");
    }

    // Find factorial if no error occurs
    for (int i = N; i > 0; i--) {
      factorial *= i;
    }
    cout << "Factorial of " << N << " is " << factorial << endl;
  }

  // Print the error message
  catch (exception &e) {
    cout << e.what();
  }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// C++ compiler doesn’t check enforce a function to list the exceptions that it
// can throw. In Java, it is enforced.

// In C++, a function can specify the list of exceptions that it can throw using
// comma separated list like following.

// Ideally it should have been "int fun() (int)"
int fun() { throw 10; }

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// dynamic exception specifications throw(..., ...)
// dynamic exception specifications are removed in c++17
// if we put throw() we cannot throw any exceptions
void test() throw(int, runtime_error) {
  // throw 10;
  throw runtime_error(" this is runtime error \n");
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main() {
  puts(" starts \n");

  // ========================================================
  puts(" 1====================");
  try {
    throw 10;
  } catch (char *excp) {

    cout << "Caught " << excp;
  } catch (...) { // catch all
    cout << "Default Exception1 \n";
  }

  // ========================================================
  // Implicit type conversion doesn’t happen for primitive types. For example,
  // in the following program ‘a’ is not implicitly converted to int
  puts(" 2====================");
  try {
    throw 'a';
  } catch (int x) {
    cout << "Caught " << x;
  } catch (...) {
    cout << "Default Exception2 \n";
  }

  // ========================================================
  // If we put base class first then the derived class catch block will never be
  // reached. For example, following C++ code prints “Caught Base Exception”
  Derived d;
  puts(" 3====================");
  try {
    throw d;
  } catch (Derived &d) {
    cout << " Derived thrown\n";
  } catch (Base &d) {
    cout << " Derived thrown\n";
  }

  // ========================================================
  // In C++, try-catch blocks can be nested. Also, an exception can be re-thrown
  // using “throw;
  puts(" 4====================");
  try {
    try {
      throw 20;
    } catch (int n) {
      cout << "Handle Partially \n";
      throw; // Re-throwing an exception
    }
  } catch (int n) {
    cout << "Handle remaining \n";
  }

  // ========================================================
  // In C++, try-catch blocks can be nested. Also, an exception can be re-thrown
  // using “throw;
  puts(" 4b====================");
  try {
    try {
      throw 20;
    } catch (int n) {
      cout << "Handle Partially \n";
      // throw 21;            // Re-throwing but a different int
      throw " here it is"; // Re-throwing but a different int
    }
  } catch (int n) {
    cout << "Handle remaining \n";
  } catch (...) {
    cout << "Handle remaining  catch all\n";
  }

  // ========================================================
  // When an exception is thrown, all objects created inside the enclosing try
  // block are destructed before the control is transferred to catch block.
  puts(" 5====================");
  try {
    Test t1;
    throw 10;
  } catch (int i) {
    cout << "Caught " << i << endl;
  }

  // ========================================================
  puts(" 6====================");
  findFactorial(3);
  findFactorial(-1);

  // ========================================================
  puts(" 7====================");
  try {
    fun();
  } catch (int) {
    cout << "Caught \n";
  }

  // ========================================================
  puts(" 8====================");
  try {
    throw 10;
  } catch (int param) {
    cout << "int exception\n";
    // It is compiler error to put catch all block before any other catch. The
    // catch(…) must be the last catch block.
  } catch (...) {
    cout << "default exception\n";
  }

  // ========================================================
  puts(" 9====================");
  int a = 10, b = 0, c;
  try {
    if (b == 0)
      throw runtime_error("divide by zero\n");
    c = a / b;
    cout << " results: " << c << endl;
  } catch (runtime_error &e) {
    cout << "runtime error \n";
    cout << e.what();
  }

  // ========================================================
  puts(" 10====================");
  try {
    test();
  } catch (int &e) {
    std::cerr << "error int" << e << '\n';
  } catch (runtime_error &e) {
    std::cerr << "runtime_error" << e.what() << '\n';
  }

  // ========================================================
  // ========================================================
  // ========================================================
  // ========================================================
  // If an exception is thrown and not caught anywhere, the program terminates
  // abnormally. For example, in the following program, a char is thrown, but
  // there is no catch block to catch a char.
  puts(" END ====================");
  try {
    throw 'a';
  } catch (int x) {
    cout << "Caught ";
  }

  puts(" \n ends");

  return 0;
}
