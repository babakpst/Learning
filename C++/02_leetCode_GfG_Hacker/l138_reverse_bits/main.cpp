
#include <bitset>
#include <iostream>

using namespace std;

// approach 1
// class Solution
// {
//   public:
//     uint32_t reverseBits(uint32_t n)
//     {
//       int out  = 0;
//       for (int i = 0; i<32; ++i)
//        {
//         int bit = n&1;
//         n>>=1;
//         out += bit<<(31-i);
//         // cout <<  bitset<32>(out) << " " << bitset<32>(n) << endl;
//        }

//       return out;
//     }
// };

// approach 2
class Solution
{
 public:
  uint32_t reverseBits(uint32_t n)
  {
    n = (n >> 16 | n << 16);
    n = ((n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1);

    return n;
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  cout << bitset<32>(atoi(argv[1])) << endl;
  uint32_t out = sol.reverseBits(atoi(argv[1]));
  cout << bitset<32>(out) << endl;
  cout << out << endl;
  cout << " end \n";
  return 0;
}
