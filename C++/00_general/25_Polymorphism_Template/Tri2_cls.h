
#include <iostream>
using namespace std;

#include "polygon_cls.h"

#ifndef TRI2_CLS_H
#define TRI2_CLS_H

class Triangle2 : public Polygon {
public:
  Triangle2(int, int);
  virtual ~Triangle2();
  int area();

  virtual void fill_shape_function();
  virtual void print_shape_function();
};

#endif
