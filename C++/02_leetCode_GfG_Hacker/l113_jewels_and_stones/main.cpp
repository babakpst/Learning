

// babak poursartip
// Dec 12, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
      unordered_set<char> sset;
      int out = 0;

      for (int i = 0; i<jewels.size(); i++)
        sset.insert(jewels[i]);

      for (int i = 0; i<stones.size(); i++)
        if ( sset.find(stones[i]) != end(sset)) out++;

      return out;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
  string jewels = "aA", stones = "aAAbbbb";

  Solution t;

  int out = t.numJewelsInStones(jewels, stones);

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
