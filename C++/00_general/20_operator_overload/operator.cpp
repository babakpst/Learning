/*

Babak Poursartip
05/04/2020
updated on 08/20/2020
operator overloading

geeksforgeeks

*/

#include <iostream>

// ============================================================
class complex
{
 private:
  int real, imag;

 public:
  complex();          // ctor
  complex(int, int);  // ctor
  // complex(const complex&); // copy ctor
  // const complex &operator=(const complex &);  // copy assignment

  complex operator+(const complex &) const;
  // complex operator+(const complex &);
  complex &operator+=(const complex &);
  void print() const;
};

complex::complex(int real = 0, int imag = 0) : real(real), imag(imag){};

// const complex &operator=(const complex &);  // copy assignment

complex &complex::operator+=(const complex &rhs)
{
  std::cout << rhs.real << " +i" << rhs.imag << std::endl;
  std::cout << this->real << " +i" << this->imag << std::endl;
  this->real += rhs.real;
  this->imag += rhs.imag;
  return *this;
  // return complex(real+=rhs.real, imag+=rhs.imag);
}

complex complex::operator+(complex const &rhs) const { return complex(real + rhs.real, imag + rhs.imag); };
// complex complex::operator+(const complex &rhs){return (*this)+=rhs;} // Wrong, it changes both right and left hand
// side.

void complex::print() const { std::cout << real << " + " << imag << "i\n"; };

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
  complex a(4, 5), b(2, 3), c(1, 1);
  a.print();
  b.print();

  std::cout << "here is c+=\n";
  c += a;
  c.print();
  a.print();

  std::cout << "here is c\n";
  c = a + b;
  c.print();
  a.print();
  b.print();

  std::cout << "here is c+=\n";
  c += b;
  c.print();

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
