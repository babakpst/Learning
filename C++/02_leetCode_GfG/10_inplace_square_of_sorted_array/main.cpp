#include <iostream>
#include <math.h>
#include <vector>
/*
class Solution {
public:
  std::vector<int> sortedSquares(std::vector<int> &A) {
    int i;
    int j = A.size() - 1;
    while (j >= 0) {
      if (abs(A[j]) < abs(A[0])) {
        std::swap(A[0], A[j]);
        A[j] = pow(A[j], 2);
        --j;
        i = 0;
        while (abs(A[i]) < abs(A[i + 1]) && i + 1 < j) {
          std::swap(A[i], A[i + 1]);
          ++i;
        }

      } else {
        A[j] = pow(A[j], 2);
        --j;
      }
    }
    return A;
  }
};
*/

class Solution {
public:
  std::vector<int> sortedSquares(std::vector<int> &A) {
    std::vector<int> res(A.size());
    int i = 0, j = A.size() - 1, k = A.size() - 1;
    while (i != j) {
      if (abs(A[i]) > abs(A[j])) {
        res[k] = pow(A[i], 2);
        i++;
      } else {
        res[k] = pow(A[j], 2);
        j--;
      }
      k--;
    }
    res[k] = pow(A[j], 2);
    return res;
  }
};

int main() {

  std::cout << "starts ... \n";

  std::vector<int> A{-3, -3, -2, 1};
  // std::vector<int> A{-4, -1, 0, 3, 10};
  // std::vector<int> A{-7, -3, 2, 3, 11};
  // std::vector<int> A{-5, -4, 1, 2, 5};
  // std::vector<int> A{-9, -7, -5, -3, -1, 2, 4, 4, 7, 10};
  // std::vector<int> A{-2, 0};
  // std::vector<int> A{-1, 1};

  std::cout << " here is the vector: \n";
  for (auto c : A)
    std::cout << c << " ";
  std::cout << std::endl;

  Solution sol;
  A = sol.sortedSquares(A);

  std::cout << " here is the squared vector: \n";
  for (auto c : A)
    std::cout << c << " ";
  std::cout << std::endl;

  std::cout << "finished! \n";
  return 0;
}
