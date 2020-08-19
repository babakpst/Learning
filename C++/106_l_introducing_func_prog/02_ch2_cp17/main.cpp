
// linkedin functional programming
// Babak Poursartip

// to run: clang++ -Wall -std=c++17 main.cpp -o main
// this is only valid for c++17

#include <iostream>

// C++ nested namesapce
namespace A::B::C {
int i;
}

int main() {
  puts(" code starts ...");

  A::B::C::i = 45;
  std::cout << "nested name space: " << A::B::C::i << "\n";

  puts(" terminated successfully");
  return 0;
}