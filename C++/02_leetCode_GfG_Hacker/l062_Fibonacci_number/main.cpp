
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution0 {
public:
    std::vector<int> st{0,1};
    int fib(int n) 
    {
      if (n<=1) 
      {
        return st[n];
      }

      else if (st.size()>n) return st[n];
      else
      {
        st.push_back( fib(n-1)+fib(n-2));
        return st[n];
      }
    }
};


class Solution {
public:
    int fib(int n) 
    {
      if (n<=1) return n;
      int out = 1;
      int tmp1 = 0;
      int tmp2 = 1;
      for (int i = 2; i<=n; i++)
      {
        out=tmp1+tmp2;
        tmp1 = tmp2;
        tmp2 = out;
      }
      return out;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

 
 
  Solution t;

  int out = t.fib(atoi(argv[1]));
  cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}