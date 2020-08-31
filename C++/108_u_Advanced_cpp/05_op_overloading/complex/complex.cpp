

#include "complex.h"
namespace myComplex {

complex complex::operator*() const { return complex(_real, -_img); }

bool complex::operator==(const complex &rhs) const {
  return (_real == rhs._real && _img == rhs._img);
}

bool complex::operator!=(const complex &rhs) const { return !(*this == rhs); }

complex operator+(const double &d, const complex &lhs) {
  return complex(lhs.getReal() + d, lhs.getIm());
} // namespace myComplex

complex operator+(const complex &lhs, const double &d) {
  return complex(lhs.getReal() + d, lhs.getIm());
} // namespace myComplex

complex operator+(const complex &lhs, const complex &rhs) {
  return complex(lhs.getReal() + rhs.getReal(), lhs.getIm() + rhs.getIm());
}

ostream &operator<<(ostream &o, const complex &rhs) {
  return o << "(" << rhs.getReal() << ", " << rhs.getIm() << ")";
}

// constructor
complex::complex() : _real{0.0}, _img{0.0} { cout << " default ctor\n"; }
complex::complex(double _real, double _img) : _real{_real}, _img{_img} {
  cout << " ctor\n";
}

// copy constructor
complex::complex(const complex &rhs) {
  _real = rhs._real;
  _img = rhs._img;
  cout << " copy ctor\n";
}

// assignment operator
const complex &complex::operator=(const complex &rhs) {
  this->_real = rhs._real;
  this->_img = rhs._img;
  cout << " assignment operator\n";
  return *this;
}

} // namespace myComplex