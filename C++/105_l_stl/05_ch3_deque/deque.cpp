
// Babak Poursartip
// 08/15/2020

// deque

#include <deque>
#include <iostream>

int main() {
  puts(" code starts ...");

  std::deque<int> num;
  int tmp;

  puts(" pushing back: ");
  while (tmp >= 0) {
    std::cin >> tmp;
    if (tmp >= 0)
      num.push_back(tmp);
  }

  std::deque<int>::iterator it;
  printf(" here is the deque [");
  for (it = num.begin(); it != num.end(); ++it)
    printf(" %d ", *it);

  puts("]");

  puts(" pushing front: ");
  tmp = 0;
  while (tmp >= 0) {
    std::cin >> tmp;
    if (tmp >= 0)
      num.push_front(tmp);
  }

  printf(" here is the deque [");
  for (it = num.begin(); it != num.end(); ++it)
    printf(" %d ", *it);

  puts("]");

  puts(" terminates successfully.");
  return 0;
}