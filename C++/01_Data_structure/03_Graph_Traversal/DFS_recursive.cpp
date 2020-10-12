
// Babak Poursartip
// 10/10/2020
// modified

/*
 source:
https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

Complexity Analysis:
- Time complexity: O(V + E), where V is the number of vertices and E is the
number of edges in the graph. Space Complexity: O(V).
- Since, an extra visited array is needed of size V.

- The only catch here is, unlike trees, graphs may contain cycles, so we may
come to the same node again. To avoid processing a node more than once, we use a
boolean visited array. For simplicity, it is assumed that all vertices are
reachable from the starting vertex.

*/

#include <iostream>
#include <list>
#include <queue>

using std::cout;
using std::endl;

// ======================================

class graph {
private:
  int nVertices; // number of Nodes/Vertices
  std::vector<std::list<int>> adj;

  // A recursive function used by DFS
  void DFSUtil(int v, std::vector<bool> &visited) {
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (auto c : adj[v])
      if (!visited[c])
        DFSUtil(c, visited);
  }

public:
  // constructor
  graph(int nVertices) : nVertices{nVertices} { adj.resize(nVertices); }

  ~graph() {}

  // adding edge w to v's list.
  void addEdge(int v, int w) { adj[v].push_back(w); }

  // print traverse from a source
  void DFS(int v) {

    // to avoid getting trapped in a cycle
    std::vector<bool> visited(nVertices, false);
    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
    cout << endl;
  }
};

// ======================================
int main() {
  cout << " == DFS == \n";

  graph myG(4);
  myG.addEdge(0, 2);
  myG.addEdge(0, 1);
  myG.addEdge(1, 2);
  myG.addEdge(2, 0);
  myG.addEdge(2, 3);
  myG.addEdge(3, 3);

  cout << " DFS traverse: \n";
  myG.DFS(2);

  return 0;
}