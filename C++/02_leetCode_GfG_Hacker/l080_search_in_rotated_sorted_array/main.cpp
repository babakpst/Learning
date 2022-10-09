
// babak poursartip
// Oct 8, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    int search(vector<int>& nums, int target) {

      int size = nums.size();
      // edge case
      if (size == 1) return nums[0]==target? 0:-1;

      
      int left = 0, right = size-1;
      
      // check if vector is rotated, if yes, find the rotation index
      if (nums[left]>nums[right]) // rotated
      {
        while (!(left+1==right))
        {
          int mid = left + (right - left)/2;
          if (nums[mid]>nums[right]) left = mid; 
          else if (nums[mid]<nums[right]) right = mid; 
        }
        // cout << " rot: " << left << endl;
        if (target>nums[size-1]) 
        {
          right = left;
          left = 0;
        }
        else
        {
          left = right;
          right = size - 1;
        }
      }
      else // not rotatated
      {
        left = 0, right=size-1;
      }


      while(left<=right)
      {
        int mid = left + (right - left)/2;
        if (nums[mid]==target) return mid;
        else if (nums[mid]>target) right = mid - 1;
        else if (nums[mid]<target) left = mid + 1;
      }
      return -1;
    }
};
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

      int size = nums.size();
      // edge case
      if (size == 1) return nums[0]==target? 0:-1;

      
      int left = 0, right = size-1;
      while (left <= right)
      {
        int mid = left + (right-left)/2;
        // cout << left << " " << right << " " << mid << endl;
        if (nums[mid]==target) return mid;
        else if (nums[left] <= nums[mid] ) 
          if (nums[left]<=target &&  target < nums[mid] ) right = mid - 1;
          else left = mid + 1;
        else 
          if ( nums[mid] < target && target <= nums[right] ) left = mid + 1;
          else right = mid - 1;
      }

      return -1;
    }
};



int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<int> nums{4,5,6,7,0,1,2}; 
  int target = 2;
  
  // vector<int> nums{0,1,2,4,5,6,7}; 
  // int target = 4;
  
  // vector<int> nums{4}; 
  // int target = 4;

  Solution t;

  int out = t.search(nums, target);
  
  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}