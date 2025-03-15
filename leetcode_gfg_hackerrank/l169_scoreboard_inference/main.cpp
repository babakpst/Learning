

/*

You are spectating a programming contest with N competitors, each trying to independently solve the same set of
programming problems. Each problem has a point value, which is either 1 or 2. On the scoreboard, you observe that the
ith competitor has attained a score of Si, which is a positive integer equal to the sum of the point values of all the
problems they have solved. The scoreboard does not display the number of problems in the contest, nor their point
values. Using the information available, you would like to determine the minimum possible number of problems in the
contest.

Constraints
1≤N≤500,000
1≤Si≤1,000,000,000

Sample test case #1
N = 6
S = [1, 2, 3, 4, 5, 6]
Expected Return Value = 4

Sample test case #2
N = 4
S = [4, 3, 3, 4]
Expected Return Value = 3

Sample test case #3
N = 4
S = [2, 4, 6, 8]
Expected Return Value = 4

Sample Explanation
In the first case, it's possible that there are as few as 4 problems in the contest, for example with point values
[1,1,2,2]. The 6 competitors could have solved the following subsets of problems:

Problem 1 (1 point)
Problem 3 (2 points)
Problems 2 and 3 (1+2=3 points)
Problems 1, 2, and 4 (1+1+2=4 points)
Problems 2, 3, and 4 (1+2+2=5 points)
All 4 problems (1+1+2+2=6 points)
It is impossible for all 6 competitors to have achieved their scores if there are fewer than 4 problems.
In the second case, one optimal set of point values is [1,1,2].
In the third case, one optimal set of point values is [2,2,2,2].

*/

#include <iostream>
#include <vector>

using namespace std;

int getMinProblemCount(int N, vector<int> S)
{
  int n2p = 0;
  int n1p = 0;

  for (auto i : S)
  {
    if (i % 2 == 1 && n1p == 0) n1p = 1;
    if (i / 2 > n2p) n2p = i / 2;
  }

  return n2p + n1p;
}

int main()
{
  cout << " code starts here " << endl;

  // vector<int> S = {1,2,3,4,5,6};
  vector<int> S = {4, 3, 3, 4};
  // vector<int> S = {2,4,6,8};

  int numq = getMinProblemCount(S.size(), S);

  cout << " num of questions: " << numq << endl;

  return 0;
}
