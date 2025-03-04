
// babak poursartip
// Oct 12, 2022

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x)
  {
    int size = arr.size();
    int kk = k;
    if (size == kk) return arr;

    vector<int> out(k);
    if (x <= arr[0])
    {
      copy(arr.begin(), arr.begin() + k, out.begin());
      return out;
    }

    if (x >= arr[size - 1])
    {
      copy(arr.end() - k, arr.end(), out.begin());
      return out;
    }

    int left = 0, right = size - 1;

    while (left + 1 != right)
    {
      int mid = left + (right - left) / 2;

      if (arr[mid] <= x)
        left = mid;
      else
        right = mid;
    }
    while (k > 0)
    {
      int dl = left >= 0 ? abs(arr[left] - x) : INT_MAX;
      int dr = right <= size - 1 ? abs(arr[right] - x) : INT_MAX;

      if (dl < dr || (dl == dr && arr[left] < arr[right]))
        left--;
      else
        right++;
      k--;
    }
    copy(arr.begin() + left + 1, arr.begin() + kk + left + 1, out.begin());

    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> arr{1,2,3,4,5};
  // int k = 4, x = 1;

  // vector<int> arr{ 1,1,1,10,10,10 };
  // int k = 1, x = 9;

  // vector<int> arr{ 0,1,2,2,2,3,6,8,8,9 };
  // int k = 5, x = 9;

  vector<int> arr{1, 2, 3, 3, 6, 6, 7, 7, 9, 9};
  int k = 8, x = 8;

  Solution t;

  vector<int> out = t.findClosestElements(arr, k, x);

  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
