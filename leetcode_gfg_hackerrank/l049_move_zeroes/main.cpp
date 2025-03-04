
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution0
{
 public:
  void moveZeroes(vector<int>& nums)
  {
    int index = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
      while (nums[i] == 0)
      {
        i++;
      }
      if (i < size && index + 1 < size) nums[index++] = nums[i];
    }
    for (; index < size; index++) nums[index] = 0;
  }
};

class Solution1
{
 public:
  void moveZeroes(vector<int>& nums)
  {
    int index = 0, i = 0;
    while (i < nums.size())
      if (nums[i] == 0)
        i++;
      else
        nums[index++] = nums[i++];
    for (; index < nums.size(); index++) nums[index] = 0;
  }
};

class Solution2
{
 public:
  void moveZeroes(vector<int>& nums)
  {
    for (int i = 0, index = 0; i < nums.size(); i++, index++)
    {
      while (i < nums.size() && nums[i] == 0) i++;
      if (i < nums.size())
        nums[index] = nums[i];
      else
        nums[index] = 0;
    }
  }
};

class Solution
{
 public:
  void moveZeroes(vector<int>& nums)
  {
    for (int index = 0, i = 0; index < nums.size(); index++, i++)
    {
      while (i < nums.size() && nums[i] == 0) i++;
      if (i < nums.size())
        nums[index] = nums[i];
      else
        nums[index] = 0;
    }
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{0,1,0,3,12};
  vector<int> nums{0, 1, 0, 3, 12, 0};
  // vector<int> nums{0};
  // vector<int> nums{0,0,0};
  // vector<int> nums{};

  Solution t;

  t.moveZeroes(nums);

  cout << " answer: " << endl;
  for_each(nums.begin(), nums.end(), [](auto x) { cout << x << " "; });
  cout << endl;
  std::cout << " done \n";
  return 0;
}
