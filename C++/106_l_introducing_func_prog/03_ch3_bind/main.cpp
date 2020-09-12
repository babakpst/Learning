
// Babak Poursartip
// 08/19/2020

// bind:
// manipulate a func and its parameters
// reorder the functions' argument
// bind values to arguments

// linkedin functional programming
#include <algorithm>
#include <cmath>
#include <functional> // std::bind
#include <iostream>
#include <vector>

auto greater(int x, int y) { return x >= y; }

int main() {
  puts(" code starts ... ");

  std::vector<int> ages{12, 15, 36, 25, 14, 78, 52, 15};

  int over21 = 0;
  for (int i : ages) {
    if (i >= 21)
      ++over21;
  }
  printf(" total number over 21: %d \n", over21);

  // ==============  count_if
  auto num_over21 = std::count_if(ages.begin(), ages.end(),
                                  [](const int &x) { return x > 21; });
  printf(" count_if: total number over 21: %ld \n", num_over21);

  // ==============  count_if with bind
  num_over21 = std::count_if(ages.begin(), ages.end(),
                             std::bind(&greater, std::placeholders::_1, 21));
  printf(" count_if w bind: total number over 21: %ld \n", num_over21);

  // ==============
  std::vector<int>::iterator itr;
  itr = find_if(ages.begin(), ages.end(), [](int x) { return x > 21; });
  std::cout << std::endl << " greater than 21: " << *itr << std::endl;

  puts("terminates successfully.");
  return 0;
}
