
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
  {
    // adjacency list + indegree
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);
    for (auto pr : prerequisites)
    {
      indegree[pr[0]]++;
      adj[pr[1]].push_back(pr[0]);
    }

    // BFS
    queue<int> mq;
    // adding indegree zeros
    for (int i = 0; i < indegree.size(); i++)
      if (indegree[i] == 0) mq.push(i);

    if (mq.empty()) return {};

    vector<int> out(numCourses, 0);
    int visitedCourses = 0;
    while (!mq.empty())
    {
      int course = mq.front();
      mq.pop();
      out[visitedCourses] = course;
      visitedCourses++;
      for (int j = 0; j < adj[course].size(); j++)
      {
        indegree[adj[course][j]]--;
        if (indegree[adj[course][j]] == 0) mq.push(adj[course][j]);
      }
    }

    return (visitedCourses == numCourses) ? out : vector<int>{};
  }
};

int main()
{
  // ex1
  // int numCourses = 2;
  // vector<vector<int>> prerequisites{{1, 0}, {0, 1}};

  // ex2
  int numCourses = 4;
  vector<vector<int>> prerequisites{{1, 0}, {2, 0}, {3, 1}, {3, 2}};

  Solution t;
  vector<int> out = t.findOrder(numCourses, prerequisites);

  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  cout << "end \n";
  return 0;
}
