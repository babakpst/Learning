
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

// approach 1: O(m+n)
// class Solution
// {
//   public:
//     void setZeroes(vector<vector<int>> & matrix)
//     {
//       int m = matrix.size();
//       int n = matrix[0].size();
//       set<int> rows, cols;
//       for (int i = 0; i<m; ++i)
//       {
//         for (int j = 0; j<n; ++j)
//         {
//           if (matrix[i][j]==0)
//           {
//             rows.push_back(i);
//             cols.push_back(j);
//           }
//         }
//       }

//       for (int i = 0; i<m; ++i)
//       {
//         for (int j = 0; j<n; ++j)
//         {
//           if ( end(rows) != find(begin(rows), end(rows), i) || end(cols) != find(begin(cols),
//           end(cols), j)  )
//             matrix[i][j] = 0;
//         }
//       }
//     }
// };

// approach 2: space complexity O(m)
// class Solution
// {
//   public:
//     void setZeroes(vector<vector<int>> & matrix)
//     {
//       int m = matrix.size();
//       int n = matrix[0].size();
//       vector<bool> cols(n,false);

//       for (int i = 0; i<m; ++i)
//       {
//         bool zero = false;
//         for (int j = 0; j<n; ++j)
//         {
//           if (matrix[i][j]==0)
//           {
//             cols[j]=true;
//             zero = true;
//           }
//         }
//         if (zero)
//           for (int j = 0; j<n; ++j)
//             matrix[i][j]=0;
//       }

//       for (int j = 0; j<n; j++)
//         if (cols[j])
//           for (int i = 0; i<m; i++)
//             matrix[i][j] =0;
//     }
// };

// approach 3: space complexity O(1)
class Solution
{
 public:
  void setZeroes(vector<vector<int>>& matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    bool firstrow = false;

    for (int j = 0; j < n; ++j)
      if (matrix[0][j] == 0) firstrow = true;

    for (int i = 1; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (matrix[i][j] == 0)
        {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int j = 1; j < n; ++j)
      if (matrix[0][j] == 0)
        for (int i = 1; i < m; ++i) matrix[i][j] = 0;

    for (int i = 1; i < m; ++i)
      if (matrix[i][0] == 0)
        for (int j = 1; j < n; ++j) matrix[i][j] = 0;

    if (matrix[0][0] == 0)
      for (int i = 1; i < m; ++i) matrix[i][0] = 0;

    if (firstrow)
      for (int j = 0; j < n; ++j) matrix[0][j] = 0;
  }
};

int main(int argc, char* argv[])
{
  // vector<vector<int>> matrix{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
  vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};

  Solution sol;
  sol.setZeroes(matrix);

  // print the matrix
  auto lm = [](auto x) {
    for_each(begin(x), end(x), [](auto y) { cout << y << " "; });
    cout << endl;
  };

  for_each(begin(matrix), end(matrix), [&](auto x) { lm(x); });

  cout << " end\n";
  return 0;
}
