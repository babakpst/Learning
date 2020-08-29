
// Babak Poursartip
// 08/28/2020

// STL
// Udemy: Advanced c++

#include <iostream>
#include <vector>
using namespace std;

int main() {
  puts(" starts \n");

  int dim1 = 5, dim2 = 2;
  vector<vector<int>> grid(dim1, vector<int>(dim2, 7));

  for (int row = 0; row < dim1; ++row) {
    for (int col = 0; col < dim2; ++col) {
      cout << grid[row][col] << " ";
    }
    cout << " \n";
  }

  puts(" \n ragged matrix ===========");
  grid[1].push_back(12);

  for (int row = 0; row < grid.size(); ++row) {
    for (int col = 0; col < grid[row].size(); ++col) {
      cout << grid[row][col] << " ";
    }
    cout << " \n";
  }

  puts(" \n ends");

  return 0;
}
