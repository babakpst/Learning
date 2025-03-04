
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int search(vector<int>& nums, int target)
  {
    int size = nums.size();
    if (size == 1 && nums[0] == target) return 0;
    int left = 0, right = size - 1, mid;
    while (left <= right)
    {
      mid = (left + right) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else if (nums[mid] > target)
        right = mid - 1;
    }
    return -1;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<int> nums{-1, 0, 3, 5, 9, 12};
  int target = 9;
  // int target = -2;

  // vector<int> nums{-1};
  // int target = -1;

  // vector<int> nums{2,5};
  // int target = 5;

  Solution t;

  int out = t.search(nums, target);
  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
