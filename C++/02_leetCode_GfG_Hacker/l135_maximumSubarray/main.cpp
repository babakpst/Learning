
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

// class Solution
// {
//   public:
//   int maxSubArray(vector<int> & nums)
//   {

//     int i=0, j=nums.size()-1;
//     int left = i, right = j;
//     int sumLeft= 0, sumRight = 0;
//     while (i <= j && left<right)
//     {
//       if (sumLeft + nums[i] > 0) sumLeft+=nums[i];
//       else
//       {
//         left = i+1;
//         sumLeft = 0;
//       }

//       if (sumRight + nums[j] > 0) sumRight+=nums[j];
//       else
//       {
//         right = j-1;
//         sumRight = 0;
//       }
//       i++, j--;
//       cout << i << " " <<j << " " << sumLeft << " " << sumRight << " " << left << " " << right <<
//       endl;
//     }

//     int ret2 = nums[0];
//       for (vector<int>::iterator it = begin(nums)+1; it != end(nums); it++)
//         if (ret2<*it)
//           ret2 = *it;

//     if (left<right)
//     {
//       int ret = 0;
//       for (int i  = left; i<=right; i++)
//         ret += nums[i];
//       ret2=ret2>ret?ret2:ret;
//     }
//     return ret2;
//   }
// };

// class Solution
// {
//   public:
//   int maxSubArray(vector<int> & nums)
//   {

//     int i=0, j=nums.size()-1;
//     int left = i, right = j;
//     int sumLeft= 0, sumRight = 0;
//     while (i <nums.size()-1)
//     {
//       if (sumLeft + nums[i] > 0) sumLeft+=nums[i];
//       else
//       {
//         left = i+1;
//         sumLeft = 0;
//       }

//       i++;
//       cout<< "left: " << i << " "  << sumLeft << " " << left << endl;
//     }

//     while (left <= j)
//     {
//       if (sumRight + nums[j] > 0) sumRight+=nums[j];
//       else
//       {
//         right = j-1;
//         sumRight = 0;
//       }
//       j--;
//       cout << "right: " <<j << " " << sumRight << " " << right << endl;
//     }

//     int ret2 = nums[0];
//       for (vector<int>::iterator it = begin(nums)+1; it != end(nums); it++)
//         if (ret2<*it)
//           ret2 = *it;

//     if (left<right)
//     {
//       int ret = 0;
//       for (int i  = left; i<=right; i++)
//         ret += nums[i];
//       ret2=ret2>ret?ret2:ret;
//     }
//     return ret2;
//   }
// };

class Solution
{
 public:
  int maxSubArray(vector<int>& nums)
  {
    int max = nums[0];
    int curr = nums[0];

    for (vector<int>::iterator it = begin(nums) + 1; it != end(nums); it++)
    {
      int temp = *it;
      curr = std::max(curr + temp, temp);
      max = curr > max ? curr : max;

      // cout<< "max " << max << " curr "  << curr <<  endl;
    }

    return max;
  }
};

int main()
{
  // vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
  // vector<int> nums{1};
  // vector<int> nums{5,4,-1,7,8};
  // vector<int> nums{-2,-1};
  // vector<int> nums{-2,-3,-1};
  // vector<int> nums{8,-19,5,-4,20};
  // vector<int> nums{1,-1,-2};
  vector<int> nums{-1, 1, -2, 3};
  // vector<int> nums{ -3,1,0,-1,-2,3,2,-1};
  // vector<int> nums{ 1,1,-2};
  // vector<int> nums{  3,2,-3,-1,1,-3,1,-1};

  Solution sol;
  int ret = sol.maxSubArray(nums);
  cout << " answer: " << ret << endl;
  cout << " end of the code\n";
  return 0;
}
