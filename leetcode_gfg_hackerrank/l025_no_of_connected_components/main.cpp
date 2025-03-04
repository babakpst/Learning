

// babak poursartip
// Aug 8, 2022

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution0
{
 public:
  int countComponents(int n, vector<vector<int>>& edges)
  {
    std::vector<int> root(n);
    std::iota(root.begin(), root.end(), 0);

    for (int i = 0; i < edges.size(); i++)
    {
      int p = edges[i][0];
      int q = edges[i][1];
      int rootp = root[p];
      int rootq = root[q];
      if (rootp != rootq)
        for (auto it = root.begin(); it != root.end(); it++)
        {
          if (*it == rootq) *it = rootp;
        }
    }

    std::set<int> connected;
    for (auto it = root.begin(); it != root.end(); it++)
    {
      connected.insert(*it);
    }
    return connected.size();
  }
};

class Solution
{
 public:
  int countComponents(int n, vector<vector<int>>& edges)
  {
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);

    // fill the adjacency list
    for (auto edge : edges)
    {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    int islands = 0;
    for (int i = 0; i < visited.size(); i++)
    {
      if (visited[i] == false)
      {
        islands++;
        queue<int> gr;
        gr.push(i);
        visited[i] = true;
        // cout << " ----i: " <<i << endl;
        while (!gr.empty())
        {
          int node = gr.front();
          gr.pop();
          // cout << " node: " << node << endl;
          for (int j = 0; j < adj[node].size(); j++)
          {
            int tmp = adj[node][j];
            // cout << " j: " << j << "  -- " << tmp<< endl;
            if (visited[tmp] == false)
            {
              // cout << " adding to graph: " << tmp  <<  endl;
              visited[tmp] = true;
              gr.push(tmp);
            }
          }
        }
      }
    }

    return islands;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // int n = 5;
  // std::vector<std::vector<int>> vec{{0,1},{0,2},{0,3},{1,4}};

  // int n = 2;
  // std::vector<std::vector<int>> vec{{0,1}};

  int n = 5;
  std::vector<std::vector<int>> vec{{0, 1}, {1, 2}, {3, 4}};

  Solution t;
  int out = t.countComponents(n, vec);
  std::cout << " answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
