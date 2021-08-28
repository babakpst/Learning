
#include "polygon_cls.h"

Polygon::Polygon(int a, int b) : width(a), height(b) {
  std::cout << "constructor for Polygon\n";
}

Polygon::~Polygon() { std::cout << "destructor for Polygon\n"; }

void Polygon::printMe() {
  for (int i = 0; i < RNInt; i++) {
    std::cout << " Gauss= " << Gauss[i] << std::endl;
  }
}

void Polygon::printarea() { cout << this->area() << '\n'; }
