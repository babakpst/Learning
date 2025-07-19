
// babak poursartip
// Sept 3, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution_mine
{
 public:
  vector<int> getRow(int rowIndex)
  {
    vector<int> out(rowIndex + 1, 1);

    for (int i = 2; i <= rowIndex; i++)
    {
      int temp1 = out[0];
      int temp2;

      for (int j = 1; j < i; j++)
      {
        temp2 = out[j];
        out[j] = temp1 + temp2;
        temp1 = temp2;
      }
    }
    return out;
  }
};

class Solution0
{
 public:
  vector<int> getRow(int rowIndex)
  {
    vector<int> out(rowIndex + 1, 1);
    for (int i = 1; i < rowIndex; i++)
    {
      cout << " i: " << i << endl;
      for (int j = i; j > 0; j--) out[j] += out[j - 1];

      for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
      cout << endl;
    }
    return out;
  }
};

class Solution
{
 public:
  vector<int> getRow(int rowIndex)
  {
    int cur = 2;
    vector<int> ret(rowIndex + 1, 1);

    while (cur <= rowIndex)
    {
      for (int i = cur - 1; i > 0; i--) ret[i] += ret[i - 1];
      cur++;
    }

    return ret;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // int rowIndex = 3;

  Solution t;

  vector<int> out = t.getRow(atoi(argv[1]));
  // cout << " answer: " << out << endl;

  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;
  std::cout << " done \n";

  return 0;
}
