

// Babak Poursartip
// date 09112020
// description:
/* find a target value in the sorted arrary
    return the index if found
    otherwise return -1;
*/

#include <iostream>
#include <vector>
using namespace std;

int findValue(const vector<int> &arr, int target) {
  int bb = 0, ee = arr.size() - 1;
  while (bb <= ee) {
    int mid = bb + (ee - bb) / 2;

    // Check if x is present at mid
    if (target == arr[mid])
      return mid;               // found the target
    else if (arr[mid] < target) // search in the upper half
      bb = mid + 1;
    else // search in the lower half
      ee = mid - 1;
  }

  return -1; // if target is not in the array
}

int main() {
  cout << " Finding a target value in a vector ...\n"
       << "\n    <<Assumptions:>>\n"
       << " -The array is already sorted.\n"
       << " -Elements are unique.\n"
       << " -Array is non-empty.\n\n";

  // input section =========================
  int target = 8;
  vector<int> arr = {1, 3, 6, 8, 12};
  // vector<int> arr = {1, 3, 6, 9, 12};

  // edge cases:
  // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 10, 12, 19, 25, 28, 28};
  // vector<int> arr{};

  // calc section =========================
  if (arr.size() == 0) {
    cout << "  Array is empty! \n"
         << "  Pleas enter a valid array.\n";
    return 0;
  }
  int index = findValue(arr, target);
  if (index == -1)
    cout << " Target is not in the array!\n";
  else
    cout << " The target is located at index (first index is 0): " << index
         << endl;

  cout << "\n Ends successfully! \n";
  return 0;
}
