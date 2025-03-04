
/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the
signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


2147483547

*/

#include <climits>
#include <iostream>

class Solution
{
 public:
  int reverse(int x)
  {
    int ret = 0;
    while (x != 0)
    {
      int rem = x % 10;
      x /= 10;
      if (((ret > INT_MAX / 10) || (ret == INT_MAX / 10 && rem > 7)) ||
          ((ret < INT_MIN / 10) || (ret == INT_MIN / 10 && rem < -8)))
        return 0;
      ret = ret * 10 + rem;
      std::cout << ret << std::endl;
    }
    return ret;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;
  // int input = std::numeric_limits<int>::min();
  // int input = std::numeric_limits<int>::max();
  // int input = 2147483647;
  // int input = 1111111117;
  // std::cout << " input: " << input << std::endl;
  // int out = t.reverse(input);

  int out = t.reverse(atoi(argv[1]));

  std::cout << " output: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
