
// Babak Poursartp

// Cadence interview: 10/14/2020
// longest path in directed acyclic graph

#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class graph {
private:
  int nVertices;
  int nEdges;
  vector<vector<int>> adj;

public:
  // ======================
  graph(int nVertices, int nEdges) : nVertices{nVertices}, nEdges{nEdges} {
    adj.resize(nEdges);
  }

  // ======================
  void addEdge(int a, int b) { adj[a].push_back(b); }

  // ======================
  void DFS(int source, vector<int> &dp, vector<bool> &visited) {
    visited[source] = true;

    for (auto i : adj[source]) {

      if (!visited[i])
        DFS(i, dp, visited);

      dp[source] = max(dp[source], 1 + dp[i]);
    }
  }

  // ===================
  int LongestPath() {

    vector<int> dp(nVertices, 0);
    vector<bool> visited(nVertices, false);

    for (int i = 0; i < nVertices; i++) {
      if (!visited[i])
        DFS(i, dp, visited);
    }

    int ans = 0;

    for (int i = 0; i < nVertices; i++) {
      cout << dp[i] << endl;
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};

// ===========================
int main() {
  /*
  int nEdges = 5;
  int nVertices = 4;
  graph myG(nVertices, nEdges);

  myG.addEdge(0, 1);
  myG.addEdge(0, 2);
  myG.addEdge(2, 1);
  myG.addEdge(1, 3);
  myG.addEdge(2, 3);
  */
  int nEdges = 8;
  int nVertices = 5;
  graph myG(nVertices, nEdges);

  myG.addEdge(0, 2);
  myG.addEdge(0, 3);
  myG.addEdge(1, 2);
  myG.addEdge(1, 3);
  myG.addEdge(3, 2);
  myG.addEdge(4, 0);
  myG.addEdge(4, 1);
  myG.addEdge(4, 2);

  cout << " The longest path: " << myG.LongestPath() << endl;
  return 0;
}
