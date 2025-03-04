#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

int remve(std::vector<int> &nums, int val)
{
  int len = nums.size();
  if (len == 0) return 0;
  std::vector<int>::iterator it_end = nums.end();
  --it_end;
  while (*it_end == val)
  {
    --it_end;
    --len;
    printf(" while %d \n", len);
    if (len == 0) return 0;
  }
  printf("\n before loop len:%d end: %d\n\n", len, *it_end);
  if (it_end <= nums.begin()) return len;

  for (std::vector<int>::iterator it = nums.begin(); it != (it_end + 1); ++it)
  {
    printf(" before if it: %d  val: %d len: %d\n", *it, val, len);
    if (*it == val)
    {
      printf(" before swap it: %d end: %d\n", *it, *it_end);
      while (*it_end == *it && it != it_end)
      {
        --it_end;
        --len;
      }
      std::swap(*it, *it_end);

      if (it != it_end)
      {
        --it_end;
        --len;
      }
      else
      {
        while (*it_end == val)
        {
          --it_end;
          --len;
        }
        break;
      }
      printf(" after swap it: %d end: %d len: %d\n", *it, *it_end, len);
    }
    printf(" length: %d \n", len);
  }

  return len;
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
