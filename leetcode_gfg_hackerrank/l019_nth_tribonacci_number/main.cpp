
// babak poursartip
// Aug 2, 2022

/*
The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.



Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537


Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/

#include <iostream>
#include <vector>

class Solution
{
 public:
  int tribonacci(int n)
  {
    if (n <= 1)
      return n;
    else
    {
      std::vector<int> vec(n + 1, 0);
      vec[0] = 0;
      vec[1] = 1;
      vec[2] = 1;
      for (int i = 3; i <= n; i++) vec[i] = vec[i - 3] + vec[i - 2] + vec[i - 1];

      return vec[n];
    }
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  int out = t.tribonacci(atoi(argv[1]));
  std::cout << " answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
