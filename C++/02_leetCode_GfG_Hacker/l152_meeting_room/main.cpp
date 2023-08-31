
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution
{
 public:
  bool canAttendMeetings(vector<vector<int>>& intervals)
  {
    if (intervals.size() == 0) return true;
    sort(begin(intervals), end(intervals), [](auto x, auto y) { return x[0] < y[0]; });
    for (int i = 0; i < intervals.size() - 1; i++)
      if (intervals[i + 1][0] < intervals[i][1]) return false;
    return true;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<vector<int>> intervals{{15, 20}, {0, 30}, {5, 10}};
  // vector<vector<int> > intervals {{7,10},{2,4}};
  Solution t;

  bool out = t.canAttendMeetings(intervals);

  cout << " answer: " << boolalpha << out << endl;

  std::cout << " done \n";
  return 0;
}
