

// Babak Poursartip
// Aug 2, 2022

/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      // bottom-up dynamic programming
      int numSteps = cost.size();


      if (numSteps == 0)
        return 0;
      else if (numSteps == 1)
        return cost[0];
      else if (numSteps == 2)
        return min(cost[0],cost[1]);
      else
      {
        std::vector<int> vec(numSteps+1);
        vec[0]=cost[0];
        vec[1]=min(cost[1],vec[0] + cost[1]);
        for (int n = 2; n<=numSteps; n++)
        {
          int newCost = n==numSteps?0:cost[n];
          vec[n] = min(vec[n-1]+newCost, vec[n-2]+newCost);
        }
        for_each(vec.begin(), vec.end(), [](auto x){std::cout << x << " ";} );
        std::cout << std::endl;
        return vec[numSteps];
      }
    }
};


int main(int argc, char* argv[])
{

  std::cout << " starts ... \n";
  std::vector<int> vec{10,15,20};
  //std::vector<int> vec{1,100,1,1,1,100,1,1,100,1};

  Solution t;
  int output =   t.minCostClimbingStairs(vec);
  std::cout << " output: " << output << std::endl;

  std::cout << " done. \n";
  return 0;
}
