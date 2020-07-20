
/** @file Tri_cls.h
@author Poursartip:Babak:PhD:Algo

@version Revision 1.1

@brief header for Trinagnle class

@details
Triangle constructor: the constructor of the class
~Triangle destructor: the destructor of the class

shapefunction: calcs shapefunctions of the class

@date Monday, July 20, 2020
*/

#include <iostream>

#include "polygon_cls.h"

#ifndef TRI_CLS_H
#define TRI_CLS_H

class Triangle : public Polygon {
public:
  Triangle(int, int);
  /**<
  Triangle Constructor.

  @return void

  @param
  NInt: number of integration points
  NNode: number of nodes of the element

  @pre
  -# int var

  @post
  -# no output.
  */

  virtual ~Triangle();
  /**<
  Triangle destructor.

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
  virtual Shape function for triangle.

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
