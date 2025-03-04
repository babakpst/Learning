

// babak poursartip

// Aug 7, 2022

/*

*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

class Solution
{
 public:
 private:
  std::vector<int> root;
  std::vector<int> rank;
  int size = 0;

 public:
  int find(int p)
  {
    if (p == root[p]) return p;
    return root[p] = find(root[p]);
  }

  void Union(int p, int q)
  {
    int rootp = find(p);
    int rootq = find(q);
    if (rootp != rootq)
    {
      for (auto it = root.begin(); it != root.end(); it++)
      {
        if (*it == rootq) *it = rootp;
      }
    }
  }

  bool connected(int p, int q) { return find(p) == find(q); }

  void printSet()
  {
    for_each(root.begin(), root.end(), [](auto v) { std::cout << v << " "; });
    std::cout << std::endl;
  }

  int findCircleNum(vector<vector<int>>& isConnected)
  {
    size = isConnected.size();
    root.resize(size);
    rank.resize(size, 1);

    iota(root.begin(), root.end(), 0);

    for (int i = 0; i < size; i++)
      for (int j = i; j < size; j++)
        if (isConnected[i][j]) Union(i, j);

    std::set<int> province;

    for_each(root.begin(), root.end(), [&province](auto x) { province.insert(x); });

    return province.size();
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // std::vector<std::vector<int>> vec{{1,1,0},{1,1,0},{0,0,1}};
  std::vector<std::vector<int>> vec{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

  Solution t;
  int out = t.findCircleNum(vec);
  std::cout << " Answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
