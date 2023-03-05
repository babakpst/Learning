
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set> 

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> set1, set2;
      for (auto it = begin(nums1); it != end(nums1); it++)
        if (set1.find(*it) == end(set1))
          set1.insert(*it);

      for (auto it = begin(nums2); it != end(nums2); it++)
        if (set2.find(*it) == end(set2))
          set2.insert(*it);
      
      vector<int> out;
      for (auto it = begin(set1); it != end(set1); it++)
        if (set2.find(*it)!=end(set2))
          out.push_back(*it);

      return out;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums1={1,2,2,1}, nums2={2,2};
  vector<int> nums1={4,9,5}, nums2={9,4,9,8,4};
  
  Solution t;

  vector<int> out = t.intersection(nums1, nums2);
  
  cout << " answer: "<< endl;
  for_each(out.begin(), out.end(), [](auto x){cout << x << " ";});
  cout << endl;
  
  std::cout << " done \n";
  return 0;
}