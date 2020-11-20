
/*
Babak Poursartip
11/02/2020

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements
appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the
returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]



*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      std::vector<int> res;
      for (int i=1; i<=nums.size(); ++i) {
        std::vector<int>::iterator it=std::find(nums.begin(), nums.end(), i);
        if (it==nums.end()) res.push_back(i);
      }
      return res;
    }
};
*/
//======================
/*
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    std::vector<int> res;
    std::sort(nums.begin(), nums.end());

    std::cout << " the vector: \n";
    for (auto c : nums)
      std::cout << c << " ";
    std::cout << std::endl;

    int val = 1;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      if ((it + 1) < nums.end() && *it == *(it + 1))
        continue;
      while (*it != val) {
        res.push_back(val);
        val++;
      }
      val++;
    }
    for (int i = val; val <= nums.size(); val++)
      res.push_back(val);

    return res;
  }
};
*/

//======================
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    std::vector<int> res;

    for (int i = 0; i < nums.size(); i++)
      if (nums[abs(nums[i]) - 1] >= 0)
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];

    /*
    std::cout << " the vector: \n";
    for (auto c : nums)
      std::cout << c << " ";
    std::cout << std::endl;
    */
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] > 0)
        res.push_back(i + 1);

    return res;
  }
};

//============================
int main() {
  std::cout << " starts  here ... \n";

  // std::vector<int> myVec = {4, 3, 2, 7, 8, 2, 3, 1};
  std::vector<int> myVec = {1, 1};
  std::cout << " the vector: \n";
  for (auto c : myVec)
    std::cout << c << " ";
  std::cout << std::endl;

  // find the missing integers
  Solution obj;
  std::vector<int> res = obj.findDisappearedNumbers(myVec);

  std::cout << " missing integers: \n";
  for (auto c : res)
    std::cout << c << " ";
  std::cout << std::endl;

  std::cout << "\n finished! \n";
  return 0;
}
