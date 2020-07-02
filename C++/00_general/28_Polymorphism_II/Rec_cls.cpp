

#include "Rec_cls.h"

Rectangle::Rectangle(int Int, int Node) : Polygon(Int, Node) {}
Rectangle::~Rectangle() { std::cout << "rectangular destructor \n"; }
void Rectangle::shapefunction() {
  FN[0] = 1.1;
  FN[1] = 1.2;
}
