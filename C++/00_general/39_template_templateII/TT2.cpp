/*
Babak Poursartip
12/24/2021

topic: template template argument

*/
#include <iostream>
#include <typeinfo>

template <typename T> 
struct Foo {
  T t;
};

//The following line is an error: 
// The template type parameter X is not a template parameter to the outermost template: it is a template parameter to the innermost template. 
//template <template <class X> class T>
template <template <class> class T, typename X>
struct Bar {
  T<X> data;
};

int main()
{
  //Bar<Foo<int>> a;
  Bar<Foo,int> a;
  std::cout << typeid(a.data.t).name() << std::endl;

  Bar<Foo,float> b;
  std::cout << typeid(b.data.t).name() << std::endl;

}
