
/*

Babak Poursartip
01/08/2022

cppcon meta-programming

*/

#include <iostream>
#include <vector>
#include <array>

// 1 =============================
// A variable template is equivalent to a static data member of a class template.

template <typename T>
const bool is_void_v = true;

template <typename T>
struct is_void {
  static const bool value = true;
};

// 2 =============================
// Alias template
typedef std::vector<int> myvec_int; // c++ 03
using myvec_double = std::vector<double>; // c++ 11

// alias
template<typename T>
using myvec=std::vector<T>; // c++11 syntax

// 3 =============================
using myint = int;

template<typename T>
using myvec = std::vector<T>;

void f1(const myint& mi){};
void f1(const myvec<int>& mv){};

// 4 =============================
template <typename T>
void foo(T x)
{
  puts(__PRETTY_FUNCTION__);
}

// 5 =============================
template<typename T, typename U>
void f1(T x, U y)
{
  puts(__PRETTY_FUNCTION__);
}

template<typename T>
void f2(T x, T y)
{
  puts(__PRETTY_FUNCTION__);
}

// 6 =============================
template<typename T, typename U>
void foo(std::array<T, sizeof(U)> x, std::array<U, sizeof(T)> y, int z)
{
  puts(__PRETTY_FUNCTION__);
} 

// 7 =============================
// Functors: captureless lambda types are always implicity convertible to function pointer type. But being implicity convertible to a thing does not mean actually being that thing. 

// If you absolutely need the function pointer conversion to happen, add a unary +!!!
template<typename R, typename A>
void foo(R (*fptr)(A))
{
puts(__PRETTY_FUNCTION__);
}

// 8 ===========================
template<typename T, typename U>
void add(T x, U y)
{
puts(__PRETTY_FUNCTION__);
}

// 9 ===========================
template<typename T>
void func()
{
puts(__PRETTY_FUNCTION__);
}

// 10 ==========================
// to fix the type deduction for the no argument case, we can define a default parameter
template<typename T=char>
void func2()
{
puts(__PRETTY_FUNCTION__);
}

// =============================
// =============================
int main()
{
  std::cout << " starts ... \n";

  // 1 =============================
  std::cout << " variable template: " << std::boolalpha << is_void_v<int> << "\n";
  std::cout << " class template: " << std::boolalpha << is_void<int>::value << "\n";

  // 2 =============================
  static_assert(std::is_same_v<myvec_int, std::vector<int>>);
  static_assert(std::is_same_v<myvec_double, std::vector<double>>);
  static_assert(std::is_same_v<myvec<float>, std::vector<float>>);  
  //static_assert(std::is_same_v<myvec<float>, std::vector<double>>);  // error.
  
  // 3 =============================
  int i; 
  f1(i); // OK bcs myint is int.
  std::vector<int> v{1,2,3};
  f1(v); // OK bcs myvec<int> is std::vector<int>

  // 4 =============================  
  // type deduction: The type of T in template foo are automatically deducted.
  foo(1);
  foo(1.1);
  foo("Babak");
 
  // 5 =============================
  // type deduction: 
  f1(1, 2);
  f1(1, 2.2);  
  f2(1, 2);

  //f2(1, 2.1); // error no matching
  // two ways to solve this
  // approach 1
  f2(static_cast<double>(1), 2.1);

  // approach 2: the types of 1 and 2.1 is not participating in type deduction anymore. 
  f2<float>(1, 2.1);  

  // 6 =============================
  // type deduction: z does not participate in type deduction
  foo(std::array<int, 8>{}, std::array<double, 4>{}, 0.0); // z(0.0) is not participating in type deduction, x does contribute to deduct type of T, but not U.  
  std::array<int, 8> aa;
  std::array<double, 4> bb;
  foo(aa, bb, 0.0);
  //foo(std::array<int, 9>{}, std::array<double, 4>{}, 0.0);  // error: no matching funciton. 
 
  // 7 ============================= 
  foo( [](double x){return int(x);});
  foo(+[](double x){return int(x);});
 
  // 8 =============================  
  add<int, int>('x', 3.1); // T=int, U=int;
  add<int>('x', 3.1); // T=int, U=double;
  add<>('x', 3.1); // T=char, U=double;
  add('x', 3.1); // T=char, U=double; 
 
  // 9 =============================   
  func<int>();  // T = int;
  //func<>();  // error: could not infer template argument T,
  //func();  // error: could not infer template argument T, 
 
 
  // 10 ==========================
  // to fix the type deduction for the no argument case, we can define a default parameter
  func2<int>();  // T = int;
  func2<>();     // T = char;
  func2();        // T = char;
 
  std::cout << " done. \n";
  return 0;
}
