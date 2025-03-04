

// babak poursartip
// Dec 03, 2022

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
      for(int i = 0; i<nums.size(); i++)
        for (int j = i+1; j<( min((int)nums.size(),i+k+1)); j++)
        {
          // cout << i << ": " << nums[i] << "--" << j << ": " << nums[j] << endl;
          if (nums[i]== nums[j]) return true;
        }
      return false;
    }
};
*/

class Solution
{
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k)
  {
    unordered_set<int> myS;
    for (int i = 0; i < nums.size(); i++)
    {
      if (myS.find(nums[i]) != end(myS)) return true;
      myS.insert(nums[i]);
      if (myS.size() > k) myS.erase(nums[i - k]);
    }
    return false;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<int> nums{1, 2, 3, 1};
  int k = 3;

  // vector<int> nums{1,0,1,1};
  // int k = 1;

  // vector<int> nums{1,2,3,1,2,3};
  // int k = 2;

  // vector<int> nums{99,99};
  // int k = 2;

  Solution t;

  bool out = t.containsNearbyDuplicate(nums, k);

  cout << " answer: " << boolalpha << out << endl;

  std::cout << " done \n";
  return 0;
}
