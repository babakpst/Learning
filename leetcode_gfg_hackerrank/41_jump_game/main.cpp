/*
Given an array of integers called nums, each element represents a square in a game board. At each turn, the player can
take up to s steps toward the last square, where s is the value of the current square. This means from any position, you
can move forward by any number of steps from 1 up to the value at that position. Starting at the first index, your goal
is to determine whether it’s possible to reach the last index of the array. Write a function that returns TRUE if you
can reach the end, or FALSE if you get stuck somewhere.

Constraints:
1≤ nums.length ≤10^3
0≤ nums[i] ≤10^3

*/
#include <iostream>
#include <vector>

using namespace std;

bool JumpGame(vector<int> &nums)
{
  if (nums.size() == 1) return true;

  int target = nums.size() - 1;
  int index = target - 1;

  while (index >= 0)
  {
    if (target - index <= nums[index])
    {
      if (index == 0) return true;
      target = index;
      index = target - 1;
    }
    else
      index--;
  }

  return false;
}

int main()
{
  cout << " code starts here \n";

  // vector<int> nums{2,3,1,1,9};
  vector<int> nums{3, 2, 1, 0, 4};

  bool out = JumpGame(nums);
  cout << " results: " << boolalpha << out << endl;

  return 0;
}
