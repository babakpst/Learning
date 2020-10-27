#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int heightChecker(vector<int> &heights) {
    vector<int> tar(heights);
    sort(tar.begin(), tar.end());
    int out = 0;
    for (int i = 0; i < tar.size(); ++i)
      if (tar[i] != heights[i])
        ++out;
    return out;
  }
};

int main() {

  std::cout << "starts ... \n";

  // std::vector<int> A{1, 1, 4, 2, 1, 3};
  // std::vector<int> A{5, 1, 2, 3, 4};
  std::vector<int> A{1, 2, 3, 4, 5};

  std::cout << " here is the vector: \n";
  for (auto c : A)
    std::cout << c << " ";
  std::cout << std::endl;

  Solution sol;
  int output = sol.heightChecker(A);
  std::cout << " results: " << output << endl;
  std::cout << "finished! \n";
  return 0;
}