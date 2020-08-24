
#include <iostream>

// void printEntity(entity *e);

class entity {
  int x, y;

public:
  entity(int x, int y) {
    this->x = x;
    this->y = y;
    // printEntity(this);
  };

  int getter() { return x; }
  void print() { std::cout << x << " " << y << "\n"; }
};

// void printEntity(entity *e) {
//  std::cout << "this is the external funciton: " << e->getter() << "\n";
//}

int main() {
  puts(" start ...");

  entity e(1, 2);
  e.print();

  puts(" end");
  return 0;
}
