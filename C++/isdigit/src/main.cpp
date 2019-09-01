
/*
Babak Poursartip
31 August 2019

check exit command.

 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <stdio.h>
#include <string>

int main() {

  std::cout << " the code starts ...\n";

  std::string x[2];
  x[0] = 'y';
  x[1] = '5';

  char xx[2];
  xx[0] = 'y';
  xx[1] = '5';

  std::cout << " The value of x is: " << x[0] << " and " << x[1] << "\n";

  std::regex e("\\d");

  if (std::regex_match(x[1], e))
    std::cout << "This is a numerical char. \n";
  else
    std::cout << "This is NOT a numerical char. \n";

  if (std::isdigit(xx[1]))
    std::cout << "This is a numerical char. \n";
  else
    std::cout << "This is NOT a numerical char. \n";

  std::cout << " End of the code.\n";

  return 0;
}
