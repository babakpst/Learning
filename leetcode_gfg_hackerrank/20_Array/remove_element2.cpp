#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

int remve(std::vector<int> &nums, int val)
{
  int i = 0;
  for (int j = 0; j < nums.size(); j++)
  {
    if (nums[j] != val)
    {
      nums[i] = nums[j];
      i++;
    }
  }
  return i;

  return i;
};

int main()
{
  printf(" subs ..\n");
  std::vector<int> nums;
  nums.resize(12);
  nums[0] = 4;
  nums[1] = 2;
  nums[2] = 0;
  nums[3] = 2;
  nums[4] = 2;
  nums[5] = 1;
  nums[6] = 4;
  nums[7] = 4;
  nums[8] = 1;
  nums[9] = 4;
  nums[10] = 3;
  nums[11] = 2;

  int val = 4;
  /*
  nums[0] = 3;
  nums[1] = 2;
  nums[2] = 2;
  nums[3] = 3;
  nums[4] = 8;
  nums[5] = 9;
  */

  for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
  {
    printf(" %d \n", *it);
  }

  int len = remve(nums, val);

  printf(" after %d \n", len);
  for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
  {
    printf(" %d \n", *it);
  }

  printf(" output len: %d \n", len);

  return 0;
}
