

// Babak Poursartip
// 09/06/2020

// leetcode mountain valley array

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
 public:
  bool validMountainArray(vector<int> &A)
  {
    if (A.size() < 3) return false;
    int op = 0;  // 0 less than, 1 greater than.
    for (auto it = A.begin(); it != A.end() - 1; ++it)
    {
      cout << *it << " " << boolalpha << compare(*it, *(it + 1), op) << endl;
      if (!compare(*it, *(it + 1), op)) return false;
      if (op == 0 && it < (A.end() - 2))
      {
        cout << *(it + 1) << " " << *(it + 2) << endl;
        if (!(compare(*(it + 1), *(it + 2), op))) op = 1;
      }
      cout << " op: " << op << endl;
    }

    if (op == 1)
      return true;
    else
      return false;
  };

  bool compare(const int &a, const int &b, const int &op)
  {
    if (op == 0)
      return (a < b);
    else
      return (a > b);
  };
};

int main()
{
  cout << "starts ... \n";

  // vector<int> A = {1, 3, 4, 6, 8, 9, 9, 7,5,2};
  // vector<int> A = {1, 3, 4, 6, 8, 9, 10};
  vector<int> A = {3, 5, 5};

  for (auto c : A) cout << c << " ";
  cout << "\n";

  Solution s;

  cout << "answer: " << boolalpha << s.validMountainArray(A) << endl;

  cout << "ends. \n";
  return 0;
}
