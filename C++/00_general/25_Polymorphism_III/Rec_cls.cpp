

#include "Rec_cls.h"

Rectangle::Rectangle(int Int, int Node) : Polygon(Int, Node) {
  std::cout << " This is the Rectangle constructor\n";
}
Rectangle::~Rectangle() { std::cout << "  Rectangle destructor\n"; }

void Rectangle::shapefunction() {
  FN[0] = 1.1;
  FN[1] = 1.2;
}
