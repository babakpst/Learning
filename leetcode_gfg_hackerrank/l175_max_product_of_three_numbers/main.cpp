/*

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.



Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6


Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int maximumProduct(vector<int>& nums)
  {
    if (nums.size() < 3)
      return -1;
    else if (nums.size() == 3)
      return nums[0] * nums[1] * nums[2];

    int max1 = -1001, max2 = -1001, max3 = -1001;
    int min1 = 1001, min2 = 1001;

    // int max1 =0, max2 = 0, max3 = 0;
    // int min1 =0, min2 = 0, min3 = 0;
    // int maximum = -1001;
    for (auto val : nums)
    {
      // maximum =max(maximum, val);
      if (val > max1)
      {
        max3 = max2;
        max2 = max1;
        max1 = val;
      }
      else if (val > max2)
      {
        max3 = max2;
        max2 = val;
      }
      else if (val > max3)
      {
        max3 = val;
      }

      if (val < min1)
      {
        min2 = min1;
        min1 = val;
      }
      else if (val < min2)
      {
        min2 = val;
      }

      // cout << min1 << " "<< min2<< " "<< max3 << " " << max2 << " "<< max1 << endl;
    }

    // if (maximum < 0) return min1*min2*min3;

    // vector<int> finals{
    // min1*min2*min3,
    // max1*max2*max3,
    // min1*min2*max1
    //};

    // return *max_element(finals.begin(), finals.end());
    return max(min1 * min2 * max1, max3 * max2 * max1);
  }
};

int main()
{
  cout << " starts ..\n";

  // vector<int> vec{1,2,3,4,5,6,2,7};
  vector<int> vec{-100, -98, 3, 4, 5, 6, 2, 8};
  // vector<int> vec{-1,-2,-3};

  Solution obj;
  int out = obj.maximumProduct(vec);
  cout << " results: " << out << endl;

  return 0;
}
