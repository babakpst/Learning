
/** @file polygon_cls.h
@author Poursartip:Babak:PhD:Algo

@version Revision 1.1

@brief header for Polygon class - abstract.

@details
Polygon constructor: the constructor of the class
~Polygon destructor: the destructor of the class

GaussPoints: calculates the Gauss points
print_shapefunction: Prints the shape functions
print_Gauss: prints the Gauss points

@date Monday, July 20, 2020

@class
polygon_cls
*/

#include <iostream>
using namespace std;

#ifndef POLYGON_CLS_H
#define POLYGON_CLS_H

class Polygon {
protected:
public:
  int NInt;      ///< number of integration points
  int NNode;     ///< number of nodes of the element
  double *FN;    ///< shape function array
  double *Gauss; ///< Gauss point array

  Polygon(int, int);
  /**<
  Polygon Constructor.

  @return void

  @param[in]
  NInt: number of integration points
  NNode: number of nodes of the element

  @param[in/out]
  nothing
  @param[out]
  shape

  @pre
  -# int var

  @post
  -# no output.
  */

  virtual ~Polygon();
  /**<
  Polygon destructor.

  @return void

  @param
  NInt: number of integration points
  NNode: number of nodes of the element

  @pre
  -# int var

  @post
  -# no output.
  */

  void GaussPoints();
  /**<
  Calcs the Gauss points-integration points.

  @return void

  @param
  NInt: number of integration points
  NNode: number of nodes of the element

  @pre
  -# int var

  @post
  -# no output.
  */

  void print_shapefunction();
  /**<
  prints the shapefunctions.

  @return void

  @param
  NInt: number of integration points
  NNode: number of nodes of the element

  @pre
  -# int var

  @post
  -# no output.
  */
  void print_Gauss();
  /**<
  prints the gauss points.

  @return void

  @param
  NInt: number of integration points
  NNode: number of nodes of the element

  @pre
  -# int var

  @post
  -# no output.
  */

  virtual void shapefunction(void) = 0;
  /**<
  abstract class for shape functions.

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
