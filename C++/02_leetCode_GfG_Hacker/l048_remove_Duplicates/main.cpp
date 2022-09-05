
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int index = 0;
      for (int i = 1; i<nums.size(); i++)
      {
        if (nums[i]!=nums[index])
          nums[++index] = nums[i];
      }
      return (index+1);
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{0,0,1,1,1,2,2,3,3,4};
  // vector<int> nums{1,2,3,4,5};
  // vector<int> nums{1,1,2};
  // vector<int> nums{1,1};
  vector<int> nums{1};
  // vector<int> nums{};
 
  Solution t;

  int out = t.removeDuplicates(nums);
  cout << " answer: " << out << endl;
  cout << " answer: "<< endl;
  for_each(nums.begin(), nums.end(), [](auto x){cout << x << " ";});
  cout << endl;
  std::cout << " done \n";
  return 0;
}