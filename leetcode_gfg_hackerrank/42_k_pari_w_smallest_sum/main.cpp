

/*

Given two lists, and an integer
k
k
, find
k
k
 pairs of numbers with the smallest sum so that in each pair, each list contributes one number to the pair.

Constraints:

1
1

≤
≤
 list1.length, list2.length
≤
≤

500
500

−
1
0
4
−10
4


≤
≤
 list1[i], list2[i]
≤
≤

1
0
4
10
4


1
1

≤
≤

k
k

≤
≤

1
0
3
10
3


Input lists should be sorted in ascending order.

If the value of
k
k
 exceeds the total number of valid pairs that may be formed, return all the pairs.



*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> KSmallestPairs(vector<int>& list1, vector<int>& list2, int k)
{
  vector<vector<int>> out(k);
  int ind1 = 0, ind2 = 0;
  int counter = 1;
  out[0] = {list1[ind1], list2[ind2]};

  while (counter < k)
  {
    if (ind2 + 1 < list2.size() && list1[ind1] + list2[ind2 + 1] < list1[ind1 + 1] + list2[0])
    {
      out[counter] = {list1[ind1], list2[ind2 + 1]};
      counter++;
      ind2++;
    }
    else
    {
      out[counter] = {list1[ind1 + 1], list2[0]};
      counter++;
      ind1++;
      ind2 = 0;
    };
  }
  return out;
}

int main()
{
  cout << " here: \n";
  vector<int> list1{1, 2, 300};
  vector<int> list2{1, 11, 20, 35, 300};

  vector<vector<int>> out = KSmallestPairs(list1, list2, 5);

  // for (auto x:out)
  for (int i = 0; i < out.size(); i++)
  {
    cout << "(" << out[i][0] << ", " << out[i][1] << ") ";
  }
  cout << endl;

  return 0;
}
