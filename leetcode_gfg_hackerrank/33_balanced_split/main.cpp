/*
Balanced Split
Given an array of integers (which may include repeated integers), determine if there's a way to split the array into two
subsequences A and B such that the sum of the integers in both arrays is the same, and all of the integers in A are
strictly smaller than all of the integers in B. Note: Strictly smaller denotes that every integer in A must be less
than, and not equal to, every integer in B. Signature bool balancedSplitExists(int[] arr) Input All integers in array
are in the range [0, 1,000,000,000]. Output Return true if such a split is possible, and false otherwise. Example 1 arr
= [1, 5, 7, 1] output = true We can split the array into A = [1, 1, 5] and B = [7]. Example 2 arr = [12, 7, 6, 7, 6]
output = false
We can't split the array into A = [6, 6, 7] and B = [7, 12] since this doesn't satisfy the requirement that all integers
in A are smaller than all integers in B.
*/

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

bool balancedSplitExists(vector<int>& arr)
{
  if (arr.size() == 0) return false;

  sort(arr.begin(), arr.end());

  long long total_sum = 0;
  for (auto x : arr)
  {
    total_sum += x;
    cout << x << " ";
  }
  cout << endl;
  // if total_sum not even, no way we can split the array.
  if (total_sum % 2) return false;

  bool ret = false;

  long long sum = 0;
  int i = 0;
  while (total_sum >= sum)
  {
    sum += arr[i];
    total_sum -= arr[i];

    if (sum == total_sum && arr[i] < arr[i + 1]) ret = true;
    i++;
  }

  return ret;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) { cout << "[\"" << str << "\"]"; }

int test_case_number = 1;

void check(bool expected, bool output)
{
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result)
  {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else
  {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl;
  }
  test_case_number++;
}

int main()
{
  // Testcase 1
  vector<int> arr_1{2, 1, 2, 5};
  bool expected_1 = true;
  bool output_1 = balancedSplitExists(arr_1);
  check(expected_1, output_1);

  // Testcase 2
  vector<int> arr_2{3, 6, 3, 4, 4};
  bool expected_2 = false;
  bool output_2 = balancedSplitExists(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here

  return 0;
}
