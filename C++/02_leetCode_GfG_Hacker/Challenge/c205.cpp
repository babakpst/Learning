// Babak Poursartip
// 08/30/2020

// Given an array of positive integers arr,  find a pattern of length m that is
// repeated k or more times.

// A pattern is a subarray (consecutive sub-sequence) that consists of one or
// more values, repeated multiple times consecutively without overlapping. A
// pattern is defined by its length and the number of repetitions.

// Return true if there exists a pattern of length m that is repeated k or more
// times, otherwise return false.

#include <iostream>
#include <vector>
using namespace std;

bool containPattern(vector<int> &arr, const int m, const int k) {
  vector<int> vec(m * k, 0);
  vector<int> vec1(m, 0);
  vector<int> vec2(m, 0);
  int counter = 0;
  int check = 1;
  for (auto c : arr) {
    if (counter < (k * m))
      vec[counter] = c;
    else {
      for (int j = 0; j < (k * m - 1); ++j) {
        vec[j] = vec[j + 1];
      }
      vec[k * m - 1] = c;
    }
    counter++;
    if (counter >= (k * m)) {
      check = 1;
      copy(vec.begin(), vec.begin() + m, vec1.begin());
      for (int i = 0; i < k - 1; ++i) {
        copy(vec.begin() + m * (i + 1), vec.begin() + m * (i + 2),
             vec2.begin());
        if (vec1 != vec2) {
          check = 0;
          break;
        }
      }
      if (check == 1)
        return true;
    }
  }
  return false;
}

int main() {
  // cout << "starts \n";

  // ex1
  // vector<int> arr = {1, 2, 4, 4, 4, 4};
  // int m = 1, k = 3;

  // ex2
  vector<int> arr = {2, 2, 2, 2};
  int m = 2, k = 3;

  bool ans = containPattern(arr, m, k);

  // cout << " answer: " << boolalpha << ans << "\n";

  // cout << "\nends \n";
  return 0;
}
