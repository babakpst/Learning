
#include "Tri_cls.h"
#include "polygon_cls.h"

Triangle::Triangle(int Int, int Node) : Polygon(Int, Node) {
  std::cout << " This is the Triangle constructor\n";
}
Triangle::~Triangle() { std::cout << "  Triangle destructor\n"; }

void Triangle::shapefunction() {
  FN[0] = 2.1;
  FN[1] = 2.2;
  FN[2] = 2.2;
}
