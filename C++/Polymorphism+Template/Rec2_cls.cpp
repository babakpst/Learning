

#include "Rec2_cls.h"


Rectangle2::Rectangle2(int a,int b) : Polygon(a,b) {}


int Rectangle2::area()
      { return width*height; }

void Rectangle2::fill_shape_function(){
  for(int ii =0; ii<RNNode; ii++){
    FN[ii] = 0.1*ii;
  }
}

void Rectangle2::print_shape_function (){
  for(int ii =0; ii<RNNode; ii++){
    std::cout << " shape function is: " << FN[ii] << std::endl;
  }
}


