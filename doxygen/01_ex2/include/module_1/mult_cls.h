/** @file mult_cls.h
@author Poursartip:Babak:PhD:mult
@version Revision 1.20
@brief it does number multiplication
@details
mult_int_int: multiplies int by int
mult_float_float: multiplies float by float
mult_vector_vector: multiplies float by float
@date Monday, July 20, 2020
*/

// libraries
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// classes
#include "../include/module_1/message_cls.h"

// GUARD
#ifndef MULT_CLS_H
#define MULT_CLS_H

class mult_cls {

  // members
private:
  message_cls m;
  int input;
  int ivar1, ivar2, ires = 0;
  float fvar1, fvar2, fres = 0;
  std::vector<int> vec1, vec2;

public:
  // methods
  int irestults;
  float frestults;

private:
  mult_cls();

public:
  mult_cls(const int);

  // pushes a vertix and its corresponding weighted edge
  int doit(const int, const int);
  float doit(const float, const float);
  int vecXvec(std::vector<int>, std::vector<int>);
};

#endif // ! MULT_CLS_H
