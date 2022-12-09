

// babak poursartip
// Dec 03, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      vector<unordered_set<char>> row(9), col(9);
      vector<vector<unordered_set<char>>> sq(3);
      for (int i = 0; i<sq.size(); i++)
        sq[i].resize(3);

      for (int i = 0; i<board.size(); i++)
        for (int j = 0; j<board[i].size(); j++)
          if (board[i][j] != '.')
          {
            {
              // find in row
              auto it = row[i].find(board[i][j]);
              if ( it != end(row[i]) ) return false;
              else row[i].insert(board[i][j]);
            }
            {
              // find in col
              auto it = col[j].find(board[i][j]);
              if ( it != end(col[j]) ) return false;
              else col[j].insert(board[i][j]);
            }
            {
              // find in sq
              int ii = i/3, jj = j/3;

              auto it = sq[ii][jj].find(board[i][j]);
              if ( it != end(sq[ii][jj]) ) return false;
              else sq[ii][jj].insert(board[i][j]);
            }
          }
        return true;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<vector<char> > board
  // {{'5','3','.','.','7','.','.','.','.'}
  // ,{'6','.','.','1','9','5','.','.','.'}
  // ,{'.','9','8','.','.','.','.','6','.'}
  // ,{'8','.','.','.','6','.','.','.','3'}
  // ,{'4','.','.','8','.','3','.','.','1'}
  // ,{'7','.','.','.','2','.','.','.','6'}
  // ,{'.','6','.','.','.','.','2','8','.'}
  // ,{'.','.','.','4','1','9','.','.','5'}
  // ,{'.','.','.','.','8','.','.','7','9'}};
{{'8','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};


  Solution t;

  bool out = t.isValidSudoku(board);

  cout << " answer: " << boolalpha << out << endl;

  std::cout << " done \n";
  return 0;
}
