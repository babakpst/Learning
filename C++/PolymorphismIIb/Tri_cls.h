
#include <iostream>

#include "polygon_cls.h"

#ifndef TRI_CLS_H
#define TRI_CLS_H

class Triangle: public Polygon {
  public:
    Triangle(int ,int );
    
    virtual void shapefunction();
};

#endif