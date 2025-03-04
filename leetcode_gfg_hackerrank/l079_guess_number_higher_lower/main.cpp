
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
static int pick;

int guess(int num)
{
  if (num == pick)
    return 0;
  else if (num > pick)
    return -1;
  else if (num < pick)
    return 1;
  return 10;
}

class Solution
{
 public:
  int guessNumber(int n)
  {
    if (n == 1) return 1;
    int left = 1, right = n;
    long long int mid;
    while (left <= right)
    {
      mid = (right - left) / 2 + left;
      int out = guess(mid);
      if (out == 0)
        return mid;
      else if (out == -1)
        right = mid - 1;
      else if (out == 1)
        left = mid + 1;
    }
    return 0;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  pick = (atoi(argv[1]));
  int out = t.guessNumber(atoi(argv[2]));
  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
