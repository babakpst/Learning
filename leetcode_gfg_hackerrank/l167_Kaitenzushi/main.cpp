/*

There are N dishes in a row on a kaiten belt, with the ith dish being of type Di. Some dishes may be of the same type as
one another. You're very hungry, but you'd also like to keep things interesting. The N dishes will arrive in front of
you, one after another in order, and for each one you'll eat it as long as it isn't the same type as any of the previous
K dishes you've eaten. You eat very fast, so you can consume a dish before the next one gets to you. Any dishes you
choose not to eat as they pass will be eaten by others.

Determine how many dishes you'll end up eating.
Please take care to write a solution which runs within the time limit.

Constraints
1≤N≤500,000
1≤K≤N
1≤D i ≤1,000,000

Sample test case #1
N = 6
D = [1, 2, 3, 3, 2, 1]
K = 1
Expected Return Value = 5
Sample test case #2
N = 6
D = [1, 2, 3, 3, 2, 1]
K = 2
Expected Return Value = 4
Sample test case #3
N = 7
D = [1, 2, 1, 2, 1, 2, 1]
K = 2
Expected Return Value = 2

Sample Explanation
In the first case, the dishes have types of
[1,2,3,3,2,1], so you'll eat the first 3 dishes, skip the next one as it's another type-3 dish, and then eat the last 2.
In the second case, you won't eat a dish if it has the same type as either of the previous 2 dishes you've eaten. After
eating the first, second, and third dishes, you'll skip the fourth and fifth dishes as they're each the same type as one
of the last 2 dishes that you've eaten. You'll then eat the last dish, consuming 4 dishes total. In the third case, once
you eat the first two dishes you won't eat any of the remaining dishes.

*/

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
