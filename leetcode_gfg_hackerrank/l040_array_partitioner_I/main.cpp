
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int arrayPairSum(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    int ret = 0;
    for (int i = 0; i < nums.size(); i += 2) ret += nums[i];
    return ret;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{6,2,6,5,1,2};
  vector<int> nums{1, 4, 3, 2};

  Solution t;

  int out = t.arrayPairSum(nums);
  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
