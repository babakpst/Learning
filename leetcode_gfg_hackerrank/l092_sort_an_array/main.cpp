
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr)
  {
    sort(begin(arr), end(arr));
    int min = numeric_limits<int>::max();
    for (int i = 0; i < arr.size() - 1; i++)
      if ((arr[i + 1] - arr[i]) < min) min = arr[i + 1] - arr[i];

    cout << min << endl;
    vector<vector<int>> out;
    for (int i = 0; i < arr.size() - 1; i++)
      if ((arr[i + 1] - arr[i]) == min) out.push_back(vector<int>{arr[i], arr[i + 1]});

    cout << out.size() << endl;
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> arr{4,2,1,3};
  // vector<int> arr{ 1,3,6,10,15 };
  vector<int> arr{3, 8, -10, 23, 19, -4, -14, 27};

  Solution t;

  vector<vector<int>> out = t.minimumAbsDifference(arr);

  cout << " answer: " << endl;

  auto lm2 = [](auto x) {
    for_each(x.begin(), x.end(), [](auto y) { cout << y << " "; });
    cout << endl;
  };

  auto lm1 = [&](auto x) { lm2(x); };

  for_each(out.begin(), out.end(), lm1);

  cout << endl;

  std::cout << " done \n";
  return 0;
}
