#include <algorithm>
#include <iostream>
#include <iterator>
#include <string.h>
struct g {
  g() : n(0) {}
  int operator()() {
    std::cout << n << "\n";
    return n++;
  }
  int n;
};

int main() {
  int a[10];
  g aa;
  // int m = ();
  std::generate(a, a + 10, g());
  std::copy(a, a + 10, std::ostream_iterator<int>(std::cout, " "));
  std::cout << strcmp("strcmp()", "strcmp()") << strcmp("baba", "baba");
}