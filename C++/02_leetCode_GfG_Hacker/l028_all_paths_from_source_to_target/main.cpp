
//babak poursartip
// Aug 14, 2022

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
public:
    // difficult, copied form the solution
    // DFS
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& paths) 
    {
        path.push_back(node);
        if (node == graph.size() - 1) {
            paths.emplace_back(path);
            return;
        }
        vector<int> nextNodes = graph[node];
        for (int nextNode : nextNodes) {
            dfs(graph, nextNode, path, paths);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        if (graph.size() == 0) {
            return paths;
        }
        vector<int> path;
        dfs(graph, 0, path, paths);
        return paths;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<vector<int>> edges{{4,3,1},{3,2,4},{3},{4},{}};

  Solution t; 
  
  vector<vector<int>>  out = t.allPathsSourceTarget(edges);

  for (auto c: out)
  {
    cout << " path: \n";
    for (auto p: c)
    {
      cout << p <<" ";    
    }
    cout << endl;
  }

  //std::cout << " answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
