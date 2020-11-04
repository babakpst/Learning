
#include <iostream>

using namespace std;
main() {

  int i = 1, j = 2, k = 3, r;

  r = (i, j, k);
  cout << r << endl;

  r = (10, i, j, k);
  cout << r << endl;

  r = (10, i, j, k, j);
  cout << r << endl;
}