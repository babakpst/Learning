
/*
A maze consists of n rooms numbered from 1 ~ n, and some rooms are connected by corridors. You are given a 2D integer
array, corridors, where corridors[i]=[room1,room2]  indicates that there is a corridor connecting room1  and  room2,
allowing a person in the maze to go from room1 to room2 and vice versa.

The designer of the maze wants to know how confusing the maze is. The confusion score of the maze is the number of
different cycles of length 3.

For example, 1→2→3→1 is a cycle of length 3, but 1→2→3→4 and 1→2→3→2→1 are not.

Two cycles are considered to be different if one or more of the rooms visited in the first cycle is not in the second
cycle.

Return the confusion score of the maze.

Constraints:
2≤ n ≤100
1≤ corridors.length ≤5×10^2

corridors[i].length =2
1≤room1i ,room2i  ≤n

room1i != room2i

There are no duplicate corridors.

*/

#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;
int CommonRooms(const vector<set<int>> &adj, const int &room1, const int &room2)
{
  cout << " CommonRooms \n";
  auto ind1 = adj[room1].begin(), ind2 = adj[room2].begin();
  int out = 0;
  while (ind1 != adj[room1].end() && ind2 != adj[room2].end())
  {
    if (*ind1 == *ind2)
    {
      out++;
      ind1++;
      ind2++;
    }
    else if (*ind1 < *ind2)
    {
      ind1++;
    }
    else if (*ind1 > *ind2)
    {
      ind2++;
    }
  }
  return out;
};

int NumberOfPaths(int n, std::vector<std::vector<int>> &corridors)
{
  int cycles = 0;

  vector<set<int>> adj(n);

  for (int i = 0; i < corridors.size(); i++)
  {
    cout << i << endl;
    int room1 = corridors[i][0] - 1;
    int room2 = corridors[i][1] - 1;
    adj[room1].insert(room2);
    adj[room2].insert(room1);
    cout << " call \n";
    cycles += CommonRooms(adj, room1, room2);
  }
  return cycles;
};

int main()
{
  cout << " starts here: \n";

  int n = 5;
  vector<vector<int>> corridors = {{1, 2}, {5, 2}, {4, 1}, {2, 4}, {3, 1}, {3, 4}};

  int out = NumberOfPaths(n, corridors);
  cout << " n cycles: " << out << endl;

  return 0;
}
