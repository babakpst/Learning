#include <cstdio>

#include "Rec2_cls.h"
#include "Tri2_cls.h"
#include "polygon_cls.h"

int main() {

  std::puts(" === rectangle === ");
  Polygon *ppoly1 = new Rectangle2(4, 5);
  ppoly1->FormMatrices<4, 6>();
  ppoly1->printMe();
  ppoly1->fill_shape_function();
  ppoly1->print_shape_function();
  ppoly1->printarea();
  delete ppoly1;

  std::puts(" === triangle === ");
  Polygon *ppoly2 = new Triangle2(6, 7);
  ppoly1->FormMatrices<4, 6>();
  ppoly1->printMe();
  ppoly1->fill_shape_function();
  ppoly1->print_shape_function();
  ppoly1->printarea();
  delete ppoly2;

  return 0;
}
