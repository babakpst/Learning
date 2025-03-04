

// Babak Poursartip
// Aug 4, 2022

/*
Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.



Example 1:

Input: nums = [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the maximum number of consecutive 1s. After flipping, the maximum number of
consecutive 1s is 4. Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 4


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int findMaxConsecutiveOnes(vector<int>& nums)
  {
    int len1 = 0;
    int len2 = 0;
    int countZeros = 0;
    int max = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 1)
      {
        len1++;
        len2++;
      }
      else if (nums[i] == 0)
      {
        countZeros++;
        if (countZeros % 2 == 1)  // odd zeros
        {
          len1++;
          len2 = 0;
        }
        else
        {
          len1 = 0;
          len2++;
        }
      }
      if (max < len1) max = len1;
      if (max < len2) max = len2;
      // std::cout << " num: " << nums[i] << " len1: " << len1 << " len2: " << len2 << " max: " << max << " zeros: " <<
      // countZeros << std::endl;
    }
    return max;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
  // std::vector<int> vec{1,0,1,1,0,1}; // 4
  // std::vector<int> vec{1,0,1,1,0}; //4
  // std::vector<int> vec{0,1}; // 2
  // std::vector<int> vec{1,0,1}; // 3
  // std::vector<int> vec{1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1}; // 18
  std::vector<int> vec{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1};  //  12

  Solution t;

  int out = t.findMaxConsecutiveOnes(vec);

  std::cout << " answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
