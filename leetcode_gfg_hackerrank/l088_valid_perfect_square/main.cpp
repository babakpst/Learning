
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  bool isPerfectSquare(int num)
  {
    int left = 1, right = max(num / 2, 1);
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      long long int nn = static_cast<long long int>(mid) * static_cast<long long int>(mid);
      cout << mid << " " << nn << endl;
      if (nn == num)
        return true;
      else if (nn > num)
        right = mid - 1;
      else
        left = mid + 1;
    }
    return false;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Solution t;

  bool out = t.isPerfectSquare(atoi(argv[1]));

  cout << " answer: " << boolalpha << out << endl;

  std::cout << " done \n";
  return 0;
}
