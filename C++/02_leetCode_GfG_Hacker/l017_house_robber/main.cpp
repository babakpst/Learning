
// Babak Poursartip
// Aug 08/01/2022

// House Robber

#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
 public:
  int rob(vector<int>& nums)
  {
    std::vector<int> money(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
      if (i == 0)
        money[i] = nums[i];
      else if (i == 1)
        money[i] = max(nums[i], nums[i - 1]);
      else
        money[i] = max(money[i - 1], money[i - 2] + nums[i]);
    }

    return money[nums.size() - 1];
  }
};

class Solution
{
 public:
  int rob(vector<int>& nums)
  {
    std::vector<int> money(nums.size(), 0);

    money[0] = nums[0];
    money[1] = max(nums[0], nums[1]);

    for (int i = 0; i < nums.size(); i++) money[i] = max(money[i - 1], money[i - 2] + nums[i]);
    return money[nums.size() - 1];
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // std::vector<int> vec{1,2,3,1};
  std::vector<int> vec{2, 7, 9, 3, 1};

  Solution t;
  std::cout << " output: " << t.rob(vec) << std::endl;

  std::cout << " done. \n";
  return 0;
}
