
// Babak Poursartip
// July 31, 2022

/*
Given an array of integers nums, sort the array in ascending order.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]

*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      make_heap(nums.begin(), nums.end());

      std::vector<int>::iterator end = nums.end();
      for (int i = 0; i<nums.size(); i++)
      {
        std::pop_heap(nums.begin(), end);
        end--;
      }

      return nums;
    }
};

template<typename T=int>
void printVec(std::vector<T> vec)
{
  for_each(vec.begin(), vec.end(), [](auto x){std::cout << x << " ";});  
  std::cout << " end of vec. \n";  
}

// ============
int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
  //std::vector<int> vec{5,87,5,1,7,2,7,88,21,1};
  std::vector<int> vec{};
  std::cout << " before ... \n";
  printVec(vec);
  
  Solution t;
  vec = t.sortArray(vec);
  
  std::cout << " sorted ... \n";
  printVec(vec);

  std::cout << " done. \n";
  return 0;
}
