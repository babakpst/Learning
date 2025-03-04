
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  void sortColors(vector<int>& nums)
  {
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] == 0)
        zero++;
      else if (nums[i] == 1)
        one++;
      else if (nums[i] == 2)
        two++;

    for (int i = 0; i < nums.size(); i++) nums[i] = i < zero ? 0 : (i < (zero + one)) ? 1 : 2;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<int> nums{2, 0, 2, 1, 1, 0};

  Solution t;

  t.sortColors(nums);

  cout << " answer: " << endl;
  for_each(nums.begin(), nums.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
