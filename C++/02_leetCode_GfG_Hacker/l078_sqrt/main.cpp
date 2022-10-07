
// babak poursartip
// Oct 7, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
      
      if (x<=1) return x;
      int left = 1, right = x / 2;
      long long int mid;
      while(left<=right)
      {
        mid  = (left + right)/2;
        int ans = mid*mid;
        if (mid*mid <= x  && (mid+1)*(mid+1)>x) return mid;
        else if (mid*mid < x) left = mid + 1;
        else if (mid*mid > x) right = mid - 1;
      }
      return mid-1;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
 
  Solution t;

  int out = t.mySqrt(atoi(argv[1]));
  
  cout << " answer: " << out << endl;
  
  std::cout << " done \n";
  return 0;
}