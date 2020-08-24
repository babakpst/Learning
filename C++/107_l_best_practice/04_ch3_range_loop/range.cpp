// Babak Poursartp
// 08/19/2020

// linkedin course: c++ best practice
// range loop
#include <iostream>
#include <map>
#include <vector>

int main() {
  puts("code starts ...");

  // iteration over a vector in stl
  std::vector<int> a{1, 2, 3, 4, 5};
  for (auto ii : a) {
    std::cout << "a: " << ii << std::endl;
  }

  for (auto ii : {5, 2, 87, 99, 658, 357}) {
    std::cout << "next: " << ii << std::endl;
  }

  // iteration over standard arrays
  int b[]{2, 5, 8, 9, 5, 1, 4};
  for (auto ii : b) {
    std::cout << "b: " << ii << std::endl;
  }
  // delete[] b; is only used if we use new.

  std::string str{"I am great."};
  for (auto ii : str) {
    std::cout << "string: " << ii << std::endl;
  }

  // iteration over a map in stl
  std::map<int, std::string> m{
      {1, "bob"}, {3, "behnaz"}, {2, "shiva"}, {5, "behrang"}};

  for (auto ii : m) {
    std::cout << "map: " << ii.first << " and: " << ii.second << std::endl;
  }

  puts("terminates successfully");
  return 0;
}