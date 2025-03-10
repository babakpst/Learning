
#include "polygon_cls.h"

Polygon::Polygon(int Int, int Node)
    : NInt(Int), NNode(Node), FN(new double[NNode]), Gauss(new double[NInt]) {
  std::cout << " This is the polygon constructor\n";
}

Polygon::~Polygon() { std::cout << "  Polygon destructor\n"; }

void Polygon::GaussPoints() {
  for (int i = 0; i < NInt; i++) {
    Gauss[i] = i;
  }
}

void Polygon::print_shapefunction() {
  for (int i = 0; i < NNode; i++) {
    std::cout << " shape functions: " << FN[i] << std::endl;
  }
}

void Polygon::print_Gauss() {
  for (int i = 0; i < NNode; i++) {
    std::cout << " Gauss: " << Gauss[i] << std::endl;
  }
}
