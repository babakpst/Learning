
// babak poursartip
// Aug 9, 2022

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:

    int earliestAcq(vector<vector<int>>& logs, int n) {

      //if (n-1 != logs.size())
      //  return -1;

      int time = 0;
      vector<int> root(n);
      iota(root.begin(), root.end(), 0);
      
      // sort logs
      auto sortcol = [](const vector<int>& v1, const vector<int>& v2){return v1[0] < v2[0];};

      sort(logs.begin(), logs.end(), sortcol);


      for (auto it = logs.begin(); it != logs.end(); it++)
      {
        int temp = (*it)[0];
        int p  = (*it)[1];
        int q  = (*it)[2];
        int rootp = root[p];
        int rootq = root[q];
        if (rootp != rootq)
        {
          //(temp>time)?(time = temp):1;
          time = (temp<time)?time:temp;
          for (auto it2 = root.begin(); it2 != root.end(); it2++)
            if (*it2 == rootq)
              *it2 = rootp;
        }
        //else 
        //  return -1
        //std::cout << " time: " << time << " - ";
        //for_each(root.begin(),root.end(), [](auto x){std::cout << x << " ";});
        //std::cout << std::endl;

      }
      
      int treeRoot = root[0];
      for (auto it = root.begin(); it != root.end(); it++)
        if (*it != treeRoot)
          return -1;
      
      return time;        
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  //int n = 4;
  //std::vector<vector<int>> logs{{0,2,0},{1,0,1},{3,0,3},{4,1,2},{7,3,1}};

  int n = 4;
  std::vector<vector<int>> logs{{7,3,1},{2,3,0},{3,2,1},{6,0,1},{0,2,0},{4,3,2}};





  Solution t;
  int out = t.earliestAcq(logs,n);
  std::cout << " answer: " << out << std::endl;

  std::cout << " done. \n";
  return 0;
}
