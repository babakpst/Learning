
// babak poursartip
// Aug 31, 2022

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
 public:
  string addBinary(string a, string b)
  {
    int l1 = a.size(), l2 = b.size();
    if (l1 == 0 && l2 == 0)
      return a;
    else if (l1 == 0)
      return b;
    else if (l2 == 0)
      return a;

    int len = max(l1, l2);
    int i1 = 0, i2 = 0;
    std::string out(len + 1, '0');
    int n1, n2, carry = 0;
    for (int i = 1; i <= len + 1; i++)
    {
      i1 = l1 - i;
      i2 = l2 - i;
      n1 = 0, n2 = 0;
      if (i1 >= 0)
      {
        n1 = (a[i1] == '1') ? 1 : 0;
      }
      if (i2 >= 0)
      {
        n2 = (b[i2] == '1') ? 1 : 0;
      }
      n1 += n2 + carry;
      carry = 0;
      if (n1 < 2)
        out[len - i + 1] = (n1 == 0 ? '0' : '1');
      else
      {
        out[len - i + 1] = (n1 == 2 ? '0' : '1');
        carry = 1;
      }
    }
    return (out[0] == '0') ? out.substr(1, len) : out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // std::string a="11", b="1";
  // std::string a="1010", b="1011";
  std::string a = "1111", b = "1111";
  Solution t;
  std::string out = t.addBinary(a, b);
  std::cout << " answer: " << out << std::endl;

  std::cout << " done \n";
  return 0;
}
