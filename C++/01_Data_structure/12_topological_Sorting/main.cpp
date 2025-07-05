/*
topological sorting.
Graph saved as adjency list
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> topological_sorting(vector<vector<int>> &adj)
{
  vector<int> indegree(adj.size());

  for (int i = 0; i < adj.size(); i++)
    for (auto x : adj[i]) indegree[x]++;

  queue<int> myq;

  for (int i = 0; i < adj.size(); i++)
    if (indegree[i] == 0) myq.push(i);

  vector<int> res(adj.size());

  int index = 0;
  while (!myq.empty())
  {
    int vert = myq.front();
    myq.pop();
    res[index++] = vert;

    for (auto x : adj[vert])
    {
      indegree[x]--;
      if (indegree[x] == 0) myq.push(x);
    }
  }

  if (index != adj.size())
  {
    cout << "cycle in the graph:" << index << " " << adj.size() << endl;
    return {};
  }

  return res;
}

int main()
{
  cout << " code starts here \n";

  int nvertices = 6;
  vector<vector<int>> adj(nvertices);

  adj[0].resize(0);
  adj[1].resize(0);
  adj[2] = {3};
  adj[3] = {1};
  adj[4] = {0, 1};
  adj[5] = {0, 2};

  vector<int> res = topological_sorting(adj);

  for (auto x : res) cout << x << ", ";
  cout << endl;

  return 0;
}
