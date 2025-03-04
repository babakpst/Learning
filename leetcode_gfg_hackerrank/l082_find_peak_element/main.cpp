
// babak poursartip
// Oct 9, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int findPeakElement(vector<int>& nums)
  {
    int size = nums.size();
    int left = 0, right = size - 1;
    while (left < right)
    {
      int mid = left + (right - left) / 2;

      if (nums[mid] > nums[mid + 1])
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{1,2,3,1};
  vector<int> nums{1, 2, 1, 3, 5, 6, 4};

  Solution t;

  int out = t.findPeakElement(nums);

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
