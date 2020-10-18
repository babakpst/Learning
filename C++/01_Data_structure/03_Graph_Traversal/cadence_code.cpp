
// Babak Poursartp

// Cadence interview: 10/14/2020
// longest path in directed acyclic graph

#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class graph {
private:
  int nVertices;
  int nEdges;
  vector<vector<pair<int, int>>> adj;

public:
  // ======================
  graph(int nVertices, int nEdges) : nVertices{nVertices}, nEdges{nEdges} {
    adj.resize(nVertices);
  }

  // ======================
  void addEdge(int a, int b, int w) { adj[a].push_back(make_pair(b, w)); }

  // ======================
  void DFS(int source, vector<int> &dp, vector<bool> &visited, int &len) {
    visited[source] = true;

    for (auto i : adj[source]) {
      if (!visited[i.first])
        DFS(i.first, dp, visited, len);
      // dp[source] = max(dp[source], 1 + dp[i]);
    }
    dp[len] = source;
    len++;
  }

  // ===================
  void LongestPath(int source) {

    vector<int> dp(nVertices, -1);
    vector<bool> visited(nVertices, false);
    int len = 0;

    for (int i = 0; i < nVertices; i++) {
      if (!visited[i])
        DFS(i, dp, visited, len);
    }

    vector<int> length(nVertices, INT_MAX);
    length[source] = 0;

    for (int i = nVertices - 1; i >= 0; i--) {
      int v = dp[i];
      for (auto e : adj[v]) {

        int u = e.first;
        int w = e.second * (-1);

        if (length[v] != INT_MAX && length[v] + w < length[u]) {
          length[u] = length[v] + w;
        }
      }
    }

    for (int i = 0; i < nVertices; i++) {
      cout << source << " to " << i << " = " << setw(2) << -length[i] << endl;
    }
    vector<int>::iterator it = min_element(length.begin(), length.end());

    cout << " the longest path is: " << source << " to "
         << distance(length.begin(), it) << ": "
         << -length[distance(length.begin(), it)] << endl;
  }
};

// ===========================
int main() {

  int nEdges = 11;
  int nVertices = 8;
  graph myG(nVertices, nEdges);

  myG.addEdge(0, 6, 2);
  myG.addEdge(1, 2, -6);
  myG.addEdge(1, 4, 1);
  myG.addEdge(1, 6, 2);
  myG.addEdge(3, 0, 3);
  myG.addEdge(3, 4, 8);
  myG.addEdge(5, 1, 2);
  myG.addEdge(7, 0, -2);
  myG.addEdge(7, 1, 7);
  myG.addEdge(7, 3, 6);
  myG.addEdge(7, 5, -4);

  myG.LongestPath(7);
  return 0;
}
