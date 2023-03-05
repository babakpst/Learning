
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution0 {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> out;
      for (int i = 0; i<numRows; i++)
      {
        vector<int> row(i+1,1);
        
        for (int j = 1; j <i; j++)
        {
          row[j] = out[i-1][j] + out[i-1][j-1];
        }
        out.push_back(row);
      }
    
      return out;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> out(numRows);
      for (int i = 0; i<numRows; i++)
      {
        out[i].resize(i+1,1);
        
        for (int j = 1; j <i; j++)
        {
          out[i][j] = out[i-1][j] + out[i-1][j-1];
        }
      }    
      return out;
    }
};


int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";
 
  Solution t;

  vector<vector<int>> out = t.generate(atoi(argv[1]));

  cout << " answer: "<< endl;
  
  auto lm0 = [](auto y){cout << y << " ";};
    
  auto lm = [&](auto x)
  {
    for_each(x.begin(),x.end(),lm0);
    cout << "\n";
  };

  for_each(out.begin(), out.end(), lm);
  cout << endl;
  std::cout << " done \n";
  return 0;
}