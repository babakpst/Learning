
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#if 0
class Solution {
public:

    int numSquares(int n) {
      int min = (n<=3)?n:INT_MAX;
      int n1 = pow(n, 0.5);
      while(n1>1)
      {
        int sum = 0;
        int count = 0;
        int n2 = n1;
        while(sum<n)
        {
          sum += n2*n2;
          int n3 = pow(n-sum,0.5);
          n2 = n3 > n2?n2:n3;
          count++;
        }
        // cout << " sum: " << sum << " n1: " << n1 << " count: " << count << endl;
        if (sum == n && count < min) min = count;
        n1--;
      }

      return min;
    }
};
#endif

class Solution
{
 public:
  int numSquares(int n)
  {
    vector<int> dp(n + 1, INT_MAX);
    // bottom case
    dp[0] = 0;

    // pre-calculate the square numbers.
    int max_square_index = pow(n, 0.5) + 1;

    vector<int> square_nums(max_square_index);

    for (int i = 1; i < max_square_index; ++i)
    {
      square_nums[i] = i * i;
    }

    for (int i = 1; i <= n; ++i)
    {
      for (int s = 1; s < max_square_index; ++s)
      {
        if (i < square_nums[s]) break;
        dp[i] = min(dp[i], dp[i - square_nums[s]] + 1);
      }
    }
    return dp[n];
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  int out = t.numSquares(atoi(argv[1]));
  cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}
