/*

AMD interview

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0

*/

#include <iostream>
using std::cout;
using std::string;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
      int sum  =0;
      for (int i = 0; i < stones.size(); ++i)
        {
          int j=0;
          while (stones[i]!=jewels[j] && j<jewels.size() )
            ++j;
          if (j<jewels.size()) ++sum;
          
        }
      return sum;
    }
};


int main()
{
cout << " starts \n";

std::string jewels = "aA";
std::string stones = "aAAbbbbb";

Solution mySol;
int sum = mySol.numJewelsInStones(jewels, stones);

cout << " answer: " << sum << "\n";
return 0;

}
