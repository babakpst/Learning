
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution
{
 public:
  int lengthOfLIS(vector<int>& nums)
  {
    vector<int> inc(nums.size(), 1);

    for (int i = 1; i < inc.size(); i++)
      for (int j = 0; j < i; j++)
        if (nums[i] > nums[j]) inc[j]++;

    int max = 1;
    for (int i = 1; i < inc.size(); i++)
      if (inc[i] > max) max = inc[i];
    return max;
  }
};

int main()
{
  // ex 1
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

  Solution t;
  int out = t.lengthOfLIS(nums);

  cout << " answer: " << out << endl;
  cout << "end\n";
  return 0;
}
