
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int getMaximumEatenDishCount2(int N, vector<int> D, int K)
{
  if (K == N) return 1;
  int num = 1;
  vector<int> pre(1, D[0]);

  bool exist = false;
  for (int i = 1; i < N; i++)
  {
    cout << " num: " << num << endl;
    bool exists = false;
    for (int j = 0; j < pre.size(); j++)
      if (D[i] == pre[j])
      {
        exists = true;
        break;
      }

    if (exists) continue;
    num++;
    pre.push_back(D[i]);
    if (pre.size() > K) pre.erase(pre.begin());
  }

  return num;
}

int getMaximumEatenDishCount(int N, vector<int> D, int K)
{
  if (K == N) return 1;
  int num = 1;
  queue<int> pre;
  unordered_set<int> myset;
  pre.push(D[0]);
  myset.insert(D[0]);

  bool exist = false;
  for (int i = 1; i < N; i++)
  {
    cout << " num: " << num << endl;
    bool exists = false;
    if (auto iter = myset.find(D[i]); iter != myset.end())
    {
      exists = true;
      continue;
    }

    num++;
    pre.push(D[i]);
    myset.insert(D[i]);

    if (pre.size() > K)
    {
      int fr = pre.front();
      pre.pop();
      myset.erase(fr);
    }
  }

  return num;
}

int main()
{
  std::cout << " code starts ..." << std::endl;

  vector<int> D = {1, 2, 3, 3, 2, 1};
  int K = 1;

  std::cout << " output: " << getMaximumEatenDishCount(D.size(), D, K) << std::endl;

  std::cout << " code ends ..." << std::endl;
  return 0;
}
