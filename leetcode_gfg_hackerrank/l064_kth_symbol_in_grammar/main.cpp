
// babak poursartip
// Sept 12, 2022

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
 public:
  vector<bool> mem;

  int kthGrammar(int n, int k)
  {
    mem.resize(k, false);
    for (int i = 1; i < n; i++)
    {
      vector<bool> tmp{mem.begin(), mem.begin() + pow(2, i - 1)};
      for (int j = 0; j < tmp.size(); j++)
      {
        if (tmp[j] == 0)
        {
          mem[2 * j] = 0;
          mem[2 * j + 1] = 1;
        }
        else
        {
          mem[2 * j] = 1;
          mem[2 * j + 1] = 0;
        }
        if (2 * j + 1 >= k - 1) return mem[k - 1];
      }
    }

    // for_each(mem.begin(), mem.end(), [](auto x){cout << x << " ";});
    // cout << endl;
    return 0;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  int n = 30;
  int k = 434991989;

  Solution t;

  int out = t.kthGrammar(n, k);
  cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}
