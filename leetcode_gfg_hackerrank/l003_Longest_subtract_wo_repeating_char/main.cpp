/*
Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;
class Solution0
{
 public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.length() == 0 or s.length() == 1) return s.length();

    string st;    // holds searching string
    int len = 1;  // length of the search string
    int max = 1;  // length of the longest string

    char temp;  // current char in string
    // st.push_back(s.at(0));
    st = s.at(0);
    int pos = 1;  // current position in the string

    while (pos < s.length())
    {
      temp = s.at(pos);
      pos++;
      int loc = st.find(temp);
      if (loc == string::npos)
      {
        st.push_back(temp);
        len++;
      }
      else
      {
        max = max < len ? len : max;
        len -= loc;
        st.erase(0, loc + 1);
        st.push_back(temp);
      }
      std::cout << " max: " << max << " length: " << len << " location: " << loc << " temp str: " << st << std::endl;
    }
    return max > len ? max : len;
  }
};

class Solution1
{
 public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.size() <= 1) return s.size();
    int maxLength = 1;

    int left = 0, right = 1;
    while (right < s.size())
    {
      bool charExists = false;
      int i;
      for (i = left; i < right; ++i)
        if (s[i] == s[right])
        {
          charExists = true;
          break;
        }

      if (!charExists)
      {
        maxLength = (right - left + 1) > maxLength ? (right - left + 1) : maxLength;
        right++;
      }
      else
      {
        left = i + 1;
      }  // if (right<=left) right = left +1; }
      cout << left << " " << right << " " << maxLength << endl;
    }
    return maxLength;
  }
};

class Solution
{
 public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.size() <= 1) return s.size();

    int longest = 1;
    int left = 0;

    unordered_map<char, int> seen;
    seen.insert({s[left], left});

    for (int right = 1; right < s.size(); right++)
    {
      // cout << left << " " << right << " " << s[right] << endl;

      auto it = seen.find(s[right]);
      if (it != seen.end() && it->second >= left)
      {
        int temp = it->second + 1;
        // cout << " ref: " << temp << endl;

        for (int j = left; j < temp; j++)
        {
          // cout << " for loop: " << j << " " << (j < temp) <<" " << seen[s[j]] << endl;
          seen.erase(s[j]);
        }
        left = temp;
        seen[s[right]] = right;
      }
      else
      {
        // cout << "update longest: " << longest << " " << right-left +1 << endl;
        longest = max(right - left + 1, longest);
        seen.insert({s[right], right});
      }
    }
    return longest;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts here ... \n";

  Solution t;
  std::cout << t.lengthOfLongestSubstring(argv[1]) << std::endl;

  std::cout << " ends \n";
  return 0;
}
