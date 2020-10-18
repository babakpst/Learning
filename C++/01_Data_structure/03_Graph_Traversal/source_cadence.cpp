#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

// data structure to store graph edges
struct Edge {
	int src, dest, weight;
};

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<Edge>> adjList;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<Edge>
		adjList.resize(N);

		// add edges to the directed graph
		for (Edge const &edge: edges) {
			adjList[edge.src].push_back(edge);
		}
	}
};

// Perform DFS on graph and set departure time of all
// vertices of the graph
int DFS(Graph const &graph, int v, vector<bool>
	&discovered, vector<int> &departure, int& time)
{
	// mark current node as discovered
	discovered[v] = true;

	// set arrival time - not needed
	// time++;

	// do for every edge (v -> u)
	for (Edge e : graph.adjList[v])
	{
		int u = e.dest;
		// u is not discovered
		if (!discovered[u]) {
			DFS(graph, u, discovered, departure, time);
		}
	}

	// ready to backtrack
	// set departure time of vertex v
	departure[time] = v;
	time++;
}

// The function performs topological sort on a given DAG and then finds out
// the longest distance of all vertices from given source by running one pass
// of Bellman-Ford algorithm on edges of vertices in topological order
void findLongestDistance(Graph const& graph, int source, int N)
{
	// departure[] stores vertex number having its departure
	// time equal to the index of it
	vector<int> departure(N, -1);

	// stores vertex is discovered or not
	vector<bool> discovered(N);
	int time = 0;

	// perform DFS on all undiscovered vertices
	for (int i = 0; i < N; i++) {
		if (!discovered[i]) {
			DFS(graph, i, discovered, departure, time);
		}
	}


  for (auto c : departure)
      cout << c << " ";
    cout << endl;

	vector<int> cost(N, INT_MAX);
	cost[source] = 0;

	// Process the vertices in topological order i.e. in order
	// of their decreasing departure time in DFS
	for (int i = N - 1; i >= 0; i--)
	{
		// for each vertex in topological order,
		// relax cost of its adjacent vertices
		int v = departure[i];
		for (Edge e : graph.adjList[v])
		{
			// edge e from v to u having weight w
			int u = e.dest;
			int w = e.weight * -1;	// negative the weight of edge

			// if the distance to the destination u can be shortened by
			// taking the edge vu, then update cost to the new lower value
			if (cost[v] != INT_MAX && cost[v] + w < cost[u]) {
				cost[u] = cost[v] + w;
			}
		}
	}

	// print longest paths
	for (int i = 0; i < N; i++)
	{
		cout << "dist(" << source << ", " << i << ") = " << setw(2) << cost[i];
		cout << endl;
	}
}

int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges =
	{
		{0, 6, 2}, {1, 2, -4}, {1, 4, 1}, {1, 6, 8}, {3, 0, 3}, {3, 4, 5},
		{5, 1, 2}, {7, 0, 6}, {7, 1, -1}, {7, 3, 4}, {7, 5, -4}
	};

	// Number of nodes in the graph
	int N = 8;

	// create a graph from edges
	Graph graph(edges, N);

	// source vertex
	int source = 7;

	// find Longest distance of all vertices from given source
	findLongestDistance(graph, source, N);

	return 0;
}
