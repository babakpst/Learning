

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> productExceptSelf(vector<int>& nums)
  {
    vector<int> res(nums.size(), 1);

    // approach one
    // for (int i = 0; i<nums.size(); i++)
    // {
    //   int mult = 1;
    //   for (int j = 0; j<nums.size(); j++)
    //     mult *= j==i?1:nums[j];
    //   res[i] = mult;
    // }

    // approach two
    // vector<int> pre(nums.size(), 1);
    // vector<int> post(nums.size(), 1);
    // for (int i = 1; i<nums.size(); i++)
    // {
    //   pre[i] = pre[i-1] * nums[i-1];
    //   post[nums.size()-i-1] = post[nums.size()-i] * nums[nums.size()-i];
    // }
    // // for_each(begin(pre), end(pre), [](auto x){cout << x << " ";}); cout <<endl;
    // // for_each(begin(post), end(post), [](auto x){cout << x << " ";}); cout <<endl;

    // for (int i = 0; i<nums.size(); i++)
    //   res[i] = pre[i] *  post[i];

    for (int i = 1; i < nums.size(); i++)
    {
      res[i] = res[i - 1] * nums[i - 1];
    }
    int mult = 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
      mult *= nums[i + 1];
      res[i] = res[i] * mult;
    }

    return res;
  }
};

int main(int argc, char* argv[])
{
  // vector<int> nums{1,2,3,4};
  vector<int> nums{2, 3, 4, 5, 6};

  Solution sol;
  vector<int> res = sol.productExceptSelf(nums);

  for_each(begin(res), end(res), [](auto x) { cout << x << " "; });

  cout << "\n end\n";
  return 0;
}
// 360 240 180 144 120
