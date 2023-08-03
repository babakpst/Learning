

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution
{
 public:
  bool duplicate(vector<int>& nums)
  {
    sort(begin(nums), end(nums));
    for (vector<int>::iterator it = begin(nums); it != end(nums) - 1; it++)
      if (*it == *(it + 1)) return true;
    return false;
  }
};

int main()
{
  cout << " end of the code\n";

  vector<int> nums{1, 2, 3, 0};

  Solution sol;
  cout << std::boolalpha << sol.duplicate(nums) << endl;
  // for_each(begin(nums), end(nums), [](auto i){cout << i << " ";});

  cout << " end of the code\n";
  return 0;
}
