

// babak poursartip
// Dec 17, 2022

#include <bits/stdint-uintn.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t out = 0;

    for (int i = 0; i < 32; i++)
    {
      if (n & (1 << i)) out += 1 << (31 - i);
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  uint32_t out = t.reverseBits(atoi(argv[1]));

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
