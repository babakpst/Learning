
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int findMin(vector<int>& nums)
  {
    int size = nums.size();
    if (size == 1 || nums[size - 1] > nums[0]) return nums[0];

    int left = 0, right = size - 1;
    while (left + 1 != right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[left])
        left = mid;
      else
        right = mid;
    }
    return nums[right];
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{3,4,5,1,2};
  // vector<int> nums{4,5,6,7,0,1,2};
  vector<int> nums{11, 13, 15, 17};

  Solution t;

  int out = t.findMin(nums);

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
