
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
int factorial_compute(const int val, const int sum = 1) {
  if (val > 1)
    return factorial_compute(val - 1, sum * val);
  return sum;
};

// using TMP =====
// toCube is immutable
// no return statement here.
// no branching logic
template <int val, int sum = 1>
struct Factorial : Factorial<val - 1, val * sum> {};
template <int sum> struct Factorial<1, sum> {
  enum { value = sum };
};

int main() {
  puts(" code starts ... ");

  std::cout << "5! = " << factorial_compute(5) << std::endl;

  // this part is done at the compile time.
  std::cout << " 5! = " << Factorial<5>::value << std::endl;

  puts(" \n terminates successfully.");
  return 0;
}