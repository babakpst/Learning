
// Babak Poursartip
// 08/15/2020

// deque

#include <iostream>
#include <queue>

int main() {
  puts(" code starts ...");

  std::queue<int> num;
  int tmp;

  puts(" pushing back: ");
  while (tmp >= 0) {
    std::cin >> tmp;
    if (tmp >= 0)
      num.push(tmp);
  }

  printf(" here is the deque [");
  while (num.size() > 0) {
    printf(" %d ", num.front());
    num.pop();
  }

  puts("]");

  puts(" terminates successfully.");
  return 0;
}