
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> plusOne(vector<int>& digits)
  {
    bool con = true;
    int index = digits.size() - 1;
    int inc = 1;
    while (con)
    {
      int num = digits[index] + inc;
      if (num < 10)
      {
        digits[index] = num;
        con = false;
      }
      else
      {
        digits[index] = num - 10;
        index--;
        if (index < 0)
        {
          digits.push_back(digits[digits.size() - 1]);
          for (int i = 0; i < digits.size() - 1; i++)
          {
            digits[i + 1] = digits[i];
          }
          digits[0] = 1;
          con = false;
        }
      }
    }
    return digits;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // std::vector<int> digits {1,2,3};
  // std::vector<int> digits {4,3,2,1};
  // std::vector<int> digits{9};
  std::vector<int> digits{9, 9};

  Solution t;
  std::vector<int> out = t.plusOne(digits);

  std::cout << "output: \n";
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  std::cout << "\n";

  std::cout << " done \n";
  return 0;
}
