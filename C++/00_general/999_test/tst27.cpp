#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T, var;
  cin >> T;

  for (int i = 0; i < T; ++i) {
    cin >> var;

    if (var == 2) {
      cout << "Prime" << endl;
    } else if (var == 1 || (var > 2 && (var % 2) == 0)) {
      cout << "Not prime" << endl;
    } else {
      int temp = 0;
      for (int j = 3; j <= (var / 2); j += 2) {
        if ((var % j) == 0) {
          cout << "Not prime" << endl;
          temp = 1;
          break;
        }
      }
      if (temp == 0)
        cout << "Prime" << endl;
    }
  }
  return 0;
}
