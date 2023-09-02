
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

//  failed
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//       if (amount == 0) return 0;

//       sort(begin(coins), end(coins));

//       int coin = 0;
//       int pointer = coins.size()-1;
//       while (amount>0 && pointer>=0)
//       {
//         while (pointer >0 && amount<coins[pointer]) pointer--;
//         if (amount>=coins[pointer])
//         {
//           coin++;
//           amount-=coins[pointer];
//         }
//         else
//           break;
//         cout << amount << " " << pointer << " " << coin << endl;
//       }
//       return amount == 0?coin:-1;
//     }
// };

class Solution
{
 public:
  int coinChange(vector<int>& coins, int amount)
  {
    vector<int> num(amount + 1, amount + 1);

    num[0] = 0;

    sort(begin(coins), end(coins));

    for (int i = 1; i <= amount; i++)
      for (auto coin : coins)
        if (i >= coin) num[i] = min(num[i], num[i - coin] + 1);

    return num[amount] > amount ? -1 : num[amount];
  }
};

int main()
{
  // ex 1
  // vector<int> coins{1,2,5};
  // int amount = 11;

  // ex 2
  // vector<int> coins{2};
  // int amount = 3;

  // ex 3
  // vector<int> coins{1};
  // int amount = 1;

  // ex 4
  // vector<int> coins{2,5,10,1};
  // int amount = 27;

  // ex 5
  vector<int> coins{186, 419, 83, 408};
  int amount = 6249;
  // 83,186,408,419

  Solution t;
  int out = t.coinChange(coins, amount);

  cout << " answer: " << out << endl;
  cout << "end\n";
  return 0;
}
