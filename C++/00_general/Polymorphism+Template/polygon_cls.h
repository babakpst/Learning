
#include <iostream>
using namespace std;

#ifndef POLYGON_CLS_H
#define POLYGON_CLS_H


class Polygon {
  protected:
    int width, height;
  public:
    int RNNode;
    int RNInt;
    int* Gauss;
    double* FN;    
    Polygon (int , int);
    virtual int area (void) =0;

    template<int NNode, int NInt>
    void FormMatrices(){
      Gauss = new int [NInt];
      FN    = new double [NNode];
      RNNode = NNode;
      RNInt  = NInt;

      for(int i=0; i<NInt;i++){
        Gauss[i] = i;
      }
    }

    virtual void fill_shape_function (void) =0;
    virtual void print_shape_function (void) =0;

    void printMe();
    void printarea();
};

//#include "polygon_cls.cpp"
#endif


