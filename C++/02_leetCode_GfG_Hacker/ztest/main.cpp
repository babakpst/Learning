#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// class Solution
// {
//   public:
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//       vector<vector<int>> paths;
//       vector<int> path;
//       queue<vector<int>> myq;

//       int nVertices = graph.size();

//       path = {0};
//       myq.push(path);

//       vector<vector<int>> visited;
//       visited.push_back(path);

//       while(!myq.empty())
//       {
//         path = myq.front();
//         myq.pop();
//         int lastNode = path.back();
//         if ( lastNode == nVertices-1)
//         {
//           paths.push_back(path);
//         }

//         for (auto edges: graph[lastNode])
//         {
//           vector<int> tmp = path;
//           tmp.push_back(edges);
//           if ( find(visited.begin(), visited.end(), tmp) == visited.end())
//           {
//             myq.push(tmp);
//           }
//         }
//       }
//       return paths;
//     }
// };

class Solution
{
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
  {
    vector<vector<int>> paths;
    vector<int> path;
    queue<vector<int>> myq;

    int nVertices = graph.size();

    path = {0};
    myq.push(path);

    while (!myq.empty())
    {
      path = myq.front();
      myq.pop();
      int lastNode = path.back();
      if (lastNode == nVertices - 1) paths.push_back(path);

      for (auto edges : graph[lastNode])
      {
        vector<int> tmp = path;
        tmp.push_back(edges);
        myq.push(tmp);
      }
    }
    return paths;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<vector<int>> edges{{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};

  Solution t;

  vector<vector<int>> out = t.allPathsSourceTarget(edges);

  for (auto c : out)
  {
    cout << " path: \n";
    for (auto p : c)
    {
      cout << p << " ";
    }
    cout << endl;
  }

  std::cout << " done. \n";
  return 0;
}
