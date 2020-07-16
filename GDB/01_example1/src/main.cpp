
/*
Babak Poursartip
25 August 2019
14 July 2020

check the "gdb (GNU DEBUGGER)"

 */

#include <iostream>
#include <sstream>

struct check {
  int ivar1, ivar2;
  float fvar1, fvar2;
};

int mult(const int x, const int length) {
  int results = x * length;
  return results;
}

int main() {

  std::cout << " the code starts ...\n";

  int x = 3;
  int y, z;
  puts("\n start... ");
  std::cout << " The value of x is: " << x << "\n";

  int length = -12;
  std::cout << " Here is the length: " << length << "\n";

  std::cout << " Multiplication: " << mult(x, length) << "\n";

  for (int i = 0; i < 5; ++i) {
    y = (x + 1) * i;
    z = y * 4;
  }

  std::cout << " z is: " << z << "\n";
  std::cout << " The division is: " << length / x << "\n";

  // =============================================================================
  puts(" pointer ");
  int *ipnt1 = &y;
  ipnt1 = &x;

  int *ipnt2 = &y;
  *ipnt2 = 4;

  printf("pointer1 %d \n", *ipnt1);
  printf("pointer2 %d \n", *ipnt2);

  // =============================================================================
  puts("\n  struct ");
  check ck2;
  ck2.ivar1 = 10;
  ck2.ivar2 = 12;
  printf("check2 %d, %d \n", ck2.ivar1, ck2.ivar2);

  // =============================================================================
  puts("\n pointer to struct ");
  check ck, *pck = &ck;
  pck->ivar1 = 456;
  pck->ivar2 = 789;
  printf("check %d, %d \n", pck->ivar1, pck->ivar2);

  std::cout << " Terminates successfully. "
            << "\n";
  return 0;
}
