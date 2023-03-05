
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

    if (n==1)
      return true;

    // adjancency list
    vector<list<int>> adj(n);

    for (auto edge:edges)
    {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
 
    // DFS with source started from source
    vector<bool> visited(n,false);
    stack<int> st;
    
    st.push(source);

    while(!st.empty())
    {
      int node = st.top();
      st.pop();
      //std::cout <<  node << " ";
      //std::cout <<  node << " -- \n";

      for (auto c:adj[node])
      {
        //cout << c << "\n";
        if (!visited[c])
        {
          if (c == destination)
            return true;
          visited[c] = true;
          st.push(c);
        }
      }
    }

    // check whether destination is visited

    //std::cout << std::endl;
    //for_each(visited.begin(), visited.end(), [](auto x){std::cout << std::boolalpha << x << " ";});
    //std::cout << std::endl;
    return false;
    }
};
	


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  int n = 3, source = 0, destination = 2;
  vector<vector<int>> edges{{0,1},{1,2},{2,0}};
  
  //int n = 6, source = 0, destination = 5;
  //vector<vector<int>> edges{{0,1},{0,2},{3,5},{5,4},{4,3}};

  Solution t; 
  
  bool out = t.validPath(n, edges, source, destination);

  std::cout << " answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
