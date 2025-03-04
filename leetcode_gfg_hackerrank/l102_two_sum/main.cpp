
// babak poursartip
// Nov 25, 2022

#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    unordered_map<int, int> myMap;
    vector<int> out;
    for (auto it = begin(nums); it != end(nums); it++)
      if (myMap.find(target - *it) != end(myMap))
      {
        out = {static_cast<int>(distance(begin(nums), it)), myMap.find(target - *it)->second};
        break;
      }
      else
        myMap[*it] = distance(begin(nums), it);
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<int> nums{2, 7, 11, 15};
  int target = 13;

  Solution t;

  vector<int> out = t.twoSum(nums, target);

  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
