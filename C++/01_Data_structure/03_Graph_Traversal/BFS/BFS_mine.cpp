
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

public:
  // constructor
  graph(int nVertices) : nVertices{nVertices} { adj.resize(nVertices); }

  ~graph() {}

  // adding edge w to v's list.
  void addEdge(int v, int w) { adj[v].push_back(w); }

  // print traverse from a source
  void BFS(int s) {

    // to avoid getting trapped in a cycle
    std::vector<bool> visited(nVertices, false);

    // create a queue
    std::queue<int> myQ;

    // mark the sourse as visited
    visited[s] = true;

    // adding source to the queue
    myQ.push(s);

    while (!myQ.empty()) {

      // print the front node in the queue
      s = myQ.front();
      myQ.pop();
      cout << s << endl;

      // find the adjacencies of vertix s and add it to queue if has not been
      // visited earlier

      for (std::list<int>::iterator it = adj[s].begin(); it != adj[s].end();
           ++it) {
        if (!visited[*it])
          myQ.push(*it);
        visited[*it] = true;
      }
    }
  }
};

// ======================================
int main() {
  cout << " == BFS == \n";

  graph myG(4);
  myG.addEdge(0, 2);
  myG.addEdge(0, 1);
  myG.addEdge(1, 2);
  myG.addEdge(2, 0);
  myG.addEdge(2, 3);
  myG.addEdge(3, 3);

  cout << " BFS traverse: \n";
  myG.BFS(2);

  return 0;
}