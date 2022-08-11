
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
int main() {
  cout << " == BFS == \n";

  int nVertices = 4; // number of Nodes/Vertices
  std::vector<std::list<int>> adj(nVertices);
  adj[0].push_back(2);
  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);
  adj[3].push_back(3);

  cout << " BFS traverse: \n";
  int s = 2;

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

  return 0;
}