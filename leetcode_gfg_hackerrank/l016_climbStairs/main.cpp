

// Babak Poursartip
// Aug 1, 2022

#include <iostream>
#include <vector>

// dynamic programming bottom-up
using namespace std;
class Solution0
{
 public:
  int climbStairs(int n)
  {
    if (n == 1)
      return n;
    else
    {
      std::vector<int> vec(n, 0);
      vec[0] = 1;
      vec[1] = 2;
      for (int i = 3; i <= n; i++)
      {
        vec[i - 1] = vec[i - 2] + vec[i - 3];
      }
      return vec[n - 1];
    }
  }
};

// simple recursion, no dynamic programming, time limit
class Solution1
{
 public:
  int climbStairs(int n)
  {
    if (n <= 2)
      return n;
    else
      return climbStairs(n - 1) + climbStairs(n - 2);
  }
};

// recursion with memoization
class Solution2
{
 public:
  std::vector<int> st{1, 2};
  int climbStairs(int n)
  {
    // cout << n << endl;
    if (st.size() >= n)
      return st[n - 1];
    else
    {
      st.push_back((st.size() >= (n - 1) ? st[n - 2] : climbStairs(n - 1)) +
                   (st.size() >= (n - 2) ? st[n - 3] : climbStairs(n - 2)));
      // std::cout<<  " size: " << st.size() << " "<< st[n-1] <<" "<< st[n-2] << std::endl;
      return st[n - 1];
    }
  }
};

// recursion with memoization and pre allocation
class Solution3
{
 public:
  std::vector<int> st;
  int doit(int n)
  {
    // cout << n << endl;
    if (st[n - 1] != -1)
      return st[n - 1];
    else
    {
      st[n - 1] = (st[n - 2] != -1 ? st[n - 2] : doit(n - 1)) + (st[n - 3] != -1 ? st[n - 3] : doit(n - 2));
      // std::cout<<  " size: " << st.size() << " "<< st[n-1] <<" "<< st[n-2] << std::endl;
      return st[n - 1];
    }
  }

  int climbStairs(int n)
  {
    if (n <= 2)
      return n;
    else
    {
      st.resize(n, -1);
      st[0] = 1;
      st[1] = 2;
    }
    return doit(n);
  }
};

class Solution
{
 public:
  int climbStairs(int n)
  {
    if (n <= 2) return n;
    int out = 0;
    int t1 = 1;
    int t2 = 2;
    for (int i = 3; i <= n; i++)
    {
      out = t1 + t2;
      t1 = t2;
      t2 = out;
    }

    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
  Solution t;
  int out = t.climbStairs(atoi(argv[1]));
  std::cout << " output: " << out << std::endl;
  std::cout << " done. \n";
  return 0;
}
