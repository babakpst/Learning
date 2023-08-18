
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
 public:
  int characterReplacement(string s, int k)
  {
    int left = 0, right = 0, budget, n = s.size();
    string tmp;
    int ret = 0;

    while (left < n)
    {
      right = left + 1;
      budget = k;
      tmp = s;
      while (right < n)
      {
        cout << left << " " << right;
        if (tmp[left] != tmp[right] && budget > 0)
        {
          tmp[right] = tmp[left];
          budget--;
        }
        cout << " " << tmp << endl;
        if (budget == 0) break;
        right++;
      }
      cout << " string: " << tmp << endl;
      ret = std::max(ret, longest(tmp));
      if (budget > 1 && s[n - 1] != s[n - 2]) s[n - 1] = s[n - 2];
      ret = std::max(ret, longest(tmp));

      left++;
    }
    return ret;
  }

  int longest(string s)
  {
    int maxLength = 1;
    int length = 1;
    int left = 0, right = 1;
    while (right <= s.size())
    {
      // cout << " len: " << maxLength << " " << length << endl;
      if (right < s.size() && s[left] == s[right])
        ++length;
      else
      {
        left = right;
        maxLength = max(maxLength, length);
        length = 1;
      }
      right++;
    }
    return maxLength;
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  int out = sol.characterReplacement(argv[1], atoi(argv[2]));

  cout << " answer: " << out << endl;
  cout << " end\n";
  return 0;
}
