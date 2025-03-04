#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution
{
 public:
  int maxProfit(vector<int>& prices)
  {
    int max = 0;
    // for (vector<int>::iterator it = begin(prices); it!= end(prices)-1; it++)
    // {
    //   if (*(it+1) < *it) continue;

    //   for (vector<int>::iterator it2 = it+1; it2!= end(prices); it2++)
    //   {
    //     if (*it2 < *it) continue;
    //     if (max<(*it2-*it)) max = *it2-*it;
    //   }
    // }

    // for (vector<int>::iterator it = begin(prices); it!= end(prices)-1; it++)
    // {
    //   if (*it+1 < *it) continue;
    //   auto mm = max_element(it+1, end(prices));
    //   max = (max< *mm - *it )?*mm-*it:max;
    // }

    int lowestPrice = INT_MAX;
    for (vector<int>::iterator it = begin(prices); it != end(prices); it++)
    {
      if (lowestPrice > *it) lowestPrice = *it;
      if (max < (*it - lowestPrice)) max = (*it - lowestPrice);
    }

    return max;
  }
};

int main()
{
  cout << " code starts here\n";

  // vector<int> prices{7,1,5,3,6,4};
  vector<int> prices{1, 2};

  Solution sol;
  int res = sol.maxProfit(prices);

  cout << "output: " << res << endl;

  cout << " end of the code\n";
  return 0;
}
