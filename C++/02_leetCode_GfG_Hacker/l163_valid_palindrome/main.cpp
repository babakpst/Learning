

#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>

using namespace std;

class Solution0
{
 public:
  bool isPalindrome(string s)
  {
    queue<char> myst;

    string non = " :,.~!@#$%^&*()_+-={}[]|/\?<>";
    int len = s.size();

    for (int i = 0; i <= len / 2; i++)
    {
      cout << tolower(s[i]) << " " << s[i] << endl;
      if (non.find(s[i]) == string::npos)
      {
        cout << " pushing " << endl;
        myst.push((tolower(s[i])));
      }
      cout << "**** " << myst.back() << endl;
    }

    cout << "===" << endl;
    int st = len % 2 ? len / 2 + 1 : len / 2;
    for (int i = len - 1; i > st; i--)
    {
      cout << tolower(s[i]) << " " << s[i] << " " << myst.front() << " "
           << (non.find(s[i]) == string::npos) << endl;
      if (non.find(s[i]) == string::npos && myst.front() == tolower(s[i]))
        myst.pop();
      else
        return false;
    }
    return myst.empty();
  }
};

class Solution1
{
 public:
  bool isPalindrome(string s)
  {
    string non = " :,.~!@#$%^&*()_+-={}[]|/\?<>";
    int first = 0;
    int last = s.size() - 1;

    while (first <= last)
    {
      cout << s[first] << " " << s[last] << endl;
      while (non.find(s[first]) != string::npos)
      {
        cout << " forward first " << endl;
        first++;
      }

      while (non.find(s[last]) != string::npos)
      {
        cout << " forward last " << endl;
        last--;
      }
      cout << (s[first]) << " == " << (s[last]) << endl;
      if (tolower(s[first]) != tolower(s[last])) return false;
      first++, last--;
    }

    return true;
  }
};

class Solution
{
 public:
  bool isPalindrome(string s)
  {
    int first = 0;
    int last = s.size() - 1;

    while (first <= last)
    {
      while (first < s.size() && !isalnum(s[first])) first++;
      while (last >= 0 && !isalnum(s[last])) last--;
      if (first <= last && tolower(s[first]) != tolower(s[last])) return false;
      first++, last--;
    }

    return true;
  }
};

int main()
{
  // string s = "A man, a plan, a canal: Panama";
  // string s = "abcdDcba";
  // string s = " ";
  string s = "0P";

  Solution t;
  bool out = t.isPalindrome(s);
  cout << " answer: " << boolalpha << out << endl;
  cout << " endl\n";
  return 0;
}
