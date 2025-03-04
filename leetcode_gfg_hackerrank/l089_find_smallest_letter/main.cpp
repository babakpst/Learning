
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  char nextGreatestLetter(vector<char>& letters, char target)
  {
    int size = letters.size();

    if (letters[size - 1] - 'a' <= target - 'a') return letters[0];

    int left = 0, right = size - 1;
    while (left < right)
    {
      int mid = left + (right - left) / 2;

      cout << left << " " << mid << " " << right << endl;

      if (letters[mid] - 'a' <= target - 'a' && letters[mid + 1] - 'a' > target - 'a')
        return letters[mid + 1];
      else if (letters[mid] - 'a' <= target - 'a')
        left = mid;
      else if (letters[mid] - 'a' >= target - 'a')
        right = mid;
    }
    return letters[0];
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<char> letters={'c','f','j'};
  // int target = 'f';

  vector<char> letters = {'e', 'e', 'e', 'e', 'e', 'e', 'n', 'n', 'n', 'n'};
  int target = 'e';

  Solution t;

  char out = t.nextGreatestLetter(letters, target);

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}
