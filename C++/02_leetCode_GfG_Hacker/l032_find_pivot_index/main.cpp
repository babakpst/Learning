
// babak poursartip

// Aug 27, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int size = nums.size();

      if (size == 0)
        return -1;
      
      int right = 0, left = 0;
      for_each(nums.begin(), nums.end(), [&left](auto x) {left+=x;});

      for(int i = 0; i<size; i++)
      {
        left -= nums[i];
        if (  left == right )
          return i;
        right +=nums[i];
      }
      return -1;
    }
};

class Solution2 {
public:
    int pivotIndex(vector<int>& nums) {
      int size = nums.size();

      if (size == 0)
        return -1;
      
      vector<int> left(size,0), right(size,0);
      for(int i = 1; i<size; i++)
      {
         left[i] = nums[i-1]+left[i-1];
         right[size-i-1] = nums[size-i] + right[size-i];
      }
      for(int i = 0; i<size; i++)
      {
        if (left[i]==right[i])
          return i;
      }
      return -1;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts here \n";
  //std::vector<int> nums{1,7,3,6,5,6};
  std::vector<int> nums{1,2,3};
  //std::vector<int> nums{2,1,-1};
  //std::vector<int> nums{0};
  Solution t;
  int out = t.pivotIndex(nums);
  std::cout << " answer: " << out << std::endl;
  std::cout << " done \n";
  return 0;
}