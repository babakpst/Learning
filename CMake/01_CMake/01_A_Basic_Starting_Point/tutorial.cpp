// A simple program that computes the square root of a number
#include <cmath>
//#include <cstdlib>
#include <iostream>
#include <string>

#include "TutorialConfig.h"

int main(int argc, char* argv[])
{

  std::cout << " calculate the square root of a number. Enter a number with the executable\n";

  if (argc < 2) {
    std::cout << argv[0] << " VERSION " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  //const double inputValue = atof(argv[1]);
  const double inputValue = std::stod(argv[1]);

  // calculate square root
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;
  return 0;
}
