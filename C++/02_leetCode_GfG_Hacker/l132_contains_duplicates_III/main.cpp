
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

class Solution
{
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff)
  {
    int j = min(indexDiff, (int)(nums.size() - 1));
    int i = 0;
    set<int> snum(begin(nums), begin(nums) + j + 1);
    cout << *(begin(nums) + j) << endl;
    cout << j << endl;
    cout << " chk 1 \n";
    while (j++ < nums.size())
    {
      cout << endl << "while chk 2 \n";

      // sort(begin(snum), end(snum));
      printVec(snum);
      for (auto it1 = begin(snum); it1 != prev(end(snum), 1); it1++)
      // for (auto it2 = it1+1; it2!=end(snum);it2++)
      {
        cout << *it1 << " " << *(next(it1, 1)) << endl;
        // if (abs(*it1-*it2)<=valueDiff) return true;
        if (abs(*it1 - *(next(it1, 1))) <= valueDiff) return true;
        // else break;
      }

      // snum[ find(begin(snum),end(snum),nums[i]) ] = nums[j];
      // if (j<nums.size()) *(find(begin(snum),end(snum),nums[i]))= nums[j];
      if (j < nums.size()) snum.insert(nums[j]);
      snum.erase(nums[i]);

      i++;
    }

    return false;
  }

  void printVec(set<int> vec)
  {
    cout << " size: " << vec.size() << endl;
    for (auto it = begin(vec); it != end(vec); it++) cout << *it << " ";
    cout << endl << endl;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<int> nums{1, 5, 9, 1, 5, 9};
  // vector<int> nums{1,9,4,1,5,9};
  int indexDiff = 2;
  int valueDiff = 3;

  // vector<int> nums{-3,3};
  // int indexDiff = 2;
  // int valueDiff = 4;

  Solution t;

  bool out = t.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);

  cout << " answer: " << boolalpha << out << endl;

  std::cout << " done \n";
  return 0;
}
