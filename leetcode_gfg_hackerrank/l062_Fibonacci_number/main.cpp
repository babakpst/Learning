
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution0
{
 public:
  std::vector<int> st{0, 1};
  int fib(int n)
  {
    if (n <= 1)
    {
      return st[n];
    }

    else if (st.size() > n)
      return st[n];
    else
    {
      st.push_back(fib(n - 1) + fib(n - 2));
      return st[n];
    }
  }
};

class Solution
{
 public:
  int fib(int n)
  {
    if (n <= 1) return n;
    int out = 1;
    int tmp1 = 0;
    int tmp2 = 1;
    for (int i = 2; i <= n; i++)
    {
      out = tmp1 + tmp2;
      tmp1 = tmp2;
      tmp2 = out;
    }
    return out;
  }
};

// recursion
class Solution1
{
 public:
  int fib(int n)
  {
    if (n <= 1) return n;

    return fib(n - 1) + fib(n - 2);
  }
};

// recursion top-down
class Solution2
{
 public:
  map<int, int> mymap{{0, 0}, {1, 1}};

  int fib(int n)
  {
    if (mymap.find(n) != mymap.end()) return mymap[n];
    mymap[n] = fib(n - 1) + fib(n - 2);
    return mymap[n];
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // Solution t;
  // Solution1 t;
  Solution2 t;

  int out = t.fib(atoi(argv[1]));
  cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}
