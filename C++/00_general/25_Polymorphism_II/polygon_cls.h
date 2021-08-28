
#include <iostream>
using namespace std;

#ifndef POLYGON_CLS_H
#define POLYGON_CLS_H

class Polygon {
protected:
  int width, height;

public:
  Polygon(int, int);
  virtual int area(void) = 0;
  void printarea();
  virtual ~Polygon();
};

#endif
