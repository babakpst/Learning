

// babak poursartip
// Aug 8, 2022

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {

    std::vector<int> root(n);
    std::iota(root.begin(), root.end(), 0);
    
    for (int i =  0; i<edges.size(); i++)
    {
      int p = edges[i][0];
      int q = edges[i][1];
      int rootp = root[p]; 
      int rootq = root[q]; 
      if (rootp != rootq)
        for (auto it = root.begin(); it!=root.end(); it++)
        {
          if (*it == rootq)
            *it = rootp;
        }
    }
    
    std::set<int> connected;
    for (auto it = root.begin(); it!=root.end(); it++)
    {
       connected.insert(*it);
    }
    return connected.size();
   }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  //int n = 5;
  //std::vector<std::vector<int>> vec{{0,1},{0,2},{0,3},{1,4}};

  //int n = 2;
  //std::vector<std::vector<int>> vec{{0,1}};

  int n = 5;
  std::vector<std::vector<int>> vec{{0,1},{1,2},{3,4}};

  Solution t;
  int out = t.countComponents(n,vec);
  std::cout << " answer: "<<  out << std::endl;
  

  std::cout << " done. \n";  
  return 0;
}
