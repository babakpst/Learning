
// Babak Poursartip
// 08/30/2020

#include <iostream>
#include <vector>
using namespace std;
bool checkIfExist(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      if (arr[i] == 2 * arr[j] || (arr[j] % 2 == 0 && arr[i] == 0.5 * arr[j])) return true;
    }
  }

  return false;
}

int main()
{
  vector<int> arr = {3, 1, 7, 11};

  bool ans = checkIfExist(arr);

  cout << " answer: " << boolalpha << ans << "\n";

  // cout << "\nends \n";
  return 0;
}
