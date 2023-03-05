
// babak poursartip
// Dec 17, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
      int count = 0;
      for (int i = 0; i < 32; i++)
        n & (1<<i)?count++:0; 
      return count;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  uint32_t num;  
  num = atoi(argv[1]);
   
  Solution t;
  int out = t.hammingWeight(num);
  
  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
