
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> searchRange(vector<int>& nums, int target)
  {
    int size = nums.size();
    vector<int> out{-1, -1};

    if (size == 0) return out;
    if (size == 1 && nums[0] == target)
    {
      out[0] = 0;
      out[1] = 0;
      return out;
    }

    int left = 0, right = size - 1;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;

      // cout << " left: " << left << " " << mid << " " << right << endl;
      if (nums[mid] == target && (mid - 1 >= 0 ? nums[mid - 1] < target : true))
      {
        out[0] = mid;
        break;
      }
      else if (nums[mid] < target)
        left = mid + 1;
      else if (nums[mid] > target)
        right = mid - 1;
      else
        right = mid;
    }
    if (out[0] == -1) return out;

    left = out[0], right = size - 1;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      // cout << " right: " << left << " " << mid << " " << right << endl;

      if (nums[mid] == target && (mid + 1 < size ? nums[mid + 1] > target : true))
      {
        out[1] = mid;
        break;
      }
      else if (nums[mid] < target)
        left = mid + 1;
      else if (nums[mid] > target)
        right = mid - 1;
      else
        left = left == mid ? left + 1 : mid;
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{5,7,7,8,8,10};
  // int target = 8;

  vector<int> nums{7, 7};
  int target = 6;

  // vector<int> nums{5};
  // int target = 5;

  Solution t;

  vector<int> out = t.searchRange(nums, target);

  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
