
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
      int size = nums.size();
      if (size == 0)
        return -1;

      if (size == 1)
        return 0;


      int largest = nums[0];
      int index = 0;
      bool ret = true;

      for (int i = 1; i<size; i++)
      {
        if (nums[i]>largest)
        {
          if (nums[i]>=2*largest){
            largest = nums[i];
            index = i;
            ret = true;
          }
          else
          {
            largest = nums[i];
            index = i;
            ret = false;            
          }
        }
        else
        {
          if ( !(largest>=2*nums[i]) )
            ret = false;
        }
        //cout << " index: " << index << " largest: " << largest << " ret: " << ret << std::endl;
      }

      return ret?index:-1;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts \n";

  //vector<int> nums{3,6,1,0};
  //vector<int> nums{1,2,3,4};
  //vector<int> nums{1,2,3,4,8,4,2,1,2,1,1,16};
  //vector<int> nums{0,0,3,2};
  vector<int> nums{1,0};
  Solution t;
  int out = t.dominantIndex(nums);
  std::cout << " answer: " << out << std::endl;

  std::cout << " starts \n";
  return 0;
}