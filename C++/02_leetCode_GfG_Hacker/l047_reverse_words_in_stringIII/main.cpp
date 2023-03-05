
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) 
    {
      int size = s.size();

      int index = 0;
      for (int i = 0; i<size; i++)
      {
        if(s[i]==' ' || i == size-1)
        {
          reverse(s.begin()+index, s.begin()+i+(i == size-1?1:0));
          index = i+1;
        }
      }

      return s;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // std::string s{"Let's take LeetCode contest"};
  // std::string s{"the"};
  std::string s{""};
  // std::string s{"        hello    world      "};

  Solution t;

  string out = t.reverseWords(s);
  cout << " answer:-" << out << "-" << endl;

  std::cout << " done \n";
  return 0;
}


