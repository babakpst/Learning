
#include <iostream>
using namespace std;

#ifndef POLYGON_CLS_H
#define POLYGON_CLS_H


class Polygon {
  protected:

  public:
    int NInt;
    int NNode;
    Polygon (int , int);

    double* Gauss;
    double* FN;

    void GaussPoints();
    
    void print_shapefunction ();
    void print_Gauss ();
    virtual void shapefunciton (void) =0;
};

#endif
