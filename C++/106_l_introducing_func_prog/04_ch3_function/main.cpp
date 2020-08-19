
// Babak Poursartip
// 08/19/2020

// std::function  stores function into a vector
//

// linkedin functional programming
#include <cmath>
#include <functional> // std::function
#include <iostream>
#include <vector>

void demoFunc() { puts(" demoFunc is called"); }
void adder(int a, int b) { printf(" a+b= %d\n", a + b); }
class functor {
public:
  void operator()() const { puts(" functor is called"); }
};

int main() {
  puts(" code starts ... ");

  std::vector<std::function<void()>> funcs;
  funcs.push_back(demoFunc);
  functor functor_instance;

  funcs.push_back(functor_instance);
  funcs.push_back([]() { puts(" anonymous called"); });

  funcs.push_back(std::bind(&adder, 10, 5));

  for (auto &f : funcs) {
    f();
  }

  puts("terminates successfully.");
  return 0;
}