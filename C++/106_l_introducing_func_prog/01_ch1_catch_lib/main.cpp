
// test case assertion

// from linkedin course functional programming
// 08/18/2020
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

// fibonacci
int fib(const int n) {
  // printf(" fib: %d \n", n);
  if (n <= 1)
    return n;
  return (fib(n - 1) + fib(n - 2));
}

TEST_CASE("Fibonacci series", "[fib]") {
  REQUIRE(fib(0) == 0);
  REQUIRE(fib(1) == 1);
  REQUIRE(fib(2) == 1);
  REQUIRE(fib(3) == 2);
  REQUIRE(fib(4) == 3);
  REQUIRE(fib(5) == 5);
  REQUIRE(fib(12) == 144);
}

/*
int main() {

  puts(" code starts ... ");
  int value = 5;
  printf(" fibonacci of %d is: %d \n", value, fib(value));

  puts(" terminates successfully ");
  return 0;
}
*/