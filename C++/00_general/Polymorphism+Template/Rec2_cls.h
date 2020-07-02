

#include <iostream>
using namespace std;

#include "polygon_cls.h"

#ifndef REC2_CLS_H
#define REC2_CLS_H

class Rectangle2: public Polygon{
  public:
    Rectangle2(int ,int );
    virtual int area();
    virtual void fill_shape_function();
    virtual void print_shape_function ();
};

#endif

//#include "Rec2_cls.cpp"
