
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution0
{
 public:
  double myPow(double x, int n)
  {
    double out = 1;
    int sign = n < 0 ? -1 : 1;
    n *= sign;
    for (int i = 0; i < n; i++)
    {
      // if (i%10000==0) cout << out << " " <<i << endl;
      out *= x;
    }
    return sign < 0 ? 1.0 / out : out;
  }
};

class Solution1
{
 public:
  double myPow(double x, int n) { return pow(x, n); }
};

class Solution2
{
 public:
  double myPow(double x, int n)
  {
    if (n == 0) return 1;
    double temp = myPow(x, n / 2);
    cout << temp << endl;
    if (n % 2 == 0)
      return temp * temp;
    else if (n > 0)
      return x * temp * temp;
    else
      return temp * temp / x;
  }
};

class Solution
{
 public:
  double myPow(double x, int n)
  {
    if (n == 0) return 1.0;
    if (n < 0) x = 1.0 / x;
    if (n % 2 == 0) return myPow(x * x, n / 2);
    if (n % 2 == 1) return x * myPow(x * x, (n - 1) / 2);
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  double out = t.myPow(atoi(argv[1]), atoi(argv[2]));
  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
