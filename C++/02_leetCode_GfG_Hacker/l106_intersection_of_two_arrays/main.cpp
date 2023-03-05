

// babak poursartip
// Dec 03, 2022

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

      unordered_map<int, int> myM;
      for (auto it = begin(nums1); it!=end(nums1); it++)
        if (myM.find(*it)!=end(myM))
          myM[*it]++;
        else
          myM.insert({*it,1});
      
      vector<int> out;
      for (auto it = begin(nums2); it!=end(nums2); it++)
        if (myM.find(*it)!=end(myM))
        {
          out.push_back(*it);
          myM[*it]--;
          if (myM[*it]==0) myM.erase(*it);
        }
      return out;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums1{1,2,2,1}, nums2{2,2};
  vector<int> nums1{4,9,5}, nums2{9,4,9,8,4};
 
  Solution t;

  vector<int> out = t.intersect(nums1, nums2);
  
  cout << " answer: "<< endl;
  for_each(out.begin(), out.end(), [](auto x){cout << x << " ";});
  cout << endl;
  
  std::cout << " done \n";
  return 0;
}
