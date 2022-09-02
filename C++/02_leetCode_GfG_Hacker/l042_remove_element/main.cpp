
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int size = nums.size();
      int k = size -1;
       
      for(int i = 0; i<=k; i++)
      {
        cout << i << " - " << k << endl;
        if (nums[i] == val)
        {
          while(k>i && nums[k] == val){k--;}
          if (k>=0){
            swap(nums[i], nums[k]);
            k--;
          }
        }          
      }
    return k+1;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{3,2,2,3}; 
  // int val = 3;
 
  // vector<int> nums{0,1,2,2,3,0,4,2}; 
  // int val = 2;
  
  // vector<int> nums{1}; 
  // int val = 1;

  // vector<int> nums{1}; 
  // int val = 2;

  vector<int> nums{}; 
  int val = 1;

  // vector<int> nums{0,4,4,0,4,4,4,0,2}; 
  // int val = 4;

  Solution t;

  int out = t.removeElement(nums, val);
  cout << " answer: " << out << endl;
  for_each(nums.begin(), nums.begin()+out,[](auto x){cout << x << " ";});
  cout << endl;
  std::cout << " done \n";
  return 0;
}