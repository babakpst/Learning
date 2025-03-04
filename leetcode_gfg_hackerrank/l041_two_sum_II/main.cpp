
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int binarySearch(vector<int>& numbers, int left, int right, int target)
  {
    while (right >= left)
    {
      // cout << left << " - " << right << endl;
      int mid = (left + right) / 2;
      if (numbers[mid] == target)
        return mid;
      else if (numbers[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return -1;
  }

  vector<int> twoSum(vector<int>& numbers, int target)
  {
    int ind2;
    int size = numbers.size();
    for (int ind1 = 0; ind1 < size - 1; ind1++)
    {
      ind2 = binarySearch(numbers, ind1 + 1, size - 1, target - numbers[ind1]);
      cout << " check \n";
      if (ind2 != -1) return {ind1 + 1, ind2 + 1};
    }
    return {0, 0};
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  //  vector<int> numbers{2,7,11,15};
  //  int target = 9;

  // vector<int> numbers{2,3,4};
  // int target = 6;

  // vector<int> numbers{-1,0};
  // int target = -1;

  vector<int> numbers{5, 25, 75};
  int target = 100;

  Solution t;

  vector<int> out = t.twoSum(numbers, target);
  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });

  cout << endl;
  std::cout << " done \n";
  return 0;
}
