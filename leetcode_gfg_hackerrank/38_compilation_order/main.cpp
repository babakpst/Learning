
/*

Topological sorting:

There are a total of n classes labeled with the English alphabet (A, B, C, and so on). Some classes are dependent on
other classes for compilation. For example, if class B extends class A, then B has a dependency on
A. Therefore, A must be compiled before B.

Given a list of the dependency pairs, find the order in which the classes should be compiled.

Constraints:

Class name should be an uppercase character.
0≤ dependencies.length ≤676
dependencies[i].length =2
All dependency pairs should be unique.

*/

#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

vector<char> FindCompilationOrder(vector<vector<char>> dependencies)
{
  map<char, int> classes;

  int nClasses = 0;

  // map classes to numbers
  for (auto x : dependencies)
  {
    if (classes.find(x[0]) == classes.end()) classes.insert({x[0], nClasses++});
    if (classes.find(x[1]) == classes.end()) classes.insert({x[1], nClasses++});
  }

  vector<vector<int>> adj(nClasses);
  for (auto x : dependencies) adj[classes[x[1]]].push_back(classes[x[0]]);

  vector<int> indegree(nClasses, 0);

  for (auto dep : adj)
    for (auto y : dep) indegree[y]++;

  cout << "indegree " << endl;
  for (int i = 0; i < indegree.size(); i++) cout << indegree[i] << " ";
  cout << endl;

  queue<int> myq;
  for (int i = 0; i < nClasses; i++)
    if (indegree[i] == 0) myq.push(i);

  vector<int> toposort(nClasses);
  int index = 0;
  while (!myq.empty())
  {
    int cls = myq.front();
    myq.pop();

    toposort[cls] = index++;
    for (auto dep : adj[cls])
    {
      indegree[dep]--;
      if (indegree[dep] == 0) myq.push(dep);
    }
  }

  if (index != adj.size())
  {
    cout << "cycle \n";
    return {};
  }

  vector<char> output(nClasses);

  for (auto x : toposort) cout << x << " ";
  cout << endl;

  for (auto x : classes) output[toposort[x.second]] = x.first;

  return output;
}

int main()
{
  cout << " code starts here \n";

  vector<vector<char>> dependencies;
  // {{'B','A'},{'C','A'},{'D','C'},{'E','D'},{'E','B'}};
  // vector<vector<char>> dependencies {{'C','A'},{'B','A'},{'D','C'},{'E','B'},{'E','D'}};

  // dependencies = {{'B', 'A'}, {'C', 'A'}, {'D', 'C'}, {'E', 'D'}, {'E', 'B'}};
  // dependencies =   {{'B', 'A'}, {'C', 'A'}, {'D', 'B'}, {'E', 'B'}, {'E', 'D'}, {'E', 'C'}, {'F', 'D'}, {'F', 'E'},
  // {'F', 'C'}};
  dependencies = {{'A', 'B'}, {'B', 'A'}};
  // dependencies =   {{'B', 'C'}, {'C', 'A'}, {'A', 'F'}};
  // dependencies = {{'C', 'C'}};

  vector<char> out = FindCompilationOrder(dependencies);

  for (auto x : out) cout << x << " ";
  cout << endl;

  return 0;
}
