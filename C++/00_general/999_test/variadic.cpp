#include <iostream>
using namespace std;

//===========================================

// Enter your code for reversed_binary_value<bool...>()
template <bool Tfirst, bool... Trest> int reversed_binary_value() {
  static int cnt = -1;
  cnt++;
  int p = 1;
  // int p = pow(2, cnt);
  return Tfirst * p + reversed_binary_value<Trest...>();
}

//===========================================
template <int n, bool... digits> struct CheckValues {
  static void check(int x, int y) {
    cout << " first\n";
    CheckValues<n - 1, 0, digits...>::check(x, y);
    CheckValues<n - 1, 1, digits...>::check(x, y);
  }
};

template <bool... digits> struct CheckValues<0, digits...> {
  static void check(int x, int y) {
    cout << " second\n";
    int z = reversed_binary_value<digits...>();
    std::cout << (z + 64 * y == x);
  }
};

//===========================================
int main() {
  int t;
  std::cin >> t;

  for (int i = 0; i != t; ++i) {
    int x, y;
    cin >> x >> y;
    CheckValues<6>::check(x, y);
    cout << "\n";
  }
}
