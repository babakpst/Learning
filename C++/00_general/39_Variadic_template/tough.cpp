
#include <iostream>
using namespace std;
// not got it quite well

//===========================================
template <bool a> int reversed_binary_value() {
  // cout << "inside final: " << a << endl;
  return a;
}

template <bool a, bool b, bool... d> int reversed_binary_value() {
  // cout << "inside: " << a << " " << b << endl;
  return (reversed_binary_value<b, d...>() << 1) + a;
}
//===========================================
template <int n, bool... digits> struct CheckValues {
  static void check(int x, int y) {
    cout << " first: " << n << " " << x << " " << y << "\n";

    CheckValues<n - 1, 0, digits...>::check(x, y);
    CheckValues<n - 1, 1, digits...>::check(x, y);
  }
};

template <bool... digits> struct CheckValues<0, digits...> {
  static void check(int x, int y) {
    cout << " second\n";
    int z = reversed_binary_value<digits...>();
    cout << " z=" << z << endl;
    // int z = 1;
    std::cout << "output ";
    cout << (z + 64 * y == x);
    cout << endl;
  }
};

//===========================================
int main() {
  int t;
  std::cin >> t;

  for (int i = 0; i != t; ++i) {
    int x, y;
    cin >> x >> y;

    // This 6 allows to generat 0~63. 63 is 11111.
    CheckValues<6>::check(x, y); // check generates 0~63
    cout << "\n";
    cout << "==================\n";
  }
}
