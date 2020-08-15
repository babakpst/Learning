#include <iostream>

class A1 {
  int b1;
  int b2;
  int b3;

  public:

  A1(int b1, int b2, int b3) : b1(b1) {
    b2 = b2;
    this->b3 = b3;
  }

  void print_stuff() {
    std::cout << b1 << " " << b2 << " " << b3 << std::endl;
  }
};

int main() {
  A1 a1(2, 3, 4);
  a1.print_stuff();
  return 0;
}
