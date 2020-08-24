// Babak Poursartp
// 08/19/2020

// linkedin course: c++ best practice

#include <iostream>
#include <typeinfo>
#include <vector>

int main() {
  puts("code starts ...");

  std::vector<int> a{1, 2, 3, 4};
  std::cout << "a: " << typeid(a).name() << std::endl;
  // auto beta{1, 2, 3}; // error: initializer for variable 'beta' with type
  // 'auto' contains multiple expressions

  auto b = {1, 2, 3, 4}; // ok, but wrong type for b
  std::cout << "b: " << typeid(b).name() << std::endl;

  auto c = std::vector<int>{1, 2, 3, 4}; // ok
  std::cout << "c: " << typeid(c).name() << std::endl;

  // auto d; // always an error

  puts("terminates successfully");
  return 0;
}