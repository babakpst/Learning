
// babak poursartip
// Nov 23, 2022

#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
 public:
  int singleNumber(vector<int>& nums)
  {
    unordered_set<int> mySet;
    for (auto it = begin(nums); it != end(nums); it++)
      if (mySet.find(*it) != end(mySet))
        mySet.erase(*it);
      else
        mySet.insert(*it);
    return *begin(mySet);
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{2,2,1};
  vector<int> nums{4, 1, 2, 1, 2};

  Solution t;

  int out = t.singleNumber(nums);

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
