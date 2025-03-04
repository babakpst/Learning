
// babak poursartip

// Aug 23, 2022
// solution from leetcode is different, it uses Union Find.

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 private:
  vector<vector<int>> adj;  // all vertices are connected, adj holds the weight/distance.
  vector<int> parent;
  vector<int> key;
  vector<int> queue;

  int sum = 0;

 public:
  int minCostConnectPoints(vector<vector<int>>& points)
  {
    // create the adj list,
    int size = points.size();

    if (size == 0 || size == 1) return 0;

    adj.resize(size);
    parent.resize(size);
    key.resize(size);
    queue.resize(size);  // list of unexplored points

    for (auto it1 = points.begin(); it1 != points.end(); it1++)
    {
      int point = distance(points.begin(), it1);
      queue[point] = point;
      adj[point].resize(size, 0);
      // for (auto it2 = it1+1; it2 != points.end(); it2++)
      for (auto it2 = points.begin(); it2 != points.end(); it2++)
      {
        int point2 = distance(points.begin(), it2);
        int dis = abs((*it1)[0] - (*it2)[0]) + abs((*it1)[1] - (*it2)[1]);
        adj[point][point2] = dis;
      }
      /*
      for (auto it2 = points.begin(); it2 != points.end(); it2++)
      {
        int point2 = distance(points.begin(),it2);
        std::cout << adj[point][point2] << " ";
      }
      std::cout << std::endl;
      */
    }

    // initialize parent & key
    for (int i = 0; i < size; i++)
    {
      parent[i] = INT_MIN;
      key[i] = INT_MAX;
    }

    // loop
    // assume the source is the first point.
    key[0] = 0;

    while (!queue.empty())
    {
      // find the min distance- the closest point
      auto compare = [&](auto x, auto y) { return key[x] < key[y]; };
      int u = *std::min_element(queue.begin(), queue.end(), compare);

      // std::cout << " min node is: " << u << " " << key[u] << std::endl;

      // removing the point the unexplored list
      auto itr = remove(queue.begin(), queue.end(), u);
      queue.erase(itr, queue.end());

      if (parent[u] != INT_MIN)
      {
        sum += key[u];
        // std::cout <<  " adding: " << u << " " << parent[u] << " sum: " << sum << std::endl;
      }

      // finding the adjacent points of this point and modifying its parent and key
      for (auto it1 = points.begin(); it1 != points.end(); it1++)
      {
        int point = distance(points.begin(), it1);
        int dis = adj[point][u];
        if (find(queue.begin(), queue.end(), point) != queue.end())
        {
          // std::cout << " modifying: " << point << " parent: " << u << " key: " << key[point] << " dis: " << dis
          // <<std::endl;
          if (key[point] > dis)
          {
            parent[point] = u;
            key[point] = dis;
            // std::cout << " modified: " << point << " parent: " << u << " key: " << key[point] << std::endl;
          }
        }
      }
    }
    return sum;
  }
};

int main()
{
  std::cout << " starts ... \n";

  vector<vector<int>> points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
  // vector<vector<int>> points{{3,12},{-2,5},{-4,1}};
  // vector<vector<int>> points{{3,12}};
  // vector<vector<int>> points{};
  Solution t;
  int out = t.minCostConnectPoints(points);
  std::cout << " answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
