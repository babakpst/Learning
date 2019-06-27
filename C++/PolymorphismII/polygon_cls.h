
#include <iostream>


#ifndef POLYGON_CLS_H
#define POLYGON_CLS_H


class Polygon {
  public:
    int NInt;
    int NNode;
    double* Gauss;
    double* FN;

    Polygon (int , int);

    void GaussPoints();

    virtual void shapefunction (void) =0;    

    void print_shapefunction ();
    void print_Gauss ();

};

#endif
