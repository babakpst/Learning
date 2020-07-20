

/** @file Tri_cls.cpp
@author Poursartip:Babak:PhD:Algo

@version Revision 1.1

@brief This is the Triangle class, child of Polygon_cls.

@details
Triangle constructor: the constructor of the class
~Triangle destructor: the destructor of the class

shapefunction: calcs shapefunctions of the class

@date Monday, July 20, 2020
*/

#include "Tri_cls.h"
#include "polygon_cls.h"

Triangle::Triangle(int Int, int Node) : Polygon(Int, Node) {
  std::cout << " This is the Triangle constructor\n";
}
Triangle::~Triangle() { std::cout << "  Triangle destructor\n"; }

void Triangle::shapefunction() {
  FN[0] = 2.1;
  FN[1] = 2.2;
  FN[2] = 2.2;
}
