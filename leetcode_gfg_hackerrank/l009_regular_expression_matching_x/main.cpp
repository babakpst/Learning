
// Jul 23, 2022

/*

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".


Constraints:

1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

*/

#include <iostream>
using namespace std;

class Solution
{
 public:
  bool isMatch(string s, string p)
  {
    int pos1 = 0;
    int pos2 = 0;
    while (pos1 < s.length() - p.length())
    {
      if (s.[pos1] != p.[pos2])
        pos1++;
      else
      {
        pos1++;
        pos2++;
      }
    }

    return false;
  }
};

int main(int argc, char* argv[])
{
  cout << " starts ... \n";
  Solution t;
  bool out = t.isMatch(argv[1], argv[2]);
  cout << " output: " << boolalpha << out << endl;
  cout << " done.  \n";
  return 0;
}
