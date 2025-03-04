
// babak poursartip
// Aug 25, 2023

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// approach 1
class Solution1
{
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
  {
    if (!intervals.size()) return {newInterval};
    vector<vector<int>> out;
    if (newInterval[0] > intervals[intervals.size() - 1][1])
    {
      out = intervals;
      out.push_back(newInterval);
      return out;
    }

    int counter = 0;
    int first, second;
    int inter = 0;
    bool cont = true;
    while (inter < intervals.size() && cont)
    {
      // cout << "\n"<<inter << " (" << intervals[inter][0] << ", "<< intervals[inter][1] << ") "<<
      // endl;
      if ((intervals[inter][0] <= newInterval[0] && newInterval[0] <= intervals[inter][1]) ||
          (intervals[inter][0] <= newInterval[1] && newInterval[1] <= intervals[inter][1]) ||
          (intervals[inter][0] <= newInterval[0] && newInterval[1] <= intervals[inter][1]) ||
          (newInterval[0] <= intervals[inter][0] && intervals[inter][1] <= newInterval[1]))
      {
        // cout << " check 0\n";
        first = min(newInterval[0], intervals[inter][0]);
        second = max(newInterval[1], intervals[inter][1]);
        inter++;
      }
      else if (intervals[inter][1] < newInterval[0])  //  || newInterval[1] < intervals[inter][0]
      {
        // cout << " check 1\n";
        first = intervals[inter][0];
        second = intervals[inter][1];
        inter++;
      }
      else
      {
        // cout << " check 2\n";
        first = newInterval[0];
        second = newInterval[1];
        cont = false;
      }

      // cout << inter << " *(" << first << ", "<< second << ") "<< counter << endl;
      if (counter == 0 || out[counter - 1][1] < first)
      {
        // cout << " add 1\n";
        out.push_back({first, second});
        counter++;
      }
      else
      {
        // cout << " add 2 " << min(first, out[counter-1][0]) << " " <<  max(second,
        // out[counter-1][1])<< "\n";
        out[counter - 1] = {min(first, out[counter - 1][0]), max(second, out[counter - 1][1])};
      }
      // cout << inter << " *(" << first << ", "<< second << ") "<< counter << " (" <<
      // out[counter-1][0] << ", " << out[counter-1][1] << ")"<<endl;
    }
    while (inter < intervals.size()) out.push_back(intervals[inter++]);

    // cout<< " out "<< counter << endl;
    return out;
  }
};

class Solution
{
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
  {
    if (!intervals.size()) return {newInterval};
    vector<vector<int>> out;
    if (newInterval[0] > intervals[intervals.size() - 1][1])
    {
      out = intervals;
      out.push_back(newInterval);
      return out;
    }

    int inter = 0;
    bool cond = true;
    if (newInterval[0] < intervals[0][0])
    {
      out.push_back(newInterval);
      cond = false;
    }
    else
    {
      out.push_back(intervals[inter++]);
    }

    while (inter < intervals.size() || cond)
    {
      vector<int> newin;
      if (inter == intervals.size() || (newInterval[0] < intervals[inter][0] && cond))
      {
        newin = newInterval;
        cond = false;
      }
      else
      {
        newin = intervals[inter++];
      }

      if (out[out.size() - 1][1] < newin[0])
        out.push_back(newin);
      else
        out[out.size() - 1] = {min(newin[0], out[out.size() - 1][0]), max(newin[1], out[out.size() - 1][1])};
      cout << newin[0] << ", " << newin[1] << endl;
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // ex 1
  // vector<vector<int>> intervals{{1, 3}, {6, 9}};
  // vector<int> newInterval{2, 5};

  // ex 2
  // vector<vector<int>> intervals {{1,2},{3,5},{6,7},{8,10},{12,16}};
  // vector<int> newInterval {4,8};

  // ex 3
  // vector<vector<int>> intervals {{3,5},{12,15}};
  // vector<int> newInterval {6,6};

  // ex 4
  vector<vector<int>> intervals{{1, 5}};
  vector<int> newInterval{2, 3};

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
