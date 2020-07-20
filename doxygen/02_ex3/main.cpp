
/** @file main.cpp
@author Poursartip:Babak:PhD:Algo
@version Revision 1.1
@brief compute the area of various objects
@details Rectangle, Triangle
@date Monday, July 20, 2020
*/

/**
@mainpage
Area
- Area of Triangle
- Area of Rectangle

Some comments:
<em>To emphasize a word use this command</em> \n
<b>To bold a word</b> \n
<br>This is it \n
*/

#include "Rec_cls.h"
#include "Tri_cls.h"
#include "polygon_cls.h"

/**<
Compute and return the area.

@return the area of the object.
@param
  Width width of an object.
  Length length of an object.
@pre
  Width and Length contains a positive integer.
@post
  The area of the object is calculated.
\n This \n is \n good.
*/
int main() {
  Polygon *ppoly1 = new Rectangle(3, 2); // first order
  Polygon *ppoly2 = new Triangle(3, 3);  // second order

  ppoly1->GaussPoints();
  ppoly2->GaussPoints();

  ppoly1->shapefunction();
  ppoly2->shapefunction();
  ppoly1->print_shapefunction();
  ppoly2->print_shapefunction();

  delete ppoly1;
  delete ppoly2;
  return 0;
}
