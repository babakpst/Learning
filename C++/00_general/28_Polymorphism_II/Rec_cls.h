

#include <iostream>

#include "polygon_cls.h"

#ifndef REC_CLS_H
#define REC_CLS_H

class Rectangle : public Polygon {
public:
  Rectangle(int, int);
  virtual ~Rectangle();

  virtual void shapefunction();
};

#endif
