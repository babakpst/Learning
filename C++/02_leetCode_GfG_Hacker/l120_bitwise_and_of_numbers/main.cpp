

// babak poursartip
// Dec 03, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int rangeBitwiseAnd(int left, int right)
  {
    int out = left & right;
    cout << " out 0: " << out << endl;
    if (out == 0) return 0;

    for (int i = left; i < right; i++)
    {
      out &= i;
      cout << " out: " << out << " " << i << endl;

      if (out == 0) return 0;
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  int out = t.rangeBitwiseAnd(atoi(argv[1]), atoi(argv[2]));

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
