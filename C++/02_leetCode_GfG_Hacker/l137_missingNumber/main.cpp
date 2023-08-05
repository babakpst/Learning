
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

// approach 1
// class Solution
// {
//   public:
//     int missingNumber(vector<int> nums)
//     {
//       sort(begin(nums), end(nums));
//       for (int i = 0; i<nums.size(); ++i)
//       {
//         if (i != nums[i]) return i;
//       }
//       return nums.size();
//     }
// };

// approach 2: time: O(N)-space: O(N)
// class Solution
// {
//   public:
//     int missingNumber(vector<int> nums)
//     {
//       vector<int> all(nums.size()+1);
//       iota(begin(all), end(all),0);
//       for (int i = 0; i<nums.size(); ++i)
//       {
//          all[nums[i]]=-1;
//       }

//       for (int i = 0; i<nums.size()+1; ++i)
//       {
//          if (all[i]!=-1)
//           return i;
//       }

//       return nums.size();
//     }
// };

// approach 3: using XOR time: O(N)-space: O(N)
//  n XOR n = 0 - 0 XOR n = n - n XOR m = n XOR m.
// class Solution
// {
//   public:
//     int missingNumber(vector<int> nums)
//     {
//       int missing = 0, notMissing = nums.size();
//       for (int i = 0; i<nums.size(); ++i)
//       {
//          missing ^= nums[i];
//          notMissing ^= i;
//       }

//       return missing ^ notMissing;
//     }
// };

// approach 4:
class Solution
{
 public:
  int missingNumber(vector<int> nums)
  {
    int missing = 0, notMissing = nums.size();
    for (int i = 0; i < nums.size(); ++i)
    {
      missing += nums[i];
      notMissing += i;
    }

    return notMissing - missing;
  }
};

int main(int argc, char* argv[])
{
  vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
  Solution sol;
  int out = sol.missingNumber(nums);
  cout << out << endl;
  cout << " end \n";
  return 0;
}
