
// Babak Poursartip
// 08/19/2020

// linkedin functional programming

// metaprogramming
// Template metaprogramming (TMP) is a Turing complete, functional programming
// language built-in to C++.

// TMP variables are always immutable.
// TMP does not have loops, so we use recursions
// TMP does not have branching, we use specialization

#include <iostream>
#include <vector>

// generic programming
template <typename T> T cube(const T &val) { return val * val * val; };

// using TMP =====
// toCube is immutable
// no return statement here.
//
template <int toCube> struct Cube {
  enum { value = toCube * toCube * toCube };
};

int main() {
  puts(" code starts ... ");

  std::cout << " 10 cubed:" << cube(10) << std::endl;
  std::cout << " 2 cubed:" << cube(2) << std::endl;

  // this part is done at the compile time.
  std::cout << " 10 cubed:" << Cube<10>::value << std::endl;
  std::cout << " 2 cubed:" << Cube<2>::value << std::endl;

  puts(" \n terminates successfully.");
  return 0;
}