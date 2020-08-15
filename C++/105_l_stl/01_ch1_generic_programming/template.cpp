
// Babak Poursartip
// 08/14/2020

// credit goes to the linkedin course c++ stl

#include <iostream>

template <typename T> int size_in_bits(const T &a) { return sizeof(a) * 8; }

int main() {
  printf(" %d \n", size_in_bits(31));
  printf(" %d \n", size_in_bits('f'));
  printf(" %d \n", size_in_bits(32.1f));
  printf(" %d \n", size_in_bits(32.1));
}