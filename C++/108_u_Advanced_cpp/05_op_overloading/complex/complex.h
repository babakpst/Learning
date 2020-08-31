
// Babak Poursartip
// 08/30/2020

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using std::cout;
using std::ostream;

namespace myComplex {
class complex {
private:
  double _real, _img;

public:
  complex();
  complex(double _real, double _img);
  complex(const complex &rhs);                  // copy constructor
  const complex &operator=(const complex &rhs); // assignment operator

  // getter
  double getReal() const { return _real; }
  double getIm() const { return _img; }
  bool operator==(const complex &rhs) const;
  bool operator!=(const complex &rhs) const;
  complex operator*() const;
};

ostream &operator<<(ostream &o, const complex &rhs);
complex operator+(const complex &lhs, const complex &rhs);
complex operator+(const complex &lhs, const double &d);
complex operator+(const double &d, const complex &lhs);

} // namespace myComplex
#endif // !COMPLEX_H