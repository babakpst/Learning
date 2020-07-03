
#include "Tri2_cls.h"

Triangle2::Triangle2(int a, int b) : Polygon(a, b) {
  std::cout << "destructor for Triangle2\n";
}
Triangle2::~Triangle2() { std::cout << "destructor for Triangle2\n"; }

int Triangle2::area() { return width * height / 2; }

void Triangle2::fill_shape_function() {
  for (int ii = 0; ii < RNNode; ii++) {
    FN[ii] = 0.1 * ii;
  }
}

void Triangle2::print_shape_function() {
  for (int ii = 0; ii < RNNode; ii++) {
    std::cout << " shape function is: " << FN[ii] << std::endl;
  }
}
