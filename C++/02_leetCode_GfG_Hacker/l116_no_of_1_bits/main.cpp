
// babak poursartip
// Dec 17, 2022

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// approach 1
// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//       int count = 0;
//       for (int i = 0; i < 32; i++)
//         n & (1<<i)?count++:0;
//       return count;
//     }
// };

// approach 2
class Solution
{
 public:
  int hammingWeight(uint32_t n)
  {
    int count = 0;
    while (n > 0)
    {
      n &= (n - 1);  // removes the le (1<<i)?count++:0ast significant bit
      ++count;
    }
    return count;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  uint32_t num;
  num = atoi(argv[1]);

  Solution t;
  int out = t.hammingWeight(num);

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
