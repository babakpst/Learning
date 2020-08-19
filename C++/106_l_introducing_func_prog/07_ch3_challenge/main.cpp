
// Babak Poursartip
// 08/19/2020

// lambda challenge

// linkedin functional programming
auto incrementBy = [](int initial) {
  auto init = initial;
  return [init](int addBy) mutable {
    init += addBy;
    return init;
  };
};

auto incrementBy2 = [](int initial, int addBy) {
  auto init = initial;
  return [init, addBy]() mutable {
    init += addBy;
    return init;
  };
};

#include <iostream>

int main() {
  puts(" code starts ... ");

  auto myInc = incrementBy(100);
  std::cout << "myInc " << myInc(5) << std::endl;
  std::cout << "myInc " << myInc(6) << std::endl;
  std::cout << "myInc " << myInc(7) << std::endl;
  std::cout << "myInc " << myInc(8) << std::endl;

  auto myInc2 = incrementBy2(100, 5);
  std::cout << "myInc2 " << myInc2() << std::endl;
  std::cout << "myInc2 " << myInc2() << std::endl;
  std::cout << "myInc2 " << myInc2() << std::endl;
  std::cout << "myInc2 " << myInc2() << std::endl;

  puts(" \n terminates successfully.");
  return 0;
}