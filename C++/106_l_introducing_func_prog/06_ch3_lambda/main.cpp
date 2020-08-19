
// Babak Poursartip
// 08/19/2020

// lambda

// linkedin functional programming
auto incrementer = []() {
  auto increment = 0;
  return [increment]() mutable { return ++increment; };
};

int inc() {
  static int i = 0;
  return ++i;
}

//#include <functional> // std::function
#include <iostream>

int main() {
  puts(" code starts ... ");

  auto myInc = incrementer();
  std::cout << "myInc " << myInc() << std::endl;
  std::cout << "myInc " << myInc() << std::endl;
  std::cout << "myInc " << myInc() << std::endl;
  std::cout << "myInc " << myInc() << std::endl;
  std::cout << "myInc " << myInc() << std::endl;

  puts("\n bob's inc ======");
  std::cout << "bobInc " << inc() << std::endl;
  std::cout << "bobInc " << inc() << std::endl;
  std::cout << "bobInc " << inc() << std::endl;
  std::cout << "bobInc " << inc() << std::endl;
  std::cout << "bobInc " << inc() << std::endl;

  puts(" \n terminates successfully.");
  return 0;
}