
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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

  // vector<vector<int>> matrix{{2,5,8},{4,0,-1}};
  // vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
  // vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  // vector<vector<int>> matrix{{1,2,3,4,5}};
  // vector<vector<int>> matrix{{1},{2},{3},{4},{5}};
  // vector<vector<int>> matrix{{1}};
  vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  Solution t;

  vector<int> out = t.spiralOrder(matrix);
  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;
  std::cout << " done \n";
  return 0;
}
