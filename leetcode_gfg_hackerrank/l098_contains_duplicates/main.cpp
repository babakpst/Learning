
// babak poursartip
// Nov 23, 2022

#include <algorithm>
#include <ios>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * Template for using hash set to find duplicates.
 */

class Solution
{
 public:
  bool containsDuplicate(vector<int>& nums)
  {
    unordered_set<int> mySet;
    for (auto it = begin(nums); it != end(nums); it++)
    {
      int key = *it;
      if (mySet.find(key) != end(mySet))
        return true;
      else
        mySet.insert(*it);
    }
    return false;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{1,2,3,1};
  vector<int> nums{1, 2, 3};

  Solution t;

  bool out = t.containsDuplicate(nums);

  cout << " answer: " << boolalpha << out << endl;

  std::cout << " done \n";
  return 0;
}
