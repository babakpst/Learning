
// Babak Poursartip
// 08/19/2020

// lambda

// linkedin functional programming

//#include <functional> // std::function
#include <iostream>

auto addCurry = [](auto a) {
  return [a](auto b) { return [a, b](auto c) { return a + b + c; }; };
};

int main() {
  puts(" code starts ... ");

  // goes to the addCurrey function & returns another func: return [a](auto b)
  auto added1 = addCurry(1000);

  // goes to [a](auto b) function & returns another func: return [a, b](auto c)
  auto added2 = added1(100);

  // goes to [a, b](auto c) function & returns another func: return a + b+ c;
  auto addResults = added2(10);

  std::cout << " results: " << addResults << std::endl;

  auto allAtOnce = addCurry(1000)(100)(10);

  std::cout << " results: " << allAtOnce << std::endl;

  puts(" \n terminates successfully.");
  return 0;
}