#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
      //std::sort(nums.begin(),nums.end());
      std::vector<int> res;
      for (vector<int>::iterator iter= nums.begin(); iter!=nums.end(); iter++){
          for (vector<int>::iterator iter2= iter+1; iter2!=nums.end(); iter2++){
            //std::cout << " iter 1: " << *iter << " iter 2: " << *iter2 << std::endl;
            if (*iter+*iter2==target){
              //std::cout << " ahhha " << std::distance(nums.begin(), iter) << " " << std::distance(nums.begin(), iter2) << std::endl;
              //res=std::vector<int>(std::distance(nums.begin(), iter),std::distance(nums.begin(), iter2));
              res.push_back(std::distance(nums.begin(), iter));
              res.push_back(std::distance(nums.begin(), iter2));
              }
          }
        }
      return res;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
      std::sort(nums.begin(),nums.end());
      std::vector<int> res;
      for (vector<int>::iterator iter= nums.begin(); iter!=nums.end(); iter++){
          int needed = target - *iter;
          vector<int>::iterator iter2= iter+1;
          while (*iter2<=needed){
            //std::cout << " iter 1: " << *iter << " iter 2: " << *iter2 << std::endl;
            if (*iter+*iter2==target){
              //std::cout << " ahhha " << std::distance(nums.begin(), iter) << " " << std::distance(nums.begin(), iter2) << std::endl;
              //res=std::vector<int>(std::distance(nums.begin(), iter),std::distance(nums.begin(), iter2));
              res.push_back(std::distance(nums.begin(), iter));
              res.push_back(std::distance(nums.begin(), iter2));
            }
            iter2++;
          }
        }
      return res;
    }
};




int main()
{

  std::cout << " starts here ... \n";
  
  std::vector<int>nums{2,7,11,15};
  Solution sol;
  //Solution2 sol;
  std::vector<int> res = sol.twoSum(nums,9);

  std::cout << res.size() << std::endl;

  for (vector<int>::iterator iter= res.begin(); iter!=res.end(); iter++){  
    std::cout << *iter << " ";
  }
  std::cout << std::endl;


  std::cout << " end here ... \n";
  return 0; 

}
