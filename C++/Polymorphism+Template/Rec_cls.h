

#include <iostream>
using namespace std;

#include "polygon_cls.h"

#ifndef REC_CLS_H
#define REC_CLS_H

class Rectangle: public Polygon{
  public:
    Rectangle(int ,int );
    int area();
};

#endif
