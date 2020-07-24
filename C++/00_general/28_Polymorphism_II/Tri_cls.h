
#include <iostream>
using namespace std;

#include "polygon_cls.h"

#ifndef TRI_CLS_H
#define TRI_CLS_H

class Triangle : public Polygon {
public:
  Triangle(int, int);
  ~Triangle();
  int area();
};

#endif
