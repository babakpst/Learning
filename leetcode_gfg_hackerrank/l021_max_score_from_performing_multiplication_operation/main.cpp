

// Babak Poursartip
// Aug 4, 2022

/*
You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are
1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.



Example 1:

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
Example 2:

Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score.
The total score is 50 + 15 - 9 + 4 + 42 = 102.


Constraints:

n == nums.length
m == multipliers.length
1 <= m <= 103
m <= n <= 105
-1000 <= nums[i], multipliers[i] <= 1000
*/

#include <iostream>
#include <vector>

using namespace std;

// top-down
class Solution1
{
 public:
  vector<int> score;

  int scores(int i, int left)
  {
    if (i == m) return 0;

    int right = n - 1
  }

  int maximumScore(vector<int>& nums, vector<int>& multipliers)
  {
    int m = multipliers.size();
    int n = nums.size();
    score.resize((m + 1) * (m + 1));
    return scores(0, 0)
  }
};

// bottom-up
class Solution1
{
 public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers)
  {
    // edge case
    if (multipliers.size() == 1) return max(multipliers[0] * nums[0], multipliers[0] * nums[nums.size() - 1]);

    int m = multipliers.size();  // number of operations
    int n = nums.size();         // number of elements
    std::vector<int> score((m + 1) * (m + 1));
    // base case

    // recurssion
    for (int i = m - 1; i >= 0; i--)
    {
      for (int left = i; left >= 0; left--)
      {
        int mult = multipliers[i];
        int right = n - 1 - (i - left);
        score[left * (m + 1) + i] = max(mult * nums[left] + score[i + 1 + (left + 1) * (m + 1)],
                                        mult * nums[right] + score[i + 1 + left * (m + 1)]);
      }
    }

    return score[0];
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  std::vector<int> nums{-5, -3, -3, -2, 7, 1};
  std::vector<int> multipliers{-10, -5, 3, 4, 6};

  Solution t;

  int out = t.maximumScore(nums, multipliers);
  std::cout << " answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
