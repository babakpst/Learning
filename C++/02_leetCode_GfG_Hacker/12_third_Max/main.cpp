#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int thirdMax(vector<int> &nums) {
    long long max3 = INT64_MIN, max2 = INT64_MIN, max1 = INT64_MIN;
    for (auto c : nums) {
      if (c > max1) {
        max3 = max2;
        max2 = max1;
        max1 = c;
      } else if (c > max2 && c != max1) {
        max3 = max2;
        max2 = c;
      } else if (c > max3 && c != max2 && c != max1) {
        max3 = c;
      }
    }
    int out = max3;
    if (max3 == INT64_MIN)
      out = max1;

    return out;
  }
};

int main() {

  std::cout << "starts ... \n";

  // std::vector<int> A{3, 2, 1};
  // std::vector<int> A{2, 2, 3, 1};
  std::vector<int> A{1, 2};
  // std::vector<int> A{1, 2, 2, 5, 3, 5};
  // std::vector<int> A{1, 2, -2147483648};

  std::cout << " here is the vector: \n";
  for (auto c : A)
    std::cout << c << " ";
  std::cout << std::endl;

  Solution sol;
  int output = sol.thirdMax(A);
  std::cout << " results: " << output << endl;
  std::cout << "finished! \n";
  return 0;
}