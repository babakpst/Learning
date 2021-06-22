#include <iostream>

class A1 {
  int b1;
  int b2;
  int b3;
  int var;

  public:

  A1(int b1, int b2, int b3, int b4) : b1(b1) {
    b2 = b2; // not working
    this->b3 = b3; // proper way
    var = b4; // this is fine.
  }

  void print_stuff() {
    std::cout << b1 << " " << b2 << " " << b3<< " " << var << std::endl;
  }
};

int main() {
  A1 a1(2, 3, 4, 6); // displays 2 (some random number) 4 6
  a1.print_stuff();
  return 0;
}
