

// babak poursartip
// Dec 14, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  string convertToBase7(int num)
  {
    if (!num) return "0";

    string out;
    bool neg = num < 0;
    if (neg) num *= (-1);
    while (num != 0)
    {
      out += to_string(num % 7);
      num /= 7;
    }
    if (neg) out += '-';
    reverse(begin(out), end(out));
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  string out = t.convertToBase7(atoi(argv[1]));

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
