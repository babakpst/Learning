/*

Babak Poursartip
05/04/2020
updated on 08/20/2020
updated on 01/23/2024
operator overloading

There are two ways to overload the operators:
1. define the operator as a member function. In this case, the left operand is the object that calls the function and
the right operand is the argument of the function. The operator function takes only one argument. The downside of this
method is that the left operand cannot be a built-in type.
2. define the operator as a non-member function. In this case, the left operand is the first argument and the right
operand is the second argument. The operator function takes two arguments.

To avoid the costly implicit type conversion we need to overload other types. For example, if we want to add a double to
a complex number, we need to overload the operator+ for this case. If we overload an operator, let's say +, we also need
to overload the operator+=.

Recommendation from Scott Meyer: define unary operators as a member functions. But define binary operators as non-member
functions to avoid implicit type conversion.

*/

#include <iostream>

// operator with member function ============================================================
namespace member_function
{
class complex
{
 private:
  int _real, _imag;

 public:
  complex();                                  // ctor
  complex(int, int);                          // ctor
  complex(const complex &);                   // copy ctor
  const complex &operator=(const complex &);  // copy assignment
  int getReal() const { return _real; }
  int getImag() const { return _imag; }

  complex &operator+=(const complex &);
  complex &operator+=(const int &);  // to avoid conversion from int to complex

  complex operator+(const complex &) const;
  complex operator+(const int &) const;  // to avoid conversion from int to complex
  complex operator-(
      const complex &) const;  // subtraction op; binary operator- (binary bcs it takes two arguments: c=a-b)
  complex operator-() const;   // negate op; unary operator- (unary bcs it takes one argument: c=-a)

  bool operator==(const complex &rhs) const { return (_real == rhs._real && _imag == rhs._imag); }

  bool operator!=(const complex &rhs) const { return !(*this == rhs); }

  void print() const;
};

complex::complex(int _real = 0, int _imag = 0) : _real(_real), _imag(_imag){};  // implementation of both ctor
complex::complex(const complex &rhs) : _real(rhs._real), _imag(rhs._imag){};    // copy ctor
const complex &complex::operator=(const complex &lhs)                           // copy assignment
{
  std::cout << " copy assignment \n";
  if (this != &lhs)
  {
    _real = lhs._real;
    _imag = lhs._imag;
  }
  return *this;
}

complex &complex::operator+=(const complex &rhs)
{
  std::cout << rhs._real << " +i" << rhs._imag << std::endl;
  std::cout << this->_real << " +i" << this->_imag << std::endl;
  this->_real += rhs._real;
  this->_imag += rhs._imag;
  return *this;
  // return complex(_real+=rhs._real, _imag+=rhs._imag);
}

complex &complex::operator+=(const int &rhs)
{
  std::cout << rhs << " +i0 - int" << std::endl;
  std::cout << this->_real << " +i" << this->_imag << std::endl;
  this->_real += rhs;
  return *this;
}

// option one: uses copy assignment
complex complex::operator+(const complex &rhs) const
{
  return complex(*this) += rhs;  // create a temporary var [complex(*this) or complex(_real, _imag)], add and return.
}
// option two: uses copy assignment
// complex complex::operator+(const complex &rhs) const { return complex(_real + rhs._real, _imag + rhs._imag); };

// option one: uses copy assignment
complex complex::operator+(const int &rhs) const
{
  return complex(*this) += rhs;  // create a temporary var [complex(*this) or complex(_real, _imag)], add and return.
}
// option two: uses copy assignment
// complex complex::operator+(const int &rhs) const { return complex(_real + rhs, _imag); };

complex complex::operator-() const  // negate op
{
  return complex(-this->_real, -this->_imag);
}

// sbutraction (two options)
// complex complex::operator-(complex const &rhs) const {return complex(_real-rhs._real, _imag-rhs._imag);};
complex complex::operator-(complex const &rhs) const { return complex(*this) += (-rhs); };

void complex::print() const { std::cout << _real << " + " << _imag << "i\n"; };
}  // namespace member_function
// operator with non-member function ============================================================
namespace nonmember_function
{
class complex
{
 private:
  int _real, _imag;

