

// babak poursartip
// Dec 14, 2022

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string toHex(int num) {
      string out;

      if (!num) return "0";

      bool neg = num<0;
      long lnum = num;
      if (neg) lnum*=-1;

      string nums = "0123456789abcdef";
      while (lnum!=0)
      {
        // out +=lnum%16<10?to_string(lnum%16):"abcdef"[lnum%16-10];
        // cout <<"0123456789abcdef"[lnum%16] << endl;
        out +=nums[lnum%16];
        lnum/=16;
      }
      reverse(begin(out), end(out));
      if (neg)
      {
        string out2(8,'f');
        for (int i = 0; i<out.size(); i++)
        {
          // find the char
          for (int j=0; j<nums.size(); j++)
            if (out[i]==nums[j])
            {
              out2[out2.size()-out.size()+ i] = nums[15-j];
              break;
            }
        }
        // cout << " after neg: " << out2 << endl;
        // add one ot out2
        bool carry = true;
        int pos = out2.size()-1;

        while(carry)
        {
          for (int j=0; j<nums.size(); j++)
            if (out2[pos]==nums[j])
            {
              if (j<nums.size()-1)
              {
                carry = false;
                out2[pos] = nums[j+1];
              }
              else
              {
                out2[pos] = nums[0];
                pos--;
              }
              break;
            }
        }
        out = out2;
      }
      return out;
    }
};
// -2147483648

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  string out = t.toHex(atoi(argv[1]));

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
