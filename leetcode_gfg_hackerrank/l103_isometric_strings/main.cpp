
// babak poursartip
// Dec 00, 2022

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
 public:
  bool isIsomorphic(string s, string t)
  {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> myS, myT;
    // cout << " s: " << s << " t: " << t << endl;

    char counterS = 'a', counterT = 'a';
    for (int i = 0; i < s.size(); i++)
    {
      auto it = myS.find(s[i]);
      if (it != myS.end())
        s[i] = it->second;
      else
      {
        myS.insert({s[i], counterS});
        s[i] = counterS;
        counterS++;
      }

      it = myT.find(t[i]);
      if (it != myT.end())
        t[i] = it->second;
      else
      {
        myT.insert({t[i], counterT});
        t[i] = counterT;
        counterT++;
      }

      // for (auto it =begin(myS); it !=end(myS); it++ ) cout << it->first << " - " << it->second << endl;
      // for (auto it =begin(myT); it !=end(myT); it++ ) cout << it->first << " - " << it->second << endl;
      // cout << " s: " << s << " t: " << t << endl;
    }
    return s == t;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // string s="egg", t="add";
  string s = "aaabcddefffgahdd", t = "iiijkllmnnnoizlq";

  Solution obj;

  bool out = obj.isIsomorphic(s, t);

  cout << " answer: " << boolalpha << out << endl;

  // cout << " answer: "<< endl;
  // for_each(out.begin(), out.end(), [](auto x){cout << x << " ";});
  // cout << endl;

  std::cout << " done \n";
  return 0;
}
