#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/*
int minOperations(const vector <int> &arr) {
    string str;
    for (int x : arr) str.push_back(x + '0');

    unordered_set<string> visited; visited.insert(str);
    queue<string> q; q.push(std::move(str));

    for (int step = 0; !q.empty(); ++step) {
        for (size_t s = q.size(); s; --s) {
            auto str = std::move(q.front()); q.pop();
            if (std::is_sorted(str.begin(), str.end())) return step;

            for (int i = 0; i < str.size(); ++i) {
                for (int j = i + 2; j <= str.size(); ++j) {
                    reverse(str.begin() + i, str.begin() + j);
                    if (visited.insert(str).second) q.push(str);
                    reverse(str.begin() + i, str.begin() + j);
                }
            }
        }
    }
    return 0;
}

*/

int minOperations(vector<int> arr)
{
  // Write your code here

  int ret = 0;
  int size = arr.size();

  string initial;
  for (auto x : arr) initial += to_string(x);

  string target;
  for (int i = 1; i <= size; ++i) target += to_string(i);

  // cout << " converted " << cur << " " << target << endl;

  if (initial == target) return 0;

  unordered_set<string> visited;
  queue<string> bfs_q;
  bfs_q.push(initial);

  int level_size, level = 0, perm_size = initial.size();
  string nextPerm, curPerm;

  while (!bfs_q.empty())
  {
    level++;
    level_size = bfs_q.size();

    for (int q = 0; q < level_size; ++q)
    {
      curPerm = bfs_q.front();
      bfs_q.pop();

      cout << " >>>> current: " << curPerm << " level: " << level_size << " qq: " << q << endl;

      // generate all nextPermutations for the next level in BFS
      // the for loop indices enumarate all combinations of the pair (i,j)
      //  which are used for generating the next permutations (children) for the current permutation (parent)
      for (int i = 0; i < perm_size; i++)
        for (int j = i + 1; j < perm_size; ++j)
        {
          nextPerm = curPerm;
          cout << " next: " << nextPerm << endl;
          reverse(nextPerm.begin() + i, nextPerm.begin() + j + 1);
          cout << " next reversed: " << nextPerm << endl;
          if (nextPerm == target)
          {
            cout << " matched" << endl;
            return level;
          }
          if (visited.find(nextPerm) == visited.end())
          {
            visited.insert(nextPerm);
            bfs_q.push(nextPerm);
          }
        }
    }
  }

  return level;
}

int main()
{
  vector<int> arr{1, 2, 3, 8, 7, 6, 4, 5};

  int out = minOperations(arr);
  cout << "result: " << out << endl;

  return 0;
}
