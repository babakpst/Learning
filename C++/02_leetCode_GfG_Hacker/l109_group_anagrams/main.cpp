

// babak poursartip
// Dec 03, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, int> mym;
      vector<vector<string>> out;
      int ind = 0;
      for (int i = 0; i<strs.size(); i++)    
      {
        string str = strs[i];
        sort(str.begin(), str.end());
        // cout << " sorted: " << str << endl;
        auto it = mym.find(str);
        if ( it != mym.end() )
          out[it->second].push_back(strs[i]);
        else
        {
          mym.insert({str,ind++});
          out.push_back( { strs[i] } ) ;
        }
      }
      return out;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<string> strs{"eat","tea","tan","ate","nat","bat"};
  vector<string> strs{"a"};
 
  Solution t;

  vector<vector<string>> out = t.groupAnagrams(strs);
  
  // cout << " answer: " << out << endl;
  
  cout << " answer: "<< endl;
  auto lm1 = [](auto vec)
  {
    for_each(begin(vec), end(vec), [](auto x){cout << x << " ";});
    cout << endl;
  };
  
  for_each(out.begin(), out.end(), lm1);
  cout << endl;
  
  std::cout << " done \n";
  return 0;
}
