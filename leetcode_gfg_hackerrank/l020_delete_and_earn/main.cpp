
// babak poursartip
// Aug 3, 2022
/*
You are given an integer array nums. You want to maximize the number of points you get by performing the following
operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1
and every element equal to nums[i] + 1. Return the maximum number of points you can earn by applying the above operation
some number of times.



Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
*/

// here is the recurssive formula: maxEarn(x) = max(maxEarn(x - 1), maxEarn(x - 2) + gain)

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
 public:
  std::unordered_map<int, int> pts;
  std::unordered_map<int, int> earn;

  int deleteAndEarn(vector<int>& nums)
  {
    int maxElement = 0;

    // auto ld = [&pts, &maxElement](int x)
    auto ld = [&](int x) {
      if (x > maxElement) maxElement = x;
      if (pts.find(x) != pts.end())
        pts[x] += x;
      else
        pts.insert(std::make_pair(x, x));
    };
    for_each(nums.begin(), nums.end(), ld);

    // std::cout << " here is the hash map: \n";
    // for_each(pts.begin(), pts.end(), [](auto x){ cout << x.first << ": " << x.second << endl;});

    return maxEarn(maxElement);
  }

  int maxEarn(int num)
  {
    if (num == 0) return 0;
    if (num == 1) return pts[1];
    if (earn.find(num) != earn.end()) return earn[num];

    int gain = pts[num];
    earn.insert(std::make_pair(num, max(maxEarn(num - 1), maxEarn(num - 2) + gain)));
    return earn[num];
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // std::vector<int> vec{2,2,3,3,3,4};
  std::vector<int> vec{3, 4, 2};
  Solution t;

  int out = t.deleteAndEarn(vec);
  std::cout << " answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
