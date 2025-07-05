
/*
Revenue Milestones
We keep track of the revenue Facebook makes every day, and we want to know on what days Facebook hits certain revenue
milestones. Given an array of the revenue on each day, and an array of milestones Facebook wants to reach, return an
array containing the days on which Facebook reached every milestone. Signature int[] getMilestoneDays(int[] revenues,
int[] milestones) Input revenues is a length-N array representing how much revenue FB made on each day (from day 1 to
day N). milestones is a length-K array of total revenue milestones. Output Return a length-K array where K_i is the day
on which FB first had milestones[i] total revenue. If the milestone is never met, return -1. Example revenues = [10, 20,
30, 40, 50, 60, 70, 80, 90, 100] milestones = [100, 200, 500] output = [4, 6, 10] Explanation On days 4, 5, and 6, FB
has total revenue of $100, $150, and $210 respectively. Day 6 is the first time that FB has >= $200 of total revenue.

*/

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

int binary_search(int target, vector<int>& revenue)
{
  int left = 0;
  int right = revenue.size() - 1;

  int ret = -1;
  while (left <= right)
  {
    int middle = (left + right) / 2;
    cout << " target: " << target << " middle: " << middle << " rev: " << revenue[middle] << endl;

    if (revenue[middle] == target)
      return middle;
    else if (revenue[middle] > target)
    {
      ret = middle;
      right = middle - 1;
    }
    else if (revenue[middle] < target)
      left = middle + 1;
  }

  return ret;
}

vector<int> getMilestoneDays(vector<int> revenues, vector<int> milestones)
{
  // edge

  for (int i = 1; i < revenues.size(); ++i)
  {
    revenues[i] += revenues[i - 1];
  }

  vector<int> ret(milestones.size());

  for (int i = 0; i < milestones.size(); ++i)
  {
    ret[i] = binary_search(milestones[i], revenues) + 1;
  }

  return ret;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector<int> array)
{
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++)
  {
    if (i != 0)
    {
      cout << ", ";
    }
    cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector<int>& expected, vector<int>& output)
{
  int expected_size = expected.size();
  int output_size = output.size();
  bool result = true;
  if (expected_size != output_size)
  {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++)
  {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result)
  {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else
  {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected);
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl;
  }
  test_case_number++;
}

int main()
{
  // Testcase 1
  int n_1 = 5, k_1 = 4;
  vector<int> revenues_1{100, 200, 300, 400, 500};
  vector<int> milestones_1{300, 800, 1000, 1400};
  vector<int> expected_1{2, 4, 4, 5};
  vector<int> output_1 = getMilestoneDays(revenues_1, milestones_1);
  check(expected_1, output_1);

  // Testcase 2
  int n_2 = 6, k_2 = 5;
  vector<int> revenues_2{700, 800, 600, 400, 600, 700};
  vector<int> milestones_2{3100, 2200, 800, 2100, 1000};
  vector<int> expected_2{5, 4, 2, 3, 2};
  vector<int> output_2 = getMilestoneDays(revenues_2, milestones_2);
  check(expected_2, output_2);

  // Add your own test cases here
}
