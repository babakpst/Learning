
#include "Tri_cls.h"
#include "polygon_cls.h"

    Triangle::Triangle(int a,int b) : Polygon(a,b) {}

    int Triangle::area()
      { return width*height/2; }
