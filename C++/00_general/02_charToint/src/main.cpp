
/*
Babak Poursartip
01 September 2019

*/

#include <iostream>

int main() {

  std::cout << " the code starts ...\n";

  char cvar;
  int ivar;

  cvar = '9';
  ivar = cvar;
  std::cout << " char var: " << cvar << "- int var: " << ivar << "-\n";

  for (int i = 0; i < 10; i++) {
    char cc = (char)i;
    cvar = cc;
    ivar = cvar;
    std::cout << " char var: " << cvar << "- int var: " << ivar << "-\n";
  }
  std::cout << " End of the code.\n";

  return 0;
}
