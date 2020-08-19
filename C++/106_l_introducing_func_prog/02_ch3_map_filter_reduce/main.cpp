
// linkedin functional programming
// Babak Poursartip

// to run: clang++ -Wall -std=c++17 main.cpp -o main
// this is only valid for c++17

#include <algorithm>
#include <iostream>
#include <vector>
//#include <numeric>

int main() {
  puts(" code starts ...");

  // lambda function
  auto render = [](auto collection) {
    for (const auto &val : collection)
      std::cout << val << "\n";
  };

  std::vector<int> inCol{10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  std::vector<int> outCol;

  std::transform(inCol.begin(), inCol.end(), back_inserter(outCol),
                 [](const int &value) { return value * 3; });
  std::cout << " Transform: "
            << "std::endl";

  render(outCol);

  puts(" terminated successfully");
  return 0;
}