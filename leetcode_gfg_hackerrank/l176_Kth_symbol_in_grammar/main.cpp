
/*
We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at
the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.
*/

// babak poursartip
// Jul 19, 2025

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution0
{
 public:
  int kthGrammar(int n, int k)
  {
    if (n == 1) return 0;
    vector<bool> vec(pow(2, (n - 1)), false);

    for (int i = 2; i <= n; i++)
    {
      int size = pow(2, i - 2);
      vector<bool> temp{vec.begin(), vec.begin() + size};

      // cout << " answer: " ;
      // for_each(temp.begin(), temp.end(), [](auto x) { cout << x << " "; });
      // cout << endl;

      for (int j = 0; j < size; ++j)
      {
        if (temp[j] == false)
        {
          vec[2 * j] = false;
          vec[2 * j + 1] = true;
        }
        else
        {
          vec[2 * j] = true;
          vec[2 * j + 1] = false;
        }
      }
      // cout << " answer: " ;
      // for_each(vec.begin(), vec.end(), [](auto x) { cout << x << " "; });
      // cout << endl;
    }

    // cout << " answer: " ;
    // for_each(vec.begin(), vec.end(), [](auto x) { cout << x << " "; });
    // cout << endl;

    return vec[k - 1];
  }
};

// recursive
class Solution
{
 public:
  int count = 2;
  string tmp = "01";
  void rev()
  {
    string tmp2 = '';
    for (auto x : tmp) tmp2 +=
  }

  void createSt(int n)
  {
    if (n == count) return;
    count++;
    tmp += re createSt(n);
    return;
  }

  int kthGrammar(int n, int k)
  {
    if (n == 1) return 0;
    if (n == 2) return k == 1 ? 0 : 1;
    createSt(n);

    return tmp[k - 1];
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;
  int out = t.kthGrammar(4, 4);

  cout << " answer: " << out << endl;

  // cout << " answer: " << endl;
  // for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  // cout << endl;

  std::cout << " done \n";
  return 0;
}
