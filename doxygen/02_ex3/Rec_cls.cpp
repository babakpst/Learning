
/** @file Rec_cls.cpp
@author Poursartip:Babak:PhD:Algo

@version Revision 1.1

@brief This is the Rectangle class, child of Polygon_cls.

@details
Rectangle constructor: the constructor of the class
~Rectangle destructor: the destructor of the class

shapefunction: calcs shapefunctions of the class

@date Monday, July 20, 2020
*/

#include "Rec_cls.h"

Rectangle::Rectangle(int Int, int Node) : Polygon(Int, Node) {
  std::cout << " This is the Rectangle constructor\n";
}
Rectangle::~Rectangle() { std::cout << "  Rectangle destructor\n"; }

void Rectangle::shapefunction() {
  FN[0] = 1.1;
  FN[1] = 1.2;
}
