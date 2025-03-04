

// babak poursartip
// Dec 03, 2022

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<vector<string>> groupStrings(vector<string>& strings)
  {
    unordered_map<string, list<string>> mym;
    for (auto str : strings)
    {
      vector<int> key(26, 0);
      int dif = str[0];
      for (auto c : str)
      {
        int ind = c - str[0] >= 0 ? c - str[0] : c - str[0] + 26;
        key[ind]++;
        // cout << " ind: " <<  ind << endl;
      }
      string stkey;
      for (int i = 0; i < key.size(); i++)
      {
        stkey.push_back('#');
        stkey += std::to_string(key[i]);
      }
      // cout << " strkey: " << stkey << endl;

      auto it = mym.find(stkey);

      if (it != end(mym))
        mym[it->first].push_back(str);
      else
      {
        mym.insert({stkey, {str}});
      }
    }

    vector<vector<string>> out(mym.size());
    int ind = -1;
    for (auto it = begin(mym); it != end(mym); it++)
    {
      ind++;
      for (auto it2 = begin(it->second); it2 != end(it->second); it2++) out[ind].push_back(*it2);
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<string> strings{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};

  Solution t;

  vector<vector<string>> out = t.groupStrings(strings);

  cout << " answer: " << endl;
  auto lm1 = [](auto vec) {
    for_each(begin(vec), end(vec), [](auto x) { cout << x << " "; });
    cout << endl;
  };

  for_each(out.begin(), out.end(), lm1);
  cout << endl;

  std::cout << " done \n";
  return 0;
}
