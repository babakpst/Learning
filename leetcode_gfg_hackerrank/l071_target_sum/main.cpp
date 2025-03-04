
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution0
{
 public:
  int findTargetSumWays(vector<int>& nums, int target)
  {
    int ret = 0;
    int size = nums.size();
    stack<pair<int, int>> mys;
    mys.push({+nums[0], 0});
    mys.push({-nums[0], 0});

    while (!mys.empty())
    {
      pair<int, int> tmp = mys.top();
      mys.pop();
      // cout << " working on: " << tmp.first << " " << tmp.second << endl;
      if (tmp.second == size - 1 && tmp.first == target)
      {
        ret++;
        // cout << " added: " << tmp.first << endl;
      }
      else if (tmp.second != size - 1)
      {
        mys.push({tmp.first + nums[tmp.second + 1], tmp.second + 1});
        mys.push({tmp.first - nums[tmp.second + 1], tmp.second + 1});
      }
    }
    return ret;
  }
};

class Solution
{
 public:
  void findSum(vector<int>& nums, int ind, int sum, int& target, int& ret)
  {
    cout << ind << " " << sum << " " << ret << endl;
    if (ind == nums.size() - 1 && sum == target)
      ret++;
    else if (ind < nums.size() - 1)
    {
      findSum(nums, ind + 1, sum + nums[ind + 1], target, ret);
      findSum(nums, ind + 1, sum - nums[ind + 1], target, ret);
    }
  }

  int findTargetSumWays(vector<int>& nums, int target)
  {
    int ret = 0;
    int size = nums.size();
    int sum = nums[0];
    int ind = 0;
    findSum(nums, ind, sum, target, ret);
    findSum(nums, ind, -sum, target, ret);
    return ret;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{1,1,1,1,1};
  // int target = 3;

  vector<int> nums{1};
  int target = 1;

  // vector<int> nums{11,19,14,50,47,35,18,32,8,2,31,45,6,25,49,23,25,33,24,33};
  // int target = 44;

  Solution t;

  int out = t.findTargetSumWays(nums, target);
  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
