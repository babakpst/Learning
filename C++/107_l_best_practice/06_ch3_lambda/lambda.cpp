#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

enum class BattleCondition {
  red, yellow, green
};

void print_it(const int &n) {
  std::cout << "-" << n;
}

int main() {

  std::vector<int> nums{3, 4, 2, 8, 15, 267};

  std::for_each(nums.begin(), nums.end(), std::bind(&print_it, std::placeholders::_1));
  std::cout << std::endl;

  std::for_each(nums.begin(), nums.end(), [](const int &n) { std::cout << "-" << n; });
  std::cout << std::endl;

  auto myLambda = [](const int &n) { std::cout << "*" << n; };
  std::for_each(nums.begin(), nums.end(), myLambda);
  std::cout << std::endl;

  auto currentLight = BattleCondition::green;
  const auto shieldLevel = [&]() {
    switch (currentLight) {
      case BattleCondition::green:
        return 50;
      case BattleCondition::yellow:
        return 700;
      case BattleCondition::red:
      default:
        return 1000;
    }
  }();  // important: by puting () here, we can eliminate () from shieldLevel() on the next line
  std::cout << "Current Shield Level = " << shieldLevel << std::endl;
  return 0;
}
