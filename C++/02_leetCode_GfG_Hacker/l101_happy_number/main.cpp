
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
      int num = n;
      bool repeat = true;
      unordered_set<int> mySet;
      while (repeat)
      {
        // cout << "\n fresh start: " << num << endl;
        int sum = 0;
        while (num !=0 )
        {
          sum += (num%10)*(num%10);
          num /=10;
          // cout << " - sum: " << sum << " num: " << num << endl;
        }
        // cout << " sum: " << sum << endl;
        if (sum == 1) return true;
        num = sum; 
        if (mySet.find(num)==end(mySet))
          mySet.insert(num);
        else 
          repeat =false;
      }
      return false;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
 
  Solution t;

  bool out = t.isHappy(atoi(argv[1]));
  
  cout << " answer: " << boolalpha << out << endl;
  
  std::cout << " done \n";
  return 0;
}