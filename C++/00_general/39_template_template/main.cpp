
/*

Babak Poursartip

11/16/2021

*/

#include <iostream>

template <typename T>
struct Base
{
    using value_type = T;
    void baseMethod()
    {
        std::cout << "Base<T>::f()\n";
    }
};

// ==================================
template <typename T>
struct Derived : Base<T>
{

   //value_type val = 10; //(1) ERROR: 'value_type' is not declared in the scope
   //Base<T>::value_type val = 10; //(2)ERROR: need 'typename' before 'Base<T>::value_type' because  'Base<T>' is a dependent scope
   typename Base<T>::value_type val = 10; //(3) Works

    void derivedMethod()
    {
        std::cout << "Derived<T>::g()\n  ";

        /**
         * ERROR: Dependent Name (as there is no baseMethod() in derived class): Call to baseMethod() depends
         * on Base class template hence compiler is not aware of baseMethod().
         */
        //baseMethod(); ^^
        Base<T>::baseMethod();
        f(); // Non dependent Name: hence no issues here
    }
    void f(){}
};


//==================================
int main()
{
  std::cout << " starts ... \n";
  Derived<int> d{};
  d.derivedMethod();

  std::cout << " end.  \n";
  return EXIT_SUCCESS;
}


/* ERROR
test.pp.cpp: In member function 'void Derived<T>::derivedMethod()':
test.pp.cpp:21:20: error: there are no arguments to 'baseMethod' that depend on a template parameter, so a declaration of 'baseMethod' must be available [-fpermissive]
         baseMethod();
                    ^
test.pp.cpp:21:20: note: (if you use '-fpermissive', G++ will accept your code, but allowing the use of an undeclared name is deprecated)
*/