 public:
  complex();                                  // ctor
  complex(int, int);                          // ctor
  complex(const complex &);                   // copy ctor
  const complex &operator=(const complex &);  // copy assignment
  int getReal() const { return _real; }
  int getImag() const { return _imag; }

  bool operator==(const complex &rhs) const { return (_real == rhs._real && _imag == rhs._imag); }
  bool operator!=(const complex &rhs) const { return !(*this == rhs); }

  complex &operator+=(const complex &);
  complex &operator+=(const int &);  // to avoid conversion from int to complex

  complex operator-() const;  // negate op; unary operator- (unary bcs it takes one argument: c=-a)

  void print() const;
};

complex::complex(int _real = 0, int _imag = 0) : _real(_real), _imag(_imag){};  // implementation of both ctor
complex::complex(const complex &rhs) : _real(rhs._real), _imag(rhs._imag){};    // copy ctor
const complex &complex::operator=(const complex &lhs)                           // copy assignment
{
  std::cout << " copy assignment \n";
  if (this != &lhs)
  {
    _real = lhs._real;
    _imag = lhs._imag;
  }
  return *this;
}

complex &complex::operator+=(const complex &rhs)
{
  std::cout << rhs._real << " +i" << rhs._imag << std::endl;
  std::cout << this->_real << " +i" << this->_imag << std::endl;
  this->_real += rhs._real;
  this->_imag += rhs._imag;
  return *this;
  // return complex(_real+=rhs._real, _imag+=rhs._imag);
}

complex &complex::operator+=(const int &rhs)
{
  std::cout << rhs << " +i0 - int" << std::endl;
  std::cout << this->_real << " +i" << this->_imag << std::endl;
  this->_real += rhs;
  return *this;
}

complex complex::operator-() const  // negate op
{
  return complex(-this->_real, -this->_imag);
}

complex operator+(const complex &lhs, const complex &rhs)
{
  return complex(lhs) += rhs;  // create a temporary var [complex(*this) or complex(_real, _imag)], add and return.
};

complex operator+(const complex &lhs, const int &d)
{
  return complex(lhs) += d;  // create a temporary var [complex(*this) or complex(_real, _imag)], add and return.
};

complex operator+(const int &d, const complex &rhs)
{
  return complex(rhs) += d;  // create a temporary var [complex(*this) or complex(_real, _imag)], add and return.
}

void complex::print() const { std::cout << _real << " + " << _imag << "i\n"; };
}  // namespace nonmember_function

// ============================================================
std::ostream &operator<<(std::ostream &stream, const member_function::complex &other)
{
  stream << "(" << other.getReal() << "," << other.getImag() << ")";
  return stream;
}

std::ostream &operator<<(std::ostream &stream, const nonmember_function::complex &other)
{
  stream << "(" << other.getReal() << "," << other.getImag() << ")";
  return stream;
}

// ============================================================
int main()
{
  // ================================
  std::cout << " member functions ...\n";
  member_function::complex a(4, 5), b(2, 3), c(1, 1);
  a.print();
  b.print();
  c.print();

  std::cout << "here is c+=\n";
  c += a;
  c.print();

  std::cout << "here is c=a+b\n";
  c = a + b;
  c.print();
  a.print();
  b.print();

  std::cout << "equality: " << (a == b) << std::endl;
  std::cout << "inequality: " << (a != b) << std::endl;

  std::cout << "negate: " << (-b) << std::endl;

  std::cout << "here is c=a+2\n";
  c = a + 2;
  c.print();

  std::cout << "here is c+=2\n";
  c += 2;
  c.print();

  // ================================
  std::cout << "\n\n non member functions ...\n";
  nonmember_function::complex na(4, 5), nb(2, 3), nc(1, 1);
  na.print();
  nb.print();
  nc.print();

  std::cout << "here is c+=\n";
  nc += na;
  nc.print();

  std::cout << "here is c=a+b\n";
  nc = na + nb;
  nc.print();
  na.print();
  nb.print();

  std::cout << "equality: " << (na == nb) << std::endl;
  std::cout << "inequality: " << (na != nb) << std::endl;

  std::cout << "negate: " << (-nb) << std::endl;

  std::cout << "here is c=a+2\n";
  nc = na + 2;
  nc.print();

  std::cout << "here is c+=2\n";
  nc += 2;
  nc.print();

  return 0;
}
