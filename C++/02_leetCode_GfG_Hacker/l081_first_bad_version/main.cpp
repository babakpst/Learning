
// babak poursartip
// Oct 9, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      if (isBadVersion(1)) return 1;
      int left = 1, right = n;
      while(left+1 != right)    
      {
        int mid = left+(right-left)/2;
        cout << left << " " << right << " " << mid <<endl;
        if (isBadVersion(mid)) right = mid;
        else left = mid;
      }
      return right;
    }

    bool isBadVersion(int ver)
    {
      return ver>=bad?true:false;
    }
    int bad;

};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
 
  Solution t;
  t.bad = atoi(argv[2]);
  int out = t.firstBadVersion(atoi(argv[1]));
  cout << " answer: " << out << endl;
  
  std::cout << " done \n";
  return 0;
}