

// Babak Poursartip
// Aug 1, 2022


#include <iostream>
#include <vector>

// dynamic programming bottom-up
class Solution {
public:
    int climbStairs(int n) {
        if (n==1)
          return n;
        else
        {
          std::vector<int> vec(n,0);
          vec[0]= 1;
          vec[1]= 2;
          for (int i = 3; i<=n; i++)
          {
            vec[i-1]=vec[i-2] + vec[i-3];
          }
          return vec[n-1];
        }
    }
};

// simple recursion, no dynamic programming
class Solution1 {
public:
    int climbStairs(int n) {
        if (n<=2)
          return n;
        else
          return climbStairs(n-1) + climbStairs(n-2);
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
  Solution t;
  std::cout << " output: " << t.climbStairs(atoi(argv[1])) << std::endl;  
  std::cout << " done. \n";
  return 0;
}
