
// Babak Poursartip
// 08/15/2020

// deque

#include <iostream>
#include <stack>

int main() {
  puts(" code starts ...");

  std::stack<int> num;
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

  fputs(" terminates successfully.");
  return 0;
}