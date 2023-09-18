
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <stack>
#include <vector>

using namespace std;

//  did not work
class Solution0
{
 public:
  bool exist(vector<vector<char>>& board, string word)
  {
    vector<vector<pair<int, int>>> loc(word.size());

    int row = board.size(), col = board[0].size();
    vector<vector<int>> visited(row);
    for (int w = 0; w < word.size(); w++)
      for (int i = 0; i < row; i++)
      {
        visited[i].resize(col, 30);
        for (int j = 0; j < col; j++)
          if (word[w] == board[i][j]) loc[w].push_back(make_pair(i, j));
      }

    // print loc array
    for (int i = 0; i < loc.size(); i++)
    {
      cout << i << ": " << word[i] << ": ";
      for (auto pr : loc[i]) cout << " (" << pr.first << ", " << pr.second << ")-";
      cout << endl;
    }

    cout << visited.size() << " size " << visited[0].size() << endl;

    stack<vector<int>> ms;
    for (auto pr : loc[0]) ms.push({pr.first, pr.second, 0});

    while (!ms.empty())
    {
      vector<int> letter = ms.top();
      ms.pop();

      int nextletter = letter[2] + 1;
      cout << letter[0] << " - " << letter[1] << " - " << letter[2] << endl;
      if (letter[2] == word.size() - 1) return true;

      visited[letter[0]][letter[1]] = letter[2];
      cout << " check \n";
      for (int j = 0; j < loc[nextletter].size(); j++)
      {
        if (
          visited[loc[nextletter][j].first][loc[nextletter][j].second] >=
            nextletter &&  // find(begin(pairs),end(pairs),
                           // make_pair(loc[nextletter][j].first,loc[nextletter][j].second))==pairs.end()
          ((loc[nextletter][j].first == letter[0] &&
            (loc[nextletter][j].second == letter[1] + 1 ||
             loc[nextletter][j].second == letter[1] - 1)) ||
           (loc[nextletter][j].second == letter[1] && (loc[nextletter][j].first == letter[0] + 1 ||
                                                       loc[nextletter][j].first == letter[0] - 1))))
        {
          ms.push({loc[nextletter][j].first, loc[nextletter][j].second, nextletter});
          // pairs.insert({loc[nextletter][j].first, loc[nextletter][j].second});
        }
      }
      // print stack
      // for (auto c: ms)
      // cout <<
    }
    return false;
  }
};

//  =========================================
class Solution
{
 private:
  vector<vector<char>> visited;

  int rows, cols;

 public:
  bool exist(vector<vector<char>>& board, string word)
  {
    visited = board;
    rows = board.size(), cols = board[0].size();

    for (int row = 0; row < rows; row++)
      for (int col = 0; col < cols; col++)
      {
        cout << visited[row][col] << endl;
        if (backtracking(row, col, word, 0)) return true;
      }
    return false;
  }

  bool backtracking(int row, int col, string word, int ind)
  {
    cout << row << " - " << col << " - " << ind << " - " << word[ind] << endl;
    if (ind > word.size()) return true;

    if (row < 0 || row == rows || col < 0 || col == cols || visited[row][col] != word[ind])
      return false;

    bool ret = false;
    // mark the path before the next exploration
    visited[row][col] = '#';

    vector<int> rowOffsets{0, 1, 0, -1};
    vector<int> colOffsets{1, 0, -1, 0};
    for (int d = 0; d < 4; ++d)
    {
      ret = backtracking(row + rowOffsets[d], col + colOffsets[d], word, ind + 1);
      if (ret) break;
    }

    /* Step 4). clean up and return the result. */
    visited[row][col] = word[ind];
    return ret;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // ex1
  // vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  // string word = "ABCCED";
  // string word = "ABCCEZ";

  // ex2
  vector<vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "SEE";
  // string word = "SEED";
  // string word = "SEEDE";

  // ex3
  // vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  // string word = "ABCB";

  // ex4
  // vector<vector<char>> board {{'a','a'}};
  // string word = "aa";

  // ex5
  // vector<vector<char>> board {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
  // string word = "ABCESEEEFS";

  Solution t;

  bool out = t.exist(board, word);

  cout << " answer: " << boolalpha << out << endl;

  std::cout << " done \n";
  return 0;
}
