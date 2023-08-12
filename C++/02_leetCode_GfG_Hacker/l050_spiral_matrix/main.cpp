
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution0
{
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    int size = m * n;

    int row0 = 0, row1 = m;
    int col0 = 0, col1 = n - 1;

    vector<int> out(size, 0);

    int i = 0, j = 0;
    int dir = 0;  // 0: row right, 1: col down, 2: row left, 3: col up
    for (int ind = 0; ind < size; ind++)
    {
      // cout << " dir: " << dir << " i: " << i << " j: " << j << endl;
      out[ind] = matrix[i][j];
      i += (dir % 2 == 1) ? (dir % 4 == 1 ? 1 : -1) : 0;
      j += (dir % 2 == 0) ? (dir % 4 == 0 ? 1 : -1) : 0;

      if (j > col1)
      {
        // cout << " m1 \n";
        j = col1;
        dir++;
        i++;
        row1--;
      }
      else if (j < col0)
      {
        // cout << " m2 \n";
        j = col0;
        dir++;
        i--;
        row0++;
      }
      else if (i > row1)
      {
        // cout << " m3 \n";
        i = row1;
        dir++;
        j--;
        col1--;
      }
      else if (i < row0)
      {
        // cout << " m4 \n";
        i = row0;
        dir++;
        j++;
        col0++;
      }
    }
    return out;
  }
};

class Solution1
{
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    int size = m * n;
    int ln = -1, lm = -1;

    vector<int> out(size, 0);

    int i = 0, j = 0;
    int dir = 0;  // 0: row right, 1: col down, 2: row left, 3: col up
    for (int ind = 0; ind < size; ind++)
    {
      // cout << " dir: " << dir << " i: " << i << " j: " << j << endl;
      out[ind] = matrix[i][j];

      if (dir % 4 == 0)  // row right
        (j < n - 1) ? (i += 0, j += 1) : (i += 1, j += 0, dir++, n--);
      else if (dir % 4 == 1)  // col down
        (i < m - 1) ? (i += 1, j += 0) : (i += 0, j += -1, dir++, m--);
      else if (dir % 4 == 2)  // row left
        (j > ln) ? (i += 0, j += -1) : (i += -1, j += 0, dir++, n--);
      else if (dir % 4 == 4)  // col up
    }
    return out;
  }
};

class Solution2
{
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    int rowBoundaryTop = 0, rowBoundaryBot = m;
    int colBoundaryLeft = -1, colBoundaryRight = n - 1;

    vector<int> out(m * n, 0);

    int counter = 0;
    int i = 0, j = 0;
    int cond = 0;
    while (counter < m * n)
    {
      out[counter++] = matrix[i][j];

      cond = -1;
      if (i == rowBoundaryTop && colBoundaryLeft < j && j < colBoundaryRight)
      {
        j++;
        cond = 1;
      }
      else if (i == rowBoundaryTop && j == colBoundaryRight)
      {
        rowBoundaryBot--;
        i++;
        cond = 2;
      }
      else if (i < rowBoundaryBot && j == colBoundaryRight)
      {
        i++;
        cond = 3;
      }
      else if (i == rowBoundaryBot && j == colBoundaryRight)
      {
        colBoundaryLeft++;
        j--;
        cond = 4;
      }
      else if (i == rowBoundaryBot && colBoundaryLeft < j)
      {
        j--;
        cond = 5;
      }
      else if (i == rowBoundaryBot && j == colBoundaryLeft)
      {
        rowBoundaryTop++;
        i--;
        cond = 6;
      }
      else if (i < rowBoundaryBot && i > rowBoundaryTop && j == colBoundaryLeft)
      {
        i--;
        cond = 7;
      }
      else if (i == rowBoundaryTop && j == colBoundaryLeft)
      {
        colBoundaryRight--;
        j++;
        cond = 8;
      }

      cout << rowBoundaryTop << " " << rowBoundaryBot << " -- " << colBoundaryLeft << " "
           << colBoundaryRight << " (" << i << ", " << j << ") >> cond: " << cond << endl;
    }
    return out;
  }
};

class Solution
{
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    int rowBoundaryTop = 0, rowBoundaryBot = m - 1;
    int colBoundaryLeft = 0, colBoundaryRight = n - 1;

    vector<int> out(m * n, -1);

    int counter = 0;
    while (counter < m * n)
    {
      for (int col = colBoundaryLeft; col <= colBoundaryRight; ++col)
        out[counter++] = matrix[rowBoundaryTop][col];

      for (int row = rowBoundaryTop + 1; row <= rowBoundaryBot; ++row)
        out[counter++] = matrix[row][colBoundaryRight];

      if (rowBoundaryBot != rowBoundaryTop)
        for (int col = colBoundaryRight - 1; col >= colBoundaryLeft; --col)
          out[counter++] = matrix[rowBoundaryBot][col];

      if (colBoundaryLeft != colBoundaryRight)
        for (int row = rowBoundaryBot - 1; row > rowBoundaryTop; --row)
          out[counter++] = matrix[row][colBoundaryLeft];
      ++rowBoundaryTop;
      --rowBoundaryBot;
      ++colBoundaryLeft;
      --colBoundaryRight;
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
  vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  // vector<vector<int>> matrix{{1,2,3,4,5}};
  // vector<vector<int>> matrix{{1},{2},{3},{4},{5}};
  // vector<vector<int>> matrix{{1}};

  Solution t;

  vector<int> out = t.spiralOrder(matrix);
  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;
  std::cout << " done \n";
  return 0;
}
