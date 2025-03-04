
// Babak Poursartip
// 8/18/2022

/*
Since the graph is unweighted, we can solve this problem in O(V + E) time. The idea is to use a modified version of
Breadth-first search in which we keep storing the predecessor of a given vertex while doing the breadth-first search.

We first initialize an array dist[0, 1, …., v-1] such that dist[i] stores the distance of vertex i from the source
vertex and array pred[0, 1, ….., v-1] such that pred[i] represents the immediate predecessor of the vertex i in the
breadth-first search starting from the source.

Now we get the length of the path from source to any other vertex in O(1) time from array dist, and for printing the
path from source to any vertex we can use array pred and that will take O(V) time in worst case as V is the size of
array P. So most of the time of the algorithm is spent in doing the Breadth-first search from a given source which we
know takes O(V+E) time. Thus the time complexity of our algorithm is O(V+E).
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>

using std::cout;
using std::endl;

// ======================================
class graph
{
 private:
  int nVertices;                    // number of Nodes/Vertices
  std::vector<std::list<int>> adj;  // adjacency list
  std::vector<int> pred;            // holds the immediate predecessor/parent of i, from source
  std::vector<int> dist;            // holds the distance of node i from the source.

 public:
  graph(int nVertices) : nVertices{nVertices}, adj(nVertices), pred(nVertices, -1), dist(nVertices, INT_MAX) {}

  ~graph() {}

  // adding edge w to v's list.
  void addEdge(int v, int w)
  {
    adj[v].push_back(w);
    adj[w].push_back(v);
  }

  // print traverse from a source to all connnected nodes
  void BFS(int node)  // node is the soruce
  {
    std::vector<bool> visited(nVertices, false);  // to avoid getting trapped in a cycle
    std::queue<int> myQ;
    visited[node] = true;
    myQ.push(node);
    dist[node] = 0;

    while (!myQ.empty())
    {
      // print the front node in the queue
      node = myQ.front();
      myQ.pop();
      cout << node << endl;

      // find the adjacencies of vertix s and add it to queue if has not been visited earlier
      for (std::list<int>::iterator it = adj[node].begin(); it != adj[node].end(); ++it)
      {
        if (!visited[*it])
        {
          myQ.push(*it);
          visited[*it] = true;
          dist[*it] = dist[node] + 1;
          pred[*it] = node;
        }
      }
    }
  }

  std::vector<int> shortestPath(int dest)
  {
    // vector path stores the shortest path from the source to dest
    std::vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1)
    {
      crawl = pred[crawl];
      path.push_back(crawl);
    }
    return path;
  }
};

// ======================================
int main()
{
  cout << " == BFS == \n";

  // test 1
  graph myG(8);
  myG.addEdge(0, 2);
  myG.addEdge(0, 1);
  myG.addEdge(0, 3);
  myG.addEdge(1, 2);
  myG.addEdge(3, 4);
  myG.addEdge(3, 7);
  myG.addEdge(4, 5);
  myG.addEdge(4, 6);
  myG.addEdge(4, 7);
  myG.addEdge(5, 6);
  myG.addEdge(6, 7);
  int source = 0, dest = 7;

  cout << " BFS traverse: \n";
  myG.BFS(source);

  std::vector<int> path = myG.shortestPath(dest);

  std::cout << " path: " << std::endl;
  for_each(path.begin(), path.end(), [](auto x) { std::cout << x << " "; });
  std::cout << std::endl;

  return 0;
}
