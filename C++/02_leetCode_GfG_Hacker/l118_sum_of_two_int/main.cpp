

// babak poursartip
// Dec 03, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int getSum(int a, int b)
  {
    long aa = a, bb = b;
    while (aa != 0)
    {
      long carry = (aa & bb) << 1;
      long ans = (aa ^ bb);
      aa = carry;
      bb = ans;
    }
    return bb;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  int out = t.getSum(atoi(argv[1]), atoi(argv[2]));

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
