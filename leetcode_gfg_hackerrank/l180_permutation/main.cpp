
// babak poursartip
// July 24, 2025

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  out(nums)

      vector<vector<int>> permute(vector<int>& nums)
  {
    vector<vector<int>> ret(n !);
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  vector<int> nums{1, 2, 3};
  vector<vector<int>> out = t.permute(nums);

  cout << " answer: " << endl;

  auto ld = [](auto x) {
    for_each(x.begin(), x.end(), [](auto y) { cout << y << " "; });
    cout << endl;
  };

  for_each(out.begin(), out.end(), ld);
  cout << endl;

  std::cout << " done \n";
  return 0;
}
