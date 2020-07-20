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

#include "../../include/module_1/mult_cls.h"

// constructor
mult_cls::mult_cls() { m.pt(" mult_cls."); }
mult_cls::mult_cls(const int input) : input{input} {

  m.pti(" input received.", input);
}

// =============================================================================
// calculates integer by integer
int mult_cls::doit(const int ivar1, const int ivar2) {
  m.pt("multipliying int by int");
  this->ivar1 = ivar1;

  return ivar1 * ivar2;
}

// =============================================================================
// calculates float by float
float mult_cls::doit(const float fvar1, const float fvar2) {
  m.pt("multipliying float by float");
  return fvar1 * fvar2;
}

// =============================================================================
// calculates vec by vector
int mult_cls::vecXvec(std::vector<int> vec1, std::vector<int> vec2) {
  m.pt("multipliying vector by vector");

  if (vec1.size() != vec2.size()) {
    m.pt(" vector sizes are different");
    return 99.99;
  }

  int results = 0;

  std::vector<int>::iterator it2 = vec2.begin();
  for (std::vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end();
       ++it1) {
    results += (*it1) * (*it2);
    ++it2;
  }

  return results;
}
