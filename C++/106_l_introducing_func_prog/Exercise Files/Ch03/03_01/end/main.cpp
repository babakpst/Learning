#include <iostream>
#include <vector>
using namespace std;

template<typename T>
T cube(const T& value){
  return value * value * value;
}

template<int toCube>
struct Cube {
  enum {
    value = toCube * toCube * toCube
  };
};

int main() {
  cout << "8 cubed = " << cube(8) << endl;
  cout << "5 cubed = " << Cube<5>::value << endl;
  return 0;
}
