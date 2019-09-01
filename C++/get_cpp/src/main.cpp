
/*
Babak Poursartip
31 August 2019

check exit command.

 */

#include <fstream>
#include <iostream>
//#include <string>

int main() {

  std::cout << " the code starts ...\n";

  std::ifstream inputfile("input.txt");

  char xin[4];
  inputfile.get(xin[0]);
  inputfile.get(xin[1]);
  inputfile.get(xin[2]);

  std::cout << " The value of x is: " << xin[0] << " " << xin[1] << " "
            << xin[3] << " "
            << "\n";

  if (xin[2] == '\n')
    std::cout << "This char is end of the line.\n";

  inputfile.get(xin[0]);
  inputfile.get(xin[1]);
  inputfile.get(xin[2]);

  std::cout << " The value of x is: " << xin[0] << " " << xin[1] << " "
            << xin[2] << " "
            << "\n";

  if (xin[2] == '\n')
    std::cout << "This char is end of the line.\n";

  inputfile.close();

  std::cout << " End of the code.\n";

  return 0;
}
