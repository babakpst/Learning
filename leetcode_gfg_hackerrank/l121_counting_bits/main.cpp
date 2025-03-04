

// babak poursartip
// Dec 03, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// approach 1
// class Solution
// {
//  public:
//   vector<int> countBits(int n)
//   {
//     vector<int> out(n + 1, 0);
//     for (int i = 0; i <= n; i++)
//     {
//       int ii = i;
//       int count = 0;
//       while (ii > 0)
//       {
//         ii &= ii - 1;
//         count++;
//       }
//       out[i] = count;
//     }
//     return out;
//   }
// };

// approach 2
class Solution
{
 public:
  vector<int> countBits(int n)
  {
    vector<int> out(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
      int count = 0;
      while (n > 0)
      {
        n &= (n - 1);  // removes the le (1<<i)?count++:0ast significant bit
        ++count;
      }
      out[i] = count;
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  vector<int> out = t.countBits(atoi(argv[1]));

  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
