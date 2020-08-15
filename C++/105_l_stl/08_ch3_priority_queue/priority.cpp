
// Babak Poursartip
// 08/15/2020

// priority queue
// keeps the info as a heap
// elements are displayed in descending order

#include <iostream>
#include <queue>

int main() {
  puts(" code starts ...");

  std::priority_queue<int> num;
  int tmp;

  puts(" pushing back: ");
  while (tmp >= 0) {
    std::cin >> tmp;
    if (tmp >= 0)
      num.push(tmp);
  }

  printf(" here is the deque [");
  while (num.size() > 0) {
    printf(" %d ", num.top());
    num.pop();
  }

  puts("]");

  puts(" terminates successfully.");
  return 0;
}