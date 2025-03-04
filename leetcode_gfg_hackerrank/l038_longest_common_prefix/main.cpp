
// babak poursartip
// Sept 2, 2022

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  string longestCommonPrefix(vector<string>& strs)
  {
    int size = strs.size();
    if (size == 1) return strs[0];
    string ret = "";

    int index = 0;
    bool rep = true;
    while (rep)
    {
      char temp{strs[0][index]};
      for (int i = 1; i < size; i++)
      {
        cout << " tst: " << i << endl;
        if (index >= strs[i].size() || strs[i][index] != temp)
        {
          rep = false;
          break;
        }
      }
      if (rep) ret += temp;
      index++;
    }
    return ret;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<string> strs{"flower","flow","flight"};
  vector<string> strs{""};

  Solution t;
  string out = t.longestCommonPrefix(strs);

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
