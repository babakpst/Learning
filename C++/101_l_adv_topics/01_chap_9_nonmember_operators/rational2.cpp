// rational2.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-03 for CppAdv
#include <cstdio>
#include <iostream>
using namespace std;

class Rational
{
  int _n = 0;
  int _d = 1;

 public:
  Rational(int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator)
  {
    cout << "ctor\n";
  }                                                                                  // default constructor
  Rational(const Rational& rhs) : _n(rhs._n), _d(rhs._d) { cout << "copy ctor\n"; }  // copy constructor
  ~Rational()
  {
    cout << "dtor\n";
    _n = 0;
    _d = 1;
  }

  int numerator() const { return _n; }  // w/o const there would be a compile error. Bcs the obj is const.
  int denominator() const { return _d; }
  Rational& operator=(const Rational& rhs)
  {
    if (this != &rhs)
    {
      _n = rhs.numerator();
      _d = rhs.denominator();
    }
    return *this;
  }  // assignment operator
};

Rational operator+(const Rational& lhs, const Rational& rhs)
{
  return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()),
                  lhs.denominator() * rhs.denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
  return Rational((lhs.numerator() * rhs.denominator()) - (lhs.denominator() * rhs.numerator()),
                  lhs.denominator() * rhs.denominator());
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
  return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
  return Rational(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
}

// for std::cout
std::ostream& operator<<(std::ostream& o, const Rational& r)
{
  if (r.denominator() == 1)
    return o << r.numerator();
  else
    return o << r.numerator() << '/' << r.denominator();
}

int main()
{
  Rational a = 7;  // 7/1
  cout << "a is: " << a << endl;
  Rational b(5, 3);  // 5/3
  cout << "b is: " << b << endl;
  Rational c = b;  // copy constructor
  cout << "c is: " << c << endl;
  Rational d;  // default constructor
  cout << "d is: " << d << endl;
  d = c;  // assignment operator
  cout << "d is: " << d << endl;
  Rational& e = d;  // reference
  d = e;            // assignment to self!
  cout << "e is: " << e << endl;

  cout << endl;
  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  cout << a << " / " << b << " = " << a / b << endl;
  cout << endl;
  cout << a << " + " << 2 << " = " << a + 2 << endl;
  cout << 2 << " + " << b << " = " << 2 + b << endl;
  return 0;
}
