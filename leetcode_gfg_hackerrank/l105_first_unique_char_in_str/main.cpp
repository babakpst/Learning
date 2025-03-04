

// babak poursartip
// Dec 04, 2022

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
 public:
  int firstUniqChar(string s)
  {
    unordered_map<char, int> myM;

    for (int i = 0; i < s.size(); i++)
      if (myM.find(s[i]) != end(myM))
        myM[s[i]]++;
      else
        myM.insert({s[i], 1});

    for (int i = 0; i < s.size(); i++)
      if (myM[s[i]] == 1) return i;

    return -1;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  std::string s = "aabb";

  Solution t;

  int out = t.firstUniqChar(s);

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
