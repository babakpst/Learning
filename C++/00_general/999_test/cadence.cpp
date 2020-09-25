/*
Please implement the function:

unsigned findLeftElement(  float *x, unsigned n, float a );

which computes k from [0,..,n-1] such that  x[k] < a < x[k+1].
You can assume that x is sorted in ascending order, and x[0] <= a < x[n-1].
The goal is to get optimal code from runtime point of view.

from Igor Keller (privately):    3:35 PM
ikeller@cadence.com
*/

/*
Assumptions:
- x is not null.
- x[0] <= a < x[n-1] => size of array is at least 2.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned findLeftElement(float *x, unsigned n, float a) {
  unsigned low = 0, high = n - 1;
  while (low < high) {
    unsigned mid = (low + high) / 2;
    if (x[mid] <= a && a < x[mid + 1])
      return mid;
    else if (x[mid] < a)
      low = mid + 1;
    else
      high = mid;
  }
}

int main() {

  float a = 1.15;
  // float a;
  // cout << " type the target: \n";
  // cin >> a;
  // cin.ignore();

  // create the matrix ======
  unsigned n = 7;
  float x[n] = {1.1, 1.2, 2.3, 3.0, 4.2, 6.7, 8.6};

  // unsigned n = 2;
  // float x[n] = {1.1,2.3};

  // unsigned n = 8;
  // float x[n] = {1.1,1.2,2.3,3.0,4.2,6.7,8.6,9.1};

  cout << " index is: " << findLeftElement(x, n, a) << endl;

  return 0;
}
