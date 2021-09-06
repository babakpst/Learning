
#include <iostream>
#include <cmath>

/*
Babak Poursartip
Sep 6, 2021

detects whether a number is prime at the compile time.

based on: Discovering modern c++: page 224

*/

constexpr bool is_prime(int i)
{
  if (i==1)
    return false;
  if (i % 2 == 0)
    return i == 2;

  int limit =static_cast<int>( sqrt(i) ) + 1;
  //int limit = sqrt(i) + 1;
  for(int j = 3; j < limit; j+=2)
    if (i % j == 0)
      return false;
  return true;
}

int main()
{
  std::cout << " starts ...\n";

  static_assert(is_prime(13)," is not a prime number.");
  static_assert(is_prime(12)," is not a prime number.");


  std::cout << " ends\n";
  return 0;
}
