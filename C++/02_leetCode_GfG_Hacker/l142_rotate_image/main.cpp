
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// approach 1: O(mxn) space
class Solution0
{
 public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();

    vector<vector<int>> out(n);
    for (int i = 0; i < n; ++i) out[i].resize(n);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
      {
        cout << i << " " << j << " " << matrix[i][j] << " --";
        cout << j << " " << n - i - 1 << " " << matrix[i][j] << endl;
        out[j][n - i - 1] = matrix[i][j];
      }
    matrix = out;
  }
};

// approach 2: O(1) space
class Solution1
{
 public:
  void rotate(vector<vector<int>> &matrix)
  {
    // print the matrix
    // auto lm = [](auto x) {
    //   for_each(begin(x), end(x), [](auto y) { cout << y << " "; });
    //   cout << endl;
    // };

    int n = matrix.size();

    int tmp0, tmp1;
    for (int i = 0; i < n / 2; ++i)
      for (int k = i; k < n - 1 - i; ++k)
      {
        tmp0 = matrix[k][n - i - 1];
        matrix[k][n - i - 1] = matrix[i][k];

        tmp1 = matrix[n - i - 1][n - k - 1];
        matrix[n - i - 1][n - k - 1] = tmp0;

        tmp0 = matrix[n - k - 1][i];
        matrix[n - k - 1][i] = tmp1;

        matrix[i][k] = tmp0;
        // cout << i << " " << k << endl;
        // for_each(begin(matrix), end(matrix), [&](auto x) { lm(x); });
        // cout << endl;
      }
  }
};

// approach 3: O(1) space
class Solution
{
 public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();

    // transpose
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
      {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
      }

    // reverse
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n / 2; ++j)
      {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][n - 1 - j];
        matrix[i][n - 1 - j] = tmp;
      }
  }
};

int main(int argc, char *argv[])
{
  vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  Solution sol;

  sol.rotate(matrix);

  // print the matrix
  auto lm = [](auto x) {
    for_each(begin(x), end(x), [](auto y) { cout << y << " "; });
    cout << endl;
  };

  cout << " answer: \n";
  for_each(begin(matrix), end(matrix), [&](auto x) { lm(x); });

  cout << " end\n";
  return 0;
}
