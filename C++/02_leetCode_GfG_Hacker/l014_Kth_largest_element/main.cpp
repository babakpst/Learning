
// Babak Poursartip
// July 31, 2022

/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

      transform(begin(nums), end(nums), begin(nums), [](int e){return e*(-1);});
      std::vector<int> min_heap(k);
      copy(nums.begin(), nums.begin()+k, min_heap.begin());
      
      make_heap(min_heap.begin(), min_heap.end());

      for (int i = k; i<nums.size(); i++)
      {
        if (nums[i]<min_heap.front())
        {
          std::pop_heap(min_heap.begin(), min_heap.end());
          min_heap[k-1] = nums[i];
          push_heap(min_heap.begin(), min_heap.end());
        }
      }
      return (-1)*min_heap.front();
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
      make_heap(nums.begin(), nums.end());

      std::vector<int>::iterator end = nums.end();
      for (int i = 0; i<k-1; i++)
      {
        std::pop_heap(nums.begin(), end);
        end--;
      }
      return nums.front();
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
  std::vector<int> vec{3,2,3,1,2,4,5,5,6};
  //std::vector<int> vec{};
  std::cout << " before ... \n";
  printVec(vec);
  
  Solution t;
  std::cout << " kth largest element: " <<  t.findKthLargest(vec,4) << std::endl;
  
  std::cout << " sorted ... \n";
  printVec(vec);

  std::cout << " done. \n";
  return 0;
}

