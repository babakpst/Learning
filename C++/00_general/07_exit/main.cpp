
/*
Babak Poursartip
31 August 2019

check exit command.

 */

#include <assert.h>
#include <iostream>

int main() {

  std::cout << " the code starts ...\n";

  int x = 10;

  std::cout << " The value of x is: " << x << "\n";
  if (x == 0)
    exit(100);

  int length = -12;
  std::cout << " Here is the length: " << length << "\n";
  exit(200);

  std::cout << " some text after ther exit command.\n";

  return 0;
}
