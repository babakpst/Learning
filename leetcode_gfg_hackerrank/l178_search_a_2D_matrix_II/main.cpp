
// babak poursartip
// July 20, 2025

/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the
following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// non-recursive
class Solution0
{
 public:
  bool search(vector<vector<int>>& matrix, int target, int i, int j, int m, int n, int dim1, int dim2)
  {
    if (i >= m || j >= n) return false;
    cout << i << " " << j << " " << dim1 << " " << dim2 << " " << matrix[i][j] << endl;
    if (matrix[i][j] == target) return true;

    // if ((j+1< n && i+1< m && matrix[i+1][j+1] < target) ) return search(matrix,target, i+1, j+1, m, n);
    // else
    // {
    //   if ((i+1< m && matrix[i+1][0] < target ) ) return search(matrix,target, i+1, 0, m, n);
    //   if ((j+1< n && matrix[0][j+1] < target) ) return search(matrix,target, 0, j+1, m, n);
    // }
    return (j + 1 < n && i + 1 < m && matrix[i + 1][j + 1] <= target)
               ? search(matrix, target, i + 1, j + 1, m, n, i + 1, j + 1)
               : (search(matrix, target, 0, j + 1, m, n, 0, j + 1) || search(matrix, target, i + 1, 0, m, n, i + 1, 0));
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target)
  {
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = 0;
    int dim1 = 0, dim2 = 0;

    return search(matrix, target, i, j, m, n, dim1, dim2);
  }
};

class Solution
{
 public:
  bool search(vector<vector<int>>& matrix, int target, int i, int j, int dim1, int dim2, int m, int n)
  {
    if (i > m || j > n || target < matrix[dim1][dim2] || matrix[m][n] < target)
      return false;
    else if (matrix[i][j] == target)
      return true;

    cout << i << " " << j << " " << m << " " << n << " " << matrix[i][j] << endl;

    // if ((j+1< n && i+1< m && matrix[i+1][j+1] < target) ) return search(matrix,target, i+1, j+1, m, n);
    // else
    // {
    //   if ((i+1< m && matrix[i+1][0] < target ) ) return search(matrix,target, i+1, 0, m, n);
    //   if ((j+1< n && matrix[0][j+1] < target) ) return search(matrix,target, 0, j+1, m, n);
    // }
    return (j + 1 <= n && i + 1 <= m && matrix[i + 1][j + 1] <= target)
               ? search(matrix, target, i + 1, j + 1, dim1, dim2, m, n)
               : (search(matrix, target, i + 1, dim2, i + 1, dim2, m, j) ||
                  search(matrix, target, dim1, j + 1, dim1, j + 1, i, n));
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target)
  {
    int m = matrix.size(), n = matrix[0].size();
    // if (target> matrix[m-1][n-1]) return false;

    int i = 0, j = 0;
    int dim1 = 0, dim2 = 0;

    return search(matrix, target, i, j, dim1, dim2, m - 1, n - 1);
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  vector<vector<int>> matrix{
      {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
  int target = 30;

  bool out = t.searchMatrix(matrix, target);

  cout << " answer: " << out << endl;

  // cout << " answer: " << endl;
  // for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  // cout << endl;

  std::cout << " done \n";
  return 0;
}
