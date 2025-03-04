

#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

class Solution1
{
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals)
  {
    vector<list<int>> ind(intervals.size());

    int out = 0;
    for (int i = 0; i < intervals.size(); ++i)
      for (int j = i + 1; j < intervals.size(); ++j)
      {
        if ((min(intervals[i][1], intervals[j][1]) - max(intervals[i][0], intervals[j][0])) >
            0)  // intervals have overlap
        {
          // if ((min(intervals[i][1],intervals[j][1]) - max(intervals[i][0],intervals[j][0]) ) ==
          // (intervals[i][1]- intervals[i][0]))
          // {
          //   out++;
          // }
          // else
          {
            cout << i << " -- " << j << endl;
            ind[i].push_back(j);
            ind[j].push_back(i);
          }
        }
      }

    for (int i = 0; i < ind.size(); i++)
    {
      for (auto c : ind[i]) cout << c << " ";
      cout << endl;
    }

    bool cont = true;
    while (cont)
    {
      int max = 0, index = -1;
      cont = false;
      for (int i = 0; i < ind.size(); ++i)
      {
        if (ind[i].size() > max)
        {
          max = ind[i].size();
          index = i;
        }
      }
      cout << " index: " << index << endl;
      if (index != -1)
      {
        cont = true;
        out++;
        for (auto c : ind[index])
        {
          ind[c].remove(index);
        }
        ind[index].clear();
      }
      cout << " here \n";
      for (int i = 0; i < ind.size(); i++)
      {
        for (auto c : ind[i]) cout << c << " ";
        cout << endl;
      }
    }

    return out;
  }
};

class Solution
{
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals)
  {
    vector<list<int>> ind(intervals.size());

    // auto lm = [](auto x, auto y)
    // {
    //   bool ret = false;
    //   if (x[1]<y[1])  ret = true;
    //   else if (x[1]==y[1])
    //     if (x[0]<y[0]) ret = true;
    //   return ret;
    // };
    // sort(begin(intervals), end(intervals), lm);

    sort(begin(intervals), end(intervals), [](auto x, auto y) { return x[1] < y[1]; });

// debug
#if 0
        for (int i = 0; i<intervals.size(); i++)
        {
          for (auto c:intervals[i])
            cout << c << " " ;
          cout << endl;
        }
#endif

    int ret = 0;
    int k = INT_MIN;
    for (int i = 0; i < intervals.size(); ++i)
      if (intervals[i][0] >= k)
        k = intervals[i][1];
      else
        ret++;
    return ret;
  }
};

int main()
{
  // vector<vector<int>> intervals{{1,2},{2,3},{3,4},{1,3}};
  vector<vector<int>> intervals{{0, 2}, {1, 3}, {1, 3}, {2, 4}, {3, 5}, {3, 5}, {4, 6}};
  // vector<vector<int>> intervals{{4,6},{1,3},{0,2},{1,3},{2,3},{2,4},{3,5},{3,5}};

  Solution t;
  int out = t.eraseOverlapIntervals(intervals);

  cout << " answer: " << out << endl;
  cout << " end\n";
  return 0;
}
