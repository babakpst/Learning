
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using myp = pair<int,int>;
class Solution0 {
public:
    void printMe(vector<vector<char>>& out)
    {
        auto lm0 = [](auto y){cout << y << " ";};
        
        auto lm = [&](auto x)
        {
          for_each(x.begin(),x.end(),lm0);
          cout << endl;
        };
        for_each(out.begin(), out.end(), lm);
        cout << endl;
    }

    bool findIsland(vector<vector<char>>& grid, int &rr, int &cc, int row, int col)
    {
      cout << " current: " <<  rr << " " << cc << endl;
      for(int i = rr; i<row; i++)
        for(int j = 0; j<col; j++)
          if (grid[i][j] - '0' == 1 )
          {
            rr = i; cc = j;
            return true;
          }
      return false;
    }


    int numIslands(vector<vector<char>>& grid) {

      int row = grid.size();
      if (row == 0) return 0;
      int col = grid[0].size();

      // printMe(grid);
      
      int out = 2;
      int rr = 0, cc = 0;
      bool tst= findIsland(grid, rr, cc, row, col);
      // BFS
      while (tst)
      {
        queue<myp> qq;
        qq.push(make_pair(rr, cc));
        grid[rr][cc]=out+'0';
        cout << " working on: "<< rr << " " << cc << endl;
        while(!qq.empty())
        {
          myp tmp = qq.front();
          qq.pop();
          cout << " --: "<< tmp.first << " " << tmp.second << endl;

          if ( tmp.first+1 < row  && grid[tmp.first+1][tmp.second] - '0'== 1) 
            {
              qq.push(make_pair(tmp.first+1,tmp.second));
              grid[tmp.first+1][tmp.second]=out+'0';
            }
          if ( tmp.first-1 >=0    && grid[tmp.first-1][tmp.second] - '0'== 1) 
            {
              qq.push(make_pair(tmp.first-1,tmp.second));
              grid[tmp.first-1][tmp.second]=out+'0';
            }
          if ( tmp.second+1 < col && grid[tmp.first][tmp.second+1] - '0'== 1) 
            {
              qq.push(make_pair(tmp.first,tmp.second+1));
              grid[tmp.first][tmp.second+1]=out+'0';
            }
          if ( tmp.second-1 >=0   && grid[tmp.first][tmp.second-1] - '0'== 1) 
            {
              qq.push(make_pair(tmp.first,tmp.second-1));
              grid[tmp.first][tmp.second-1]=out+'0';
            }
        }
        
        printMe(grid);
        tst = findIsland(grid, rr, cc, row, col);
        cout << " next node: " << rr << " " << cc << endl;
        out++;
      }

      return out-2;
    }
};

class Solution {
public:
    void printMe(vector<vector<char>>& out)
    {
        auto lm0 = [](auto y){cout << y << " ";};
        
        auto lm = [&](auto x)
        {
          for_each(x.begin(),x.end(),lm0);
          cout << endl;
        };
        for_each(out.begin(), out.end(), lm);
        cout << endl;
    }

    int numIslands(vector<vector<char>>& grid) {

      int row = grid.size();
      if (row == 0) return 0;
      int col = grid[0].size();

      // printMe(grid);
      
      int out = 2;
      for(int rr = 0; rr<row; rr++)
        for(int cc = 0; cc<col; cc++)
          if (grid[rr][cc]== '1')
          {
            queue<pair<int,int>> qq;
            qq.push(make_pair(rr, cc));
            grid[rr][cc]='0';
            // cout << " working on: "<< rr << " " << cc << endl;
            while(!qq.empty())
            {
              pair<int,int> tmp = qq.front();
              qq.pop();
              // cout << " --: "<< tmp.first << " " << tmp.second << endl;

              if ( tmp.first+1 < row  && grid[tmp.first+1][tmp.second] - '0'== 1) 
                {
                  qq.push(make_pair(tmp.first+1,tmp.second));
                  grid[tmp.first+1][tmp.second]='0';
                }
              if ( tmp.first-1 >=0    && grid[tmp.first-1][tmp.second] - '0'== 1) 
                {
                  qq.push(make_pair(tmp.first-1,tmp.second));
                  grid[tmp.first-1][tmp.second]='0';
                }
              if ( tmp.second+1 < col && grid[tmp.first][tmp.second+1] - '0'== 1) 
                {
                  qq.push(make_pair(tmp.first,tmp.second+1));
                  grid[tmp.first][tmp.second+1]='0';
                }
              if ( tmp.second-1 >=0   && grid[tmp.first][tmp.second-1] - '0'== 1) 
                {
                  qq.push(make_pair(tmp.first,tmp.second-1));
                  grid[tmp.first][tmp.second-1]='0';
                }
            }
            
            // printMe(grid);
            out++;
          }

      return out-2;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

/*
  vector<vector<char>> grid
 {
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
};
*/
/*
  vector<vector<char>> grid
 {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
 };
*/
  
  // vector<vector<char>> grid
  // {{'0','0','0','0','0','0','1'}};
  
  // vector<vector<char>> grid
  // {{'0','1','0'},{'1','0','1'},{'0','1','0'}};
  
  vector<vector<char>> grid
  {{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};


  Solution t;

  int out = t.numIslands(grid);
  cout << " answer: "<< out<< endl;

  std::cout << " done \n";
  return 0;
}