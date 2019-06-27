#include "polygon_cls.h"
#include "Rec_cls.h"
#include "Tri_cls.h"

int main () {
  
  Polygon* ppoly1 = new Rectangle (3,2); // first order
  Polygon* ppoly2 = new Triangle (3,3); // second order

  ppoly1->GaussPoints();
  ppoly2->GaussPoints();

  ppoly1->shapefunction();
  ppoly2->shapefunction();
  ppoly1->print_shapefunction();
  ppoly2->print_shapefunction();



  delete ppoly1;
  delete ppoly2;
  return 0;
}
