/*
Babak Poursartip
5/5/2020

Linkedin: advanced topics in cpp

chapter 1: conversion operator
important notes:
overloading a cast operator.

*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Rational {

  int _n = 0;
  int _d = 1;

public:
  Rational(int numerator = 0, int denominator = 1)
      : _n(numerator), _d(denominator){};
  Rational(const Rational &rhs) : _n(rhs._n), _d(rhs._d){}; // copy constructor
  ~Rational();

  int numerator() const { return _n; };
  int denominator() const { return _d; };
  Rational &operator=(const Rational &);
  operator string() const;
};
Rational::operator string() const {
  if (_d == 1)
    return to_string(_n);
  else
    return to_string(_n) + "/" + to_string(_d);
};

Rational &Rational::operator=(const Rational &rhs) {
  if (&rhs != this) {
    _n = rhs.numerator();
    _d = rhs.denominator();
  }
  return *this;
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
  return Rational((lhs.numerator() * rhs.denominator()) -
                      (lhs.denominator() * rhs.numerator()),
                  lhs.denominator() * rhs.denominator());
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
  return Rational((lhs.numerator() * rhs.denominator()) +
                      (lhs.denominator() * rhs.numerator()),
                  lhs.denominator() * rhs.denominator());
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
  return Rational(lhs.numerator() * rhs.numerator(),
                  lhs.denominator() * rhs.denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
  return Rational(lhs.numerator() * rhs.denominator(),
                  lhs.denominator() * rhs.numerator());
}

Rational::~Rational() {
  _n = 0;
  _d = 1;
}

// for std::cout
std::ostream &operator<<(std::ostream &o, const Rational &r) {
  // if (r.denominator() == 1)
  //  return o << r.numerator();
  // else
  //  return o << r.numerator() << '/' << r.denominator();
  return o << string(r);
}

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

  string s = " Rational value is : ";
  s += b;
  cout << s << endl;

  return 0;
}