

#include "polygon_cls.h"
#include "Rec_cls.h"
#include "Rec2_cls.h"
#include "Tri_cls.h"

int main () {
//  Polygon * ppoly1 = new Rectangle (4,5);
//  Polygon * ppoly2 = new Triangle (4,5);
  Polygon * ppoly3 = new Rectangle2 (4,5);

//  ppoly1->printarea();
//  ppoly2->printarea();
  ppoly3->FormMatrices<4, 6>();
  ppoly3->printMe();
  ppoly3->fill_shape_function();
  ppoly3->print_shape_function();
  ppoly3->printarea();

//  delete ppoly1;
//  delete ppoly2;
  delete ppoly3;
  return 0;
}
