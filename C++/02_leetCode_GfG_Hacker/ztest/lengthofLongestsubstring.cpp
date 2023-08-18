
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

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

class Solution2
{
 public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.size() <= 1) return s.size();
    int maxLength = 1;

    unordered_map<char, int> characters;
    characters[s[0]] = 0;
    int left = 0, right = 1;
    while (right < s.size())
    {
      bool charExists = false;
      int ind;

      auto it = characters.find(s[right]);
      if (it != end(characters))
      {
        charExists = true;
        ind = it->second;
        characters.erase(s[right]);
      }
      else
      {
        characters[s[right]] = right;
      }

      // for(i = left; i<right; ++i)
      //   if (s[i]==s[right])
      //   {
      //     charExists = true;
      //     break;
      //   }

      if (!charExists)
      {
        maxLength = (right - left + 1) > maxLength ? (right - left + 1) : maxLength;
        right++;
      }
      else
      {
        left = ind + 1;
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
    int length = s.size(), maxLength = 0;
    if (length <= 1) return length;

    unordered_map<char, int> characters;

    int left = 0;
    for (int right = 0; right < length; ++right)
    {
      auto it = characters.find(s[right]);

      cout << " set before\n";
      for (auto mm : characters) cout << mm.first << " " << mm.second << endl;
      cout << " \n \n";

      if (it != end(characters))
      {
        cout << " in the for " << it->first << endl;
        left = it->second + 1;
        for (auto mm : characters)
          if (mm.second < left) characters.erase(s[mm.first]);
      }
      cout << " set after\n";
      cout << " set after\n";
      for (auto mm : characters) cout << mm.first << " " << mm.second << endl;
      cout << " \n \n";

      characters[s[right]] = right;
      maxLength = (right - left + 1) > maxLength ? (right - left + 1) : maxLength;
      cout << left << " " << right << " " << maxLength << " " << s[right] << endl;
    }

    return maxLength;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  int out = t.lengthOfLongestSubstring(argv[1]);
  cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}
