/*
Babak Poursartip
05/02/2020

Linkedin: advanced topics in cpp

chapter 1: Explicit constructor

important note:
To avoid that we need to put explicit in front of the name of the class
constructor.

*/

#include <iostream>

// =======================
class c1 {
  int _value = 0;
  c1(); // prevents the compiler to call the private constructor

public:
  c1(const int &value) : _value(value) {}
  //if we use an explicit ctor, no implicit conversion occurs
  //uncommenting this explicit ctor, generates an error.
  //explicit c1(const int &value) : _value(value) {} 
  void setvalue(const int &value) { _value = value; }
  int getvalue() const { return _value; }
};

// =======================
// It converts the x to a number, and since the ctor of c1 accepts an int, then 
// uses the int to construct the class in the function.
void func(const c1 &o) { 
    std::cout << " value is: " << o.getvalue() << std::endl; 
}

// =======================
int main() {
  std::cout << " program starts ... \n\n";
  // c1 x; // error because it cannot call the private constructor
  // this type of calling the constructor is only possible if you have a
  // constructor with only one argument.


  // - This is implicit conversion. converts the ASCII value to a number.
  // - Here, it converts x to 120;
  // - To avoid this implicit conversion, we need to put explicit in front of 
  // the name of the class constructor.
  c1 o = 'x';
  std::cout << " value is: " << o.getvalue() << std::endl;

  // another implicit conversion
  func('x');

 
  // create a class directly by an int
  c1 obj2(5);
  std::cout << " class: " << obj2.getvalue() << std::endl;

  c1 obj3=6;
  std::cout << " class: " << obj3.getvalue() << std::endl;

  std::cout <<  " \n program ends! \n";
  return 0;
}
