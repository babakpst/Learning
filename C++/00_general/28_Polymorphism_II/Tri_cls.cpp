

#include "Tri_cls.h"

Triangle::Triangle(int Int, int Node) : Polygon(Int, Node) {}
Triangle::~Triangle() { std::cout << "triangle destructor \n"; }
void Triangle::shapefunction() {
  FN[0] = 2.1;
  FN[1] = 2.2;
  FN[2] = 2.2;
}
