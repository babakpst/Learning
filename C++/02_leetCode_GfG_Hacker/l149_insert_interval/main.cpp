
// babak poursartip
// Aug 25, 2023

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
  {
    vector<vector<int>> out;

    int first = -1, second = -1;

    for (int i = 0; i < intervals.size(); i++)
    {
      if (intervals[i][0] <= newInterval[0] <= intervals[i][1]) first = i;
      if (intervals[i][0] <= newInterval[1] <= intervals[i][1]) second = i;
      if (second > -1 && first > -1) break;
    }

    // add new interval

    // do nothing

    // merge

    return;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // ex 1
  vector<vector<int>> intervals{{1, 3}, {6, 9}};
  vector<int> newInterval{2, 5};

  // ex 2
  // vector<vector<int>> intervals {{1,2},{3,5},{6,7},{8,10},{12,16}};
  // vector<int> newInterval {4,8};

  Solution t;
  vector<vector<int>> out = t.insert(intervals, newInterval);

  cout << " results: \n";
  for (auto c : out)
  {
    for (auto p : c)
    {
      cout << p << " ";
    }
    cout << endl;
  }

  std::cout << " done \n";
  return 0;
}
