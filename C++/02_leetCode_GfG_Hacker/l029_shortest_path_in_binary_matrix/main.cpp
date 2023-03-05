
// babak poursartip

// Aug 17, 2022

// shortest path in binary matrix

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    
      int x = 0, y = 0;
      int size = grid.size();
      if (grid[x][y] == 1 || grid[size-1][size-1] == 1 )
        return -1;
        
      //std::cout << " size: " << size << "\n";
      std::queue<std::pair<int,int>> qq;
     
      qq.push(std::make_pair(x,y));
      grid[x][y] = 1;

      while( !qq.empty() )
      {
       
        std::pair<int,int> node = qq.front();
        qq.pop();

        x = node.first, y = node.second;
        int dist = grid[x][y];
        std::cout << "checking (" << x << ", " << y << ") - " << dist << "\n";

        for (int i = -1; i<2; i++ ){
          for (int j = -1; j<2; j++ ){
            int x2 = x + i;
            int y2 = y + j;
            
            if (x2 !=size && x2 >= 0 && y2 != size && y2>= 0 && grid[x2][y2] == 0){
              qq.push(std::make_pair(x2,y2));
              grid[x2][y2] = dist + 1;
            }
          }
        }

       /*
       for (int i = 0; i<size; i++)
       {
         for (int j = 0; j<size; j++)
         {
           std::cout << setw(12) << grid[i][j] << " ";
         }
         std::cout << std::endl;
       }
       std::cout << std::endl;
       */
      }


      return grid[size-1][size-1]==0?-1:grid[size-1][size-1]; 
    }
};




class Solution1 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    
      int x = 0, y = 0;
      int size = grid.size();
      if (grid[x][y] == 1 || grid[size-1][size-1] == 1 )
        return -1;
        
      //std::cout << " size: " << size << "\n";
      std::queue<std::pair<int,int>> qq;

      std::vector<std::vector<bool>> visited(size); // each cell is a node
      std::vector<std::vector<int>> dist(size);
      
      for (int i = 0; i<size; i++)
      {
        visited[i].resize(size,false);
        dist[i].resize(size, INT_MAX);
      }
      
      qq.push(std::make_pair(x,y));
      visited[x][y] = true;
      dist[x][y] = 0;

      while( !qq.empty() )
      {
       
        std::pair<int,int> node = qq.front();
        qq.pop();

        x = node.first, y = node.second;
        //std::cout << "checking (" << x << ", " << y << ")\n";

        if (x+1!=size && y+1!=size && grid[x+1][y+1] != 1 && visited[x+1][y+1] == false){
          qq.push(std::make_pair(x+1,y+1));
          visited[x+1][y+1] = true;
          dist[x+1][y+1] = dist[x][y] + 1;
          //std::cout << " add 1 " << x+1 << " " << y+1 << "\n";
        }
        if (x+1!=size              && grid[x+1][y  ] != 1 && visited[x+1][y  ] == false){
          qq.push(std::make_pair(x+1,y));
          visited[x+1][y  ] = true;
          dist[x+1][y  ] = dist[x][y] + 1;
          //std::cout << " add 2 " << x+1 << " " << y   << "\n";
        }
        if (             y+1!=size && grid[x  ][y+1] != 1 && visited[x  ][y+1] == false){
          qq.push(std::make_pair(x,y+1));
          visited[x  ][y+1] = true;
          dist[x  ][y+1] = dist[x][y] + 1;
          //std::cout << " add 3 " << x   << " " << y+1 << "\n";
        }
        if (x-1>=0                 && grid[x-1][y  ] != 1 && visited[x-1][y  ] == false){
          qq.push(std::make_pair(x-1,y  ));
          visited[x-1][y  ] = true;
          dist[x-1][y  ] = dist[x][y] + 1;
          //std::cout << " add 4 " << x-1 << " " << y   << "\n";
        }
        if (             y-1>=0    && grid[x  ][y-1] != 1 && visited[x  ][y-1] == false){
          qq.push(std::make_pair(x  ,y-1));
          visited[x  ][y-1] = true;
          dist[x  ][y-1] = dist[x][y] + 1;
          //std::cout << " add 5 " << x   << " " << y-1 << "\n";
        }
        if (x+1!=size && y-1>=0    && grid[x+1][y-1] != 1 && visited[x+1][y-1] == false){
          qq.push(std::make_pair(x+1,y-1));
          visited[x+1][y-1] = true;
          dist[x+1][y-1] = dist[x][y] + 1;
          //std::cout << " add 6 " << x+1 << " " << y-1 << "\n";
        }
        if (x-1>=0    && y+1!=size && grid[x-1][y+1] != 1 && visited[x-1][y+1] == false){
          qq.push(std::make_pair(x-1,y+1));
          visited[x-1][y+1] = true;
          dist[x-1][y+1] = dist[x][y] + 1;
          //std::cout << " add 7 " << x-1 << " " << y+1 << "\n";
        }
        if (x-1>=0    && y-1>=0    && grid[x-1][y-1] != 1 && visited[x-1][y-1] == false){
          qq.push(std::make_pair(x-1,y-1));
          visited[x-1][y-1] = true;
          dist[x-1][y-1] = dist[x][y] + 1;
          //std::cout << " add 8 " << x-1 << " " << y-1 << "\n";
        }

       /*
       for (int i = 0; i<size; i++)
       {
         for (int j = 0; j<size; j++)
         {
           std::cout << setw(12) << dist[i][j] << " ";
         }
         std::cout << std::endl;
       }
       std::cout << std::endl;
       */
      }


      return dist[size-1][size-1]==INT_MAX?-1:dist[size-1][size-1]+1;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts \n";

  //std::vector<vector<int>> grid{{0,0,0},{1,1,0},{1,1,0}};
  //std::vector<vector<int>> grid{{1,0,0},{1,1,0},{1,1,0}};
  //std::vector<vector<int>> grid{{0,0,0},{0,1,0},{0,0,0}};
  //std::vector<vector<int>> grid{{0,1,1,0,0,0},{0,1,0,1,1,0},{0,1,1,0,1,0},{0,0,0,1,1,0},{1,1,1,1,1,0},{1,1,1,1,1,0}};
  //std::vector<vector<int>> grid{{0,1,1,0,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,1,1,0},{1,1,1,1,0}};
  std::vector<vector<int>> grid{{0,0,0,0,1},{1,0,0,0,0},{0,1,0,1,0},{0,0,0,1,1},{0,0,0,1,0}};
  
  std::vector<vector<int>> grid2 = grid;
  Solution t;
  int out = t.shortestPathBinaryMatrix(grid);
  std::cout << " answer: " << out << std::endl;

  Solution1 t2;
  int out2 = t2.shortestPathBinaryMatrix(grid2);
  std::cout << " answer: " << out2 << std::endl;

  std::cout << " done. \n";  
  return 0;
}
