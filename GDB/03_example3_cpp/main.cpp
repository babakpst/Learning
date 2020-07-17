/*
! Babak Poursartip
! 07/16/2020

! check the gdb with a fortran code.
*/

#include <sstream>

int sum_factors(const int n) {

  int sum_fac = 0;

  for (int i = 1; i <= n; ++i) {
    if ((n % i) == 0) {
      sum_fac += i;
    }
  }

  return sum_fac;
}

// =============================================================================
// =============================================================================
int main() {

  int n = 60;
  int sum_fac;

  puts(" code starts ...");

  sum_fac = sum_factors(n);

  printf(" sum of factor of %d is: %d \n", n, sum_fac);

  puts(" end of the code.");
  return 0;
}
