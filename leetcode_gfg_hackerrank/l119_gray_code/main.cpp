

// babak poursartip
// Dec 18, 2022

#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> grayCode(int n)
  {
    int size = 1 << n;
    vector<int> out(size, 0);

    // cout << " size: " << out.size() << endl;
    out[1] = 1;
    int pos = 1;
    int loc = 2;
    int cp = 1;
    while (loc < size)
    {
      // cout << "pos: " << pos<< " loc: " << loc << " cp: " << cp << endl;
      while (cp >= 0)
      {
        out[loc] = out[cp] + (1 << pos);
        loc++;
        cp--;
      }
      pos++;
      cp = loc - 1;
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  vector<int> out = t.grayCode(atoi(argv[1]));

  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << bitset<16>(x) << endl; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
