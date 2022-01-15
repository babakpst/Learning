

/*

Babak Poursartip
01/15/2022

cppcon meta-programming: lvalues/rvalues.

*/


#include <iostream>
#include <vector>
#include <array>

// 1 =============================
template<typename T>
void func1(T& t) // only accepts lvalues
{
  puts(__PRETTY_FUNCTION__);
}

// 2 =============================
/* 
reference collapsing
Combining two reference types (means taking a ref to another ref) mins (min of the two) the number of ampersands between them:

& +& = & lvalue reference to lvalue reference is lvalue reference.
& +&&= & lvalue reference to rvalue reference is lvalue reference.
&&+& = & rvalue reference to lvalue reference is lvalue reference.
&&+&&=&& rvalue reference to rvalue reference is rvalue reference.
*/
//T&& is a forwarding reference (or universal reference).
template<typename T>
void func2(T&& t) // only accepts rvalues
{
  puts(__PRETTY_FUNCTION__);
}

// 3 =============================
// when T&& deduced?
template<typename T>
void func3(void (*t)(T))
{
  puts(__PRETTY_FUNCTION__);
}
void g(int&&){}

// 4 =============================
// type deduction is only valid for function
// It does not working for classes, variables and aliases because there is no parameter to deduce the type. 
template<typename T = void> struct foo{};


// 5 =============================
// function specialization is possible for functions, classes, and variables but not aliases.
template<typename T>
using myvec = std::vector<T>;

//template<> using myvec<void> = void; // error 


// 6 =============================
// partial specialization/ full specialization
// partial specialization is not allowed for functions/alias.
// full specialization is not allowed for alias.
template<typename T>
constexpr bool is_array = false;

// partial specialization
template<typename Tp>
constexpr bool is_array<Tp[]> = true;

// partial specialization: may even have more parameters.
template<typename Tp, int N>
constexpr bool is_array<Tp[N]> = true;

// full specialization
template<>
constexpr bool is_array<void> = true;

// =============================
// =============================
int main()
{
  std::cout << " starts ... \n";

  // 1 =============================
  int i=8; 
  func1(i); // T = int
  //func1(5); // error cannot get rvalues
  
  func1(static_cast<int&>(i)); // [with T = int]
  //func1(static_cast<int&&>(i)); // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
  func1(static_cast<volatile int&>(i)); // [with T = volatile int]
  //func1(static_cast<volatile int&&>(i)); // error: cannot bind non-const lvalue reference of type ‘volatile int&’ to an rvalue of type ‘volatile int’
  func1(static_cast<const int&>(i)); // [with T = const int]
  func1(static_cast<const int&&>(i)); // [with T = const int]  <<<<



  // 2 =============================
  func2(5); //  T = int
  func2(std::move(i)); //  T = int -- std::move, converts lvalues to rvalues

  func2(i); // works but deduces T as int&
            // i is int which is kind of like int&, so we should deduce T such that T&& is int&: T=int&
            
  const int ii = 123;
  func2(ii); // [with T = const int&]
  func2(std::move(ii)); //  T = const int -- std::move, converts lvalues to rvalues

  // 3 =============================
  // when T&& deduced?
  func3(g); // T = int&&

  // 4 =============================
  // type deduction is not working for classes.
  //foo bar; // 
  foo<> bar;
 

  // 5 =============================
  printf("%d \n", is_array<int>); // 0
  printf("%d \n", is_array<int[]>); // 0 
 
  std::cout << " done. \n";
  return 0;
}
