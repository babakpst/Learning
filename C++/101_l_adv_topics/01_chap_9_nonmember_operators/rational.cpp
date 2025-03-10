/*
Babak Poursartip
5/4/2020

Linkedin: advanced topics in cpp

chapter 1: operator overload
important notes:
There are two distinct operator overload in cpp:
 - with member function,
 - with separate non-member function.

See the syntax for operator overload for member functions.

*/

#include <cstdio>
#include <iostream>
using namespace std;

// a class for doing four function arithmetic on rational numbers.
class Rational {
  int _n = 0; // numerator
  int _d = 1; // denominator.

public:
  Rational(int numerator = 0, int denominator = 1)
      : _n(numerator), _d(denominator){};
  Rational(const Rational &rhs) : _n(rhs._n), _d(rhs._d){}; // copy constructor
  ~Rational();

  int numerator() const { return _n; };
  int denominator() const { return _d; };

  // syntax for operator overload
  // name of the class (Rational) - keyword for operator overload(operator) -
  // the operator itself (+) - the arguments
  Rational &operator=(const Rational &); // this should be copy assignment
  // Rational operator+(const Rational &) const;
  Rational operator-(const Rational &) const;
  Rational operator*(const Rational &)const;
  Rational operator/(const Rational &) const;
};

Rational &Rational::operator=(const Rational &rhs) {
  if (this != &rhs) {
    _n = rhs.numerator();
    _d = rhs.denominator();
  }
  return *this;
}

// These operator overloads only work if the rational number is on the rhs. See below.
// Rational Rational::operator+(const Rational &rhs) const {
//  return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
//}

Rational Rational::operator-(const Rational &rhs) const {
  return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator*(const Rational &rhs) const {
  return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator/(const Rational &rhs) const {
  return Rational(_n * rhs._d, _d * rhs._n);
}

Rational::~Rational() {
  _n = 0;
  _d = 1;
}

// for std::cout
std::ostream &operator<<(std::ostream &o, const Rational &r) {
  if (r.denominator() == 1)
    return o << r.numerator();
  else
    return o << r.numerator() << '/' << r.denominator();
}

// This is a non-member overload operator. It is possible to use this because we
// have an implicit conversion.
Rational operator+(const Rational &lhs, const Rational &rhs) {
  return Rational((lhs.numerator() * rhs.denominator()) +
                      (lhs.denominator() * rhs.numerator()),
                  lhs.denominator() * rhs.denominator());
}


// ===============================================
int main() {

  Rational a = 7; // 7/1
  cout << "a is: " << a << endl;
  Rational b(5, 3); // 5/3
  cout << "b is: " << b << endl;
  Rational c = b; // copy constructor
  cout << "c is: " << c << endl;
  Rational d; // default constructor
  cout << "d is: " << d << endl;
  d = c; // assignment operator
  cout << "d is: " << d << endl;
  Rational &e = d; // reference
  d = e;           // assignment to self!
  cout << "e is: " << e << endl;

  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  cout << a << " / " << b << " = " << a / b << endl;

  // not working because the operator overload is defined for Raional not for an
  // integer number.

  cout << 14 << " + " << b << " = " << 14 + b << endl;

  return 0;
}
