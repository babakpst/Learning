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

*/

#include <iostream>

// operator with member function ============================================================
namespace member_function
{
class complex
{
 private:
  int real, imag;

 public:
  complex();                                  // ctor
  complex(int, int);                          // ctor
  complex(const complex &);                   // copy ctor
  const complex &operator=(const complex &);  // copy assignment

  complex &operator+=(const complex &);

  complex operator+(const complex &) const;  // option one
  // complex  operator+(const complex &); // option two

  void print() const;
};

complex::complex(int real = 0, int imag = 0) : real(real), imag(imag){};  // implementation of both ctor
complex::complex(const complex &rhs) : real(rhs.real), imag(rhs.imag){};  // copy ctor
const complex &complex::operator=(const complex &lhs)                     // copy assignment
{
  std::cout << " copy assignment \n";
  if (this != &lhs)
  {
    real = lhs.real;
    imag = lhs.imag;
  }
  return *this;
}

complex &complex::operator+=(const complex &rhs)
{
  std::cout << rhs.real << " +i" << rhs.imag << std::endl;
  std::cout << this->real << " +i" << this->imag << std::endl;
  this->real += rhs.real;
  this->imag += rhs.imag;
  return *this;
  // return complex(real+=rhs.real, imag+=rhs.imag);
}

// option one: uses copy assignment
complex complex::operator+(const complex &rhs) const
{
  return complex(*this) += rhs;  // create a temporary var [complex(*this) or complex(real, imag)], add and return.
}

// option two: uses copy assignment
// complex complex::operator+(complex const &rhs) const { return complex(real + rhs.real, imag + rhs.imag); };

void complex::print() const { std::cout << real << " + " << imag << "i\n"; };
}  // namespace member_function
// operator with non-member function ============================================================

// ============================================================
class vec
{
 private:
  //
 public:
  float _x, _y;

  vec(){};
  vec(const float x, const float y) : _x{x}, _y{y} {};

  vec operator+(const vec &other) { return vec(_x + other._x, _y + other._y); };

  bool operator==(const vec &rhs) { return (_x == rhs._x && _y == rhs._y); }

  bool operator!=(const vec &rhs) { return !(*this == rhs); }

  void print(std::string title, const vec &other)
  {
    std::cout << title << "=(" << _x << "," << _y << ")" << std::endl;
  };
};

// ============================================================
std::ostream &operator<<(std::ostream &stream, const vec &other)
{
  stream << "(" << other._x << "," << other._y << ")";
  return stream;
}

// ============================================================
int main()
{
  // ================================
  member_function::complex a(4, 5), b(2, 3), c(1, 1);
  a.print();
  b.print();
  c.print();

  std::cout << "here is c+=\n";
  c += a;
  c.print();

  std::cout << "here is c\n";
  c = a + b;
  c.print();
  a.print();
  b.print();

  // ================================
  std::cout << "\n test vector summation \n ";
  vec avec(1.0, 1.1), bvec(2.1, 2.2), cvec;
  cvec = avec + bvec;
  avec.print("a", avec);
  bvec.print("b", bvec);
  cvec.print("c", cvec);

  std::cout << " this is the operator overload: " << cvec << std::endl;
  bool eq1 = cvec == avec;
  std::cout << " == operator overload: " << eq1 << std::endl;

  bool eq2 = cvec != avec;
  std::cout << " == operator overload: " << eq2 << std::endl;

  std::cout << " == operator overload: " << (avec == avec) << std::endl;

  return 0;
}
