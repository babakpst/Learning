
// Babak Poursartip
// 08/19/2020

// linkedin functional programming

#include <iostream>

template <int n> struct fibonacci {
  enum { value = fibonacci<n - 1>::value + fibonacci<n - 2>::value };
};

template <> struct fibonacci<0> {
  enum { value = 0 };
};

template <> struct fibonacci<1> {
  enum { value = 1 };
};

int main() {
  puts(" code starts ... ");

  std::cout << " fib(5) = " << fibonacci<5>::value << std::endl;
  std::cout << " fib(10) = " << fibonacci<10>::value << std::endl;

  puts(" \n terminates successfully.");
  return 0;
}