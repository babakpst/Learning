
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  void reverseString(vector<char>& s)
  {
    int size = s.size();
    for (int i = 0; i < size / 2; i++)
    {
      swap(s[i], s[size - i - 1]);
    }
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<char> s{'h','e','l','l','o'};
  // vector<char> s{'0','1','2','3','4'};
  // vector<char> s{'0','1','2','3','4','5'};
  // vector<char> s{'0','1'};
  vector<char> s{'0'};

  Solution t;
  t.reverseString(s);

  cout << " answer: " << endl;
  for_each(s.begin(), s.end(), [](auto x) { cout << x << ' '; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
