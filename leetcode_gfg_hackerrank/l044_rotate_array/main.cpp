
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution2
{
 public:
  void rotate(vector<int>& nums, int k)
  {
    int size = nums.size();
    cout << " size: " << size << " " << k % size << endl;
    k = k % size;
    cout << " k: " << k << " mod: " << size % k << endl;
    if (size == 1 || k == 0 || k == size) return;

    int rep = (size % k ? 1 : k);
    // int rep = (size%k ? size%k : k);
    // int rep =size%k;

    for (int i = 0; i < rep; i++)
    {
      cout << " ==========================i: " << i << " rep: " << rep << endl;
      int i1 = i;
      int i2 = i1 + k;
      int temp1 = nums[i1];
      int temp2 = nums[i1];

      while (i2 != i)
      {
        // cout << i1 << " " << i2 << endl;
        temp1 = nums[i2];
        nums[i2] = temp2;
        temp2 = temp1;
        i1 += k;
        if (i1 >= size) i1 = i1 % size;
        i2 += k;
        if (i2 >= size) i2 = i2 % size;

        cout << " temp2: " << setw(4) << temp2 << " i1: " << setw(4) << i1 << " i2: " << setw(4) << i2;
        cout << "  --- answer: ";
        // for_each(nums.begin(), nums.end(), [](auto x){cout << setw(4)<< x << " ";});
        for (int ii = 0; ii < size; ii++)
        {
          if (ii == i1)
            cout << " *" << setw(2) << nums[ii] << " ";
          else
            cout << setw(4) << nums[ii] << " ";
        }
        cout << endl;
      }
      nums[i] = temp2;
    }
  }
};

// working but slow
class Solution0
{
 public:
  void rotate(vector<int>& nums, int k)
  {
    int size = nums.size();
    vector<int> out(nums);

    k = k % size;
    for (int i = 0; i < size; i++)
    {
      int index = i + k;
      index = (index < size ? index : index - size);
      nums[index] = out[i];
    }
  }
};

// class Solution_mine {
class Solution
{
 public:
  void rotate(vector<int>& nums, int k)
  {
    int size = nums.size();
    // cout << " size: " << size << " " << k%size << endl;
    k = k % size;
    // cout << " k: " << k  << " mod: " << size%k << endl;
    if (size == 1 || k == 0) return;

    bool tst = true;
    int i = 0;
    int rep = 0;
    int count = 0;

    while (tst)
    {
      // cout << " ==========================i: " << i << " rep: " << rep << endl;
      int i1 = i;
      int i2 = i1 + k;
      int temp1 = nums[i1];
      int temp2 = nums[i1];

      while (i2 != i)
      {
        // cout << i1 << " " << i2 << endl;
        cout << " count: " << ++count << endl;
        temp1 = nums[i2];
        nums[i2] = temp2;
        temp2 = temp1;

        i1 += k;
        if (i1 >= size) i1 = i1 % size;

        i2 += k;
        if (i2 >= size)
        {
          i2 = i2 % size;
          rep++;
        }

        // cout << " temp2: " << setw(4) << temp2  <<" i1: " << setw(4) << i1 << " i2: " << setw(4)<< i2;
        // cout << "  --- answer: ";
        // for_each(nums.begin(), nums.end(), [](auto x){cout << setw(4)<< x << " ";});
        // for(int ii = 0; ii<size; ii++)
        // {
        // if (ii == i1)
        // cout<<" *" <<setw(2) << nums[ii] << " ";
        // else
        // cout<< setw(4) << nums[ii] << " ";
        // }
        // cout << endl;
      }
      nums[i] = temp2;
      if (rep >= k)
      {
        tst = false;
      }
      i++;
    }
  }
};

// leetcode sol
class Solutionppp
{
 public:
  void rotate(vector<int>& nums, int k)
  {
    k = k % nums.size();
    int count = 0;
    for (int start = 0; count < nums.size(); start++)
    {
      cout << " here \n";
      int current = start;
      int prev = nums[start];
      do
      {
        cout << " here and " << count << endl;

        int next = (current + k) % nums.size();
        int temp = nums[next];
        nums[next] = prev;
        prev = temp;
        current = next;
        count++;
      } while (start != current);
    }
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{1,2,3,4,5,6,7};
  // int k = 3;

  // vector<int> nums{-1,-100,3,99};
  // int k = 2;

  // vector<int> nums{-1,-100};
  // int k = 2;

  // vector<int> nums{1,2,3,4,5,6};
  // int k = 4;

  vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
  int k = 38;

  Solution t;

  cout << " nums: " << endl;
  for_each(nums.begin(), nums.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  t.rotate(nums, k);

  // cout << " answer: " << out << endl;
  cout << " answer: " << endl;
  for_each(nums.begin(), nums.end(), [](auto x) { cout << x << " "; });
  cout << endl;
  std::cout << " done \n";
  return 0;
}
