
// babak poursartip
// Aug 14, 2022

#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
 public:
  bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
  {
    if (n == 1) return true;

    // create adjacency list
    int nVertices = n;
    vector<list<int>> adj(nVertices);

    for (auto edge : edges)
    {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    // start DFS
    stack<int> st;
    vector<bool> visited(nVertices, false);

    st.push(source);
    visited[source] = true;

    while (!st.empty())
    {
      int tmp = st.top();
      st.pop();
      for (auto ver : adj[tmp])
      {
        if (destination == ver) return true;
        if (!visited[ver])
        {
          st.push(ver);
          visited[ver] = true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  int n = 3, source = 0, destination = 2;
  vector<vector<int>> edges{{0, 1}, {1, 2}, {2, 0}};

  // int n = 6, source = 0, destination = 5;
  // vector<vector<int>> edges{{0,1},{0,2},{3,5},{5,4},{4,3}};

  Solution t;

  bool out = t.validPath(n, edges, source, destination);

  std::cout << " answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
