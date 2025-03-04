
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// my solution
class Solution2
{
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat)
  {
    int mm = mat.size();
    int nn = mat[0].size();

    vector<int> out(mm * nn);
    int index = 0;
    int i = 0, j = 0;
    int diag = 0;
    int num = 0;  // num elements in the diagonal
    int inc = 1;
    while (diag < mm + nn - 1)
    {
      if (diag % 2 == 0)
      {
        i = diag > mm - 1 ? mm - 1 : diag;
        j = diag > mm - 1 ? diag - (mm - 1) : 0;
      }
      else
      {
        j = diag > nn - 1 ? nn - 1 : diag;
        i = diag > nn - 1 ? diag - (nn - 1) : 0;
      }

      // cout<< endl << " diag: " << diag << " i: " << i << " j: " << j << endl;
      while (i >= 0 && i < mm && j >= 0 && j < nn)
      {
        // cout <<  " diag: " << diag <<  " index: " << index << " i: " << i << " j: " << j << endl;
        out[index++] = mat[i][j];
        if (diag % 2 == 0)
        {
          i--;
          j++;
        }
        else
        {
          i++;
          j--;
        }
      }
      diag++;
    }
    return out;
  }
};

// sol from the website
class Solution
{
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat)
  {
    int mm = mat.size();
    if (mat.empty() || mm == 0)
    {
      vector<int> out{0};
      return out;
    }

    int nn = mat[0].size();

    vector<int> out(mm * nn);

    int index = 0;
    int row = 0, col = 0;
    int dir = 1;  // 1 up, 0 down

    while (row < mm && col < nn)
    {
      // cout << " adding row: " << row << " col: " << col << endl;
      out[index++] = mat[row][col];

      int row2 = row + (dir == 1 ? -1 : 1);
      int col2 = col + (dir == 1 ? 1 : -1);

      // cout << " ----test  row: " << row2 << " col: " << col2 << " dir: " << dir << endl;

      // if getting out of bound, find the new head
      if (row2 < 0 || row2 == mm || col2 < 0 || col2 == nn)
      {
        if (dir == 1)
        {
          row += (col == nn - 1 ? 1 : 0);
          col += (col < nn - 1 ? 1 : 0);
          // cout << " ----mod 1 row: " << row << " col: " << col << endl;
        }
        else
        {
          col += (row == mm - 1 ? 1 : 0);
          row += (row < mm - 1 ? 1 : 0);
          // cout << " ----mod 0 row: " << row << " col: " << col << endl;
        }
        dir = 1 - dir;
      }
      else  // still within the bound
      {
        row = row2;
        col = col2;
      }
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  std::vector<vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // std::vector<vector<int>> mat{{1,2},{3,4}};
  /*
  std::vector<vector<int>> mat;
  mat.resize(1);
  mat[0].resize(2);
  mat[0][0] = 2;
  mat[0][1] = 3;
  */
  Solution t;

  vector<int> out = t.findDiagonalOrder(mat);

  cout << " answer: \n";

  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
