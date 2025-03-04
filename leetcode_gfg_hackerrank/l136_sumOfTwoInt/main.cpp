
#include <bitset>
#include <iostream>
using namespace std;

//  approach one
// class Solution
// {
//   public:
//     int getSum(int a, int b)
//     {
//       int ans=0;
//       int sum;

//       for (int dec = 0; dec<32; dec++)
//       {
//         int level = 1<<dec;

//         int abit = a & level;
//         int bbit = b & level;

//         sum = (abit & bbit )?level<<1:abit|bbit;

//         ans = (ans & sum )?(ans^(sum | (sum<<1))):(ans|sum);
//         // cout << "level: " << level <<" abit: " << abit << " bbit: " << bbit<< " sum: " << sum
//         << " ans: " << ans << endl;
//       }
//       return ans;
//     }
// };

class Solution
{
 public:
  int getSum(int a, int b)
  {
    while (b != 0)
    {
      int ans = a ^ b;
      int carry = (a & b) << 1;
      a = ans;
      b = carry;
      cout << a << " " << b << endl;
    }
    return a;
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  int a = atoi(argv[1]), b = atoi(argv[2]);
  int out = sol.getSum(a, b);
  cout << " answer: " << out << endl;
  cout << "end\n";
  return 0;
}
