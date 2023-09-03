
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution
{
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
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

    int visitedCourses = 0;
    while (!mq.empty())
    {
      int course = mq.front();
      mq.pop();
      visitedCourses++;
      for (int j = 0; j < adj[course].size(); j++)
      {
        indegree[adj[course][j]]--;
        if (indegree[adj[course][j]] == 0) mq.push(adj[course][j]);
      }
    }

    return visitedCourses == numCourses;
  }
};

int main()
{
  int numCourses = 2;
  vector<vector<int>> prerequisites{{1, 0}, {0, 1}};

  Solution t;
  bool out = t.canFinish(numCourses, prerequisites);
  cout << " answer: " << out << endl;
  cout << "end \n";
  return 0;
}
