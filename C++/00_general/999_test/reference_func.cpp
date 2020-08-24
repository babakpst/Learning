
// reference function

// A function can return reference, hence it can appear on the left hand side of
// the assignment operator.

#include <iostream>

using namespace std;
int x = 5;

int &f() { return x; }

int main() {
  f() = 10;
  cout << x << "\n";
}