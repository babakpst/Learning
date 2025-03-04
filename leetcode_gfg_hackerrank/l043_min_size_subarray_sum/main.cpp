
// babak poursartip
// Sept 03, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution2
{
 public:
  int minSubArrayLen(int target, vector<int>& nums)
  {
    int ret = nums.size() + 1;

    for (auto it = nums.begin(); it != nums.end(); it++)
    {
      int sum = *it;
      // cout << " start: " << sum << endl;
      auto it2 = it;
      while (sum < target && it2 != nums.end() - 1)
      {
        sum += *(++it2);
        // cout << " sum: " << sum << endl;
      }

      int dist = distance(it, it2) + 1;
      // cout << sum << " " << dist << endl;
      if (dist < ret && sum >= target) ret = dist;
    }
    return ret < nums.size() + 1 ? ret : 0;
  }
};

class Solution
{
 public:
  int minSubArrayLen(int target, vector<int>& nums)
  {
    int ret = nums.size() + 1;
    auto it1 = nums.begin();
    int sum = 0;
    for (auto it2 = it1; it2 != nums.end(); it2++)
    {
      sum += *it2;
      cout << sum << " " << distance(nums.begin(), it1) << " " << distance(nums.begin(), it2) << endl;
      while (sum >= target)
      {
        sum -= *it1;
        int dist = distance(it1, it2) + 1;
        if (dist < ret) ret = dist;
        cout << " mod ret: " << ret << endl;
        it1++;
      }
    }
    return ret < nums.size() + 1 ? ret : 0;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  int target = 7;
  vector<int> nums{2, 3, 1, 2, 4, 3};

  // int target = 4;
  // vector<int> nums{1,4,4};

  // int target = 11;
  // vector<int> nums{1,1,1,1,1,1,1,1};
  Solution t;

  int out = t.minSubArrayLen(target, nums);
  cout << " answer: " << out << endl;

  // for_each(out.begin(), out.end(), [](auto x){cout << x << " ";});
  // cout << endl;

  std::cout << " done \n";
  return 0;
}
