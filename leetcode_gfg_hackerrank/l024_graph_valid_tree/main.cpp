
// babak poursartip
// Aug 8, 2022

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

//  approach 1: Union find
class Solution
{
 public:
  bool validTree(int n, vector<vector<int>>& edges)
  {
    int nEdges = edges.size();

    // std::cout << " check edges " << nEdges << std::endl;

    // if all vertices/nodes are connected, it should have n-1 edges
    if (n - 1 != nEdges) return false;

    // std::cout << " check connection \n";
    // check if connected: using union find
    std::vector<int> root(n);
    std::iota(root.begin(), root.end(), 0);

    for (int i = 0; i < nEdges; i++)
    {
      int p = edges[i][0];
      int q = edges[i][1];
      int rootp = root[p];
      int rootq = root[q];
      if (rootp != rootq)
      {
        for (auto it = root.begin(); it != root.end(); it++)
        {
          if (*it == rootq) *it = rootp;
        }
      }
      else  // if a new edge does not result in a merge, that means we have a cycle, thus not a tree
        return false;
    }

    int treeRoot = root[0];
    for (auto it = root.begin(); it != root.end(); it++)
    {
      if (*it != treeRoot) return false;
    }
    return true;
  }
};

//  approach 2: DFS
// class Solution
// {
//   public:
//     bool validTree(int n, vector<vector<int>>& edges) {
//       if (n -1 != edges.size()) return false;

//       // create adjacency list
//       vector<list<int>> adj(n);

//       for (auto edge: edges)
//       {
//         adj[edge[0]].push_back(edge[1]);
//         adj[edge[1]].push_back(edge[0]);
//       }

//       // run a dfs to see if all nodes are connected
//       stack<int> st;
//       vector<bool> visited(n, false);

//       st.push(0);
//       visited[0]=true;

//       while (!st.empty())
//       {
//         int tmp = st.top();
//         cout << tmp << endl;
//         st.pop();
//         for (auto ed:adj[tmp])
//         {
//           cout << "ed: " << ed << endl;
//           if (!visited[ed])
//           {
//             st.push(ed);
//             visited[ed]=true;
//           }
//         }
//       }
//       cout <<" visited: \n";
//       for_each(begin(visited), end(visited), [](auto x){cout << x << " ";} );
//       bool out = any_of(begin(visited), end(visited), [](auto x){return !x;});
//       return !out;

//     }
// };

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // int n = 5;
  // std::vector<std::vector<int>> vec{{0,1},{0,2},{0,3},{1,4}};

  int n = 2;
  std::vector<std::vector<int>> vec{{0, 1}};

  Solution t;
  bool out = t.validTree(n, vec);
  std::cout << " answer: " << std::boolalpha << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
