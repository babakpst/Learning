
#include "Tri_cls.h"
#include "polygon_cls.h"

Triangle::Triangle(int a, int b) : Polygon(a, b) {}
Triangle::~Triangle() { std::cout << " destructor of Tri_cls \n"; }

int Triangle::area() { return width * height / 2; }
