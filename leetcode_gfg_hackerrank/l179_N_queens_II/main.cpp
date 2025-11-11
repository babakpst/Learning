
// babak poursartip
// July 21, 2025

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

// original solution
class Solution
{
 private:
  int size;

 public:
  int totalNQueens(int n)
  {
    // declaring unordered sets
    unordered_set<int> diagonals, antiDiagonals, cols;
    size = n;
    return backtrack(0, diagonals, antiDiagonals, cols);
  }

 private:
  int backtrack(int row, unordered_set<int>& diagonals, unordered_set<int>& antiDiagonals, unordered_set<int>& cols)
  {
    // Base case - N queens have been placed
    if (row == size)
    {
      return 1;
    }
    int solutions = 0;
    for (int col = 0; col < size; col++)
    {
      int currDiagonal = row - col;
      int currAntiDiagonal = row + col;

      // If the queen is not placeable
      if (cols.find(col) != cols.end() || diagonals.find(currDiagonal) != diagonals.end() ||
          antiDiagonals.find(currAntiDiagonal) != antiDiagonals.end())
      {
        continue;
      }
      // "Add" the queen to the board
      cols.insert(col);
      diagonals.insert(currDiagonal);
      antiDiagonals.insert(currAntiDiagonal);
      // Move on to the next row with the updated board state
      solutions += backtrack(row + 1, diagonals, antiDiagonals, cols);
      // "Remove" the queen from the board since we have already
      // explored all valid paths using the above function call
      cols.erase(col);
      diagonals.erase(currDiagonal);
      antiDiagonals.erase(currAntiDiagonal);
    }
    return solutions;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  string out = t.totalNQueens(argv[2]);

  cout << " answer: " << out << endl;

  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
