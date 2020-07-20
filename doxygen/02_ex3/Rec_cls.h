
/** @file Rec_cls.h
@author Poursartip:Babak:PhD:Algo

@version Revision 1.1

@brief header for Rectangle class

@details
Rectangle constructor: the constructor of the class
~Rectangle destructor: the destructor of the class

shapefunction: calcs shapefunctions of the class

@date Monday, July 20, 2020
*/

#include <iostream>

#include "polygon_cls.h"

#ifndef REC_CLS_H
#define REC_CLS_H

class Rectangle : public Polygon {
public:
  Rectangle(int, int);
  /**<
  Rectangle Constructor.

  @return void

  @param
  NInt: number of integration points
  NNode: number of nodes of the element

  @pre
  -# int var

  @post
  -# no output.
  */
  virtual ~Rectangle();
  /**<
  Rectangle destructor.

  @return void

  @param
  NInt: number of integration points
  NNode: number of nodes of the element

  @pre
  -# int var

  @post
  -# no output.
  */

  virtual void shapefunction();
  /**<
  virtual Shape function for rec.

  @return void

  @param
  NInt: number of integration points
  NNode: number of nodes of the element

  @pre
  -# int var

  @post
  -# no output.
  */
};

#endif
