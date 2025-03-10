
// Jul 23, 2022

/*

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.


Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  bool isPalindrome(int x)
  {
    if (x < 0) return false;

    int revert = 0;
    while (x > revert)
    {
      revert = revert * 10 + x % 10;
      x /= 10;
    }
    return x == revert || x == revert / 10;
  }
};

class Solution2
{
 public:
  bool isPalindrome(int x)
  {
    if (x < 0) return false;
    vector<int> vec;
    while (x > 0)
    {
      vec.push_back(x % 10);
      x /= 10;
    }
    // for_each(vec.begin(),vec.end(),[](auto x){cout << x << " ";});
    // cout <<endl;
    int size = vec.size();
    for (int i = 0; i < size / 2; i++)
    {
      // cout << vec[i] << " " << vec[size-i-1] << endl;
      if (vec[i] != vec[size - i - 1]) return false;
    }

    return true;
  }
};

int main(int argc, char* argv[])
{
  cout << " starts ... \n";

  Solution t;
  bool out = t.isPalindrome(atoi(argv[1]));
  cout << " output: " << boolalpha << out << endl;

  cout << " done. \n";
  return 0;
}
