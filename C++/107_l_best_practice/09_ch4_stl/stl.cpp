
// Babak Poursartip
// 08/19/2020

// linkedin course: best practice in c++

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  puts(" Code starts ....");

  // a lambda function to print the title
  auto print_header = [](const std::string title) {
    std::cout << "-----" << title << "----- \n";
  };

  auto render = [](const auto &col) {
    for (const auto &val : col)
      std::cout << val << "-";
    std::cout << "\n";
  };

  print_header(" MAP ");

  std::vector<int> inCol{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> outCol;

  std::transform(inCol.begin(), inCol.end(), back_inserter(outCol),
                 [](const int &val) { return 3 * val; });

  render(inCol);
  render(outCol);

  print_header(" FILTER ");
  std::vector<int> filteredCol;
  std::copy_if(inCol.begin(), inCol.end(), back_inserter(filteredCol),
               [](const int &val) { return val % 2 == 0; });
  render(filteredCol);

  print_header(" Accumulate ");
  int reduce =
      std::accumulate(filteredCol.begin(), filteredCol.end(), 0,
                      [](int total, const int x) { return total + x; });
  std::cout << "accumulate: " << reduce << "\n";

  puts(" Terminates successfully");
  return 0;
}