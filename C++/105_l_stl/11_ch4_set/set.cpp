
// Babak Poursartip
// 08/15/2020

// deque

#include <iostream>
#include <set>
#include <unordered_set>

int main() {
  puts(" code starts ...");

  // choose the right one.
  // std::set<int> num;
  // std::multiset<int> num;      // accepts duplicates
  // std::unordered_set<int> num;
  std::unordered_multiset<int> num;

  int tmp;

  puts(" insert in the set: ");
  while (tmp >= 0) {
    std::cin >> tmp;
    if (tmp >= 0)
      num.insert(tmp);
  }

  printf("set [");
  for (auto it = num.begin(); it != num.end(); ++it) {
    std::cout << *it << " ";
  }
  puts("]");

  printf(" removing elements from set");
  tmp = 0;
  while (tmp >= 0) {
    printf(" enter a number: ");
    std::cin >> tmp;
    if (tmp >= 0)
      num.erase(tmp);
  }

  printf("set [");
  for (auto it = num.begin(); it != num.end(); ++it) {
    std::cout << *it << " ";
  }
  puts("]");

  puts(" terminates successfully.");
  return 0;
}
