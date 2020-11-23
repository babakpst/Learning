/*

Babak Poursartip

Reference: Effective C++ by Scott Meyers


- integral types in c++ are: integers, chars, bools

- A definition for anything you use is required in c++, but static, class-specific constants of type integers, bools, or chars (integral types) are an exception. If and only if, you do not take the address of such variables, a declaration, without definition is fine. But if the address is required, a sparate defintion is a must. See the attached code.

*/

#include <iostream>

class test{

private:
  static const int ivar1 = 5; // a declaration, but not definition
  int arr[ivar1];          // using of a static, constant var in class without defintion.

// Uncommenting the following line, results in a compilation error. we cannot initialize non-integral, const varialbes inside a class:
//static const double dvar1 = 1.23; 

public: 
  static const int ivar2 = 6; // a declaration, but not definition
  //static const double dvar2 = 6.2; // constant declaration, but not definition
  static const double dvar3; // a declaration, but not definition
};


// we have to put this here, if we want to take the address of ivar2, otherwise it would be a compilation error.
const int test::ivar2; 
const double test::dvar3=6.2;

// ======================
int main(){

  test obj;
  test *pobj=new test;
  std::cout << pobj->ivar2 << std::endl;
  std::cout << pobj->dvar3 << std::endl;

  const int *pvar = &obj.ivar2; // taking the address of a static, const var

return 0;
}


