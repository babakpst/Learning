
// linkedin functional programming
// Babak Poursartip

// to run: clang++ -Wall -std=c++17 main.cpp -o main
// this is only valid for c++17

#include <algorithm>
#include <iostream>
#include <numeric> // for std::accumulate
#include <vector>

int main() {
  puts(" code starts ...");

  // lambda function to print a vector
  auto render = [](auto collection) {
    for (const auto &val : collection)
      std::cout << val << "\n";
  };

  std::vector<int> inCol{10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  std::vector<int> outCol;

  // transform
  std::transform(inCol.begin(), inCol.end(), back_inserter(outCol),
                 [](const int &value) { return value * 3; });
  std::cout << " Transform: "
            << "std::endl";
  render(outCol);

  // copy_if
  std::vector<int> filteredCol;
  copy_if(outCol.begin(), outCol.end(), back_inserter(filteredCol),
          [](int &x) { return x % 2 != 0; });

  puts("copy_if output");
  render(filteredCol);

  // accumulate, the third item is the initialization value for total
  int results =
      std::accumulate(filteredCol.begin(), filteredCol.end(), 0,
                      [](int total, int current) { return total + current; });

  printf("  accumulate %d \n", results);

  puts(" terminated successfully");
  return 0;
}