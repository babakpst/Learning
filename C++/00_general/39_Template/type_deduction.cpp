
/*

Babak Poursartip

12/12/2021

Prior to C++17, type argument deduction applied only to funciton templates, not to class template.

*/

#include <iostream>

//=============================================
// rational class
template <typename T>
class rational
{
public:

// cotr
rational():numerator{(T)1}, denumenator{(T)1}{ std::cout << " ctor \n";}
//template<> rational():numerator{(int)1}, denumenator{(int)1}{ std::cout << " ctor \n";}
rational(T num, T den):numerator{num}, denumenator{den}{ std::cout << " ctor \n";}

// copy ctor
rational(const rational<T> &rhs) : numerator{rhs.numerator}, denumenator{rhs.denumenator} {}


// assignment operator
rational& operator=(const rational& rhs)
{
  if (this != &rhs)
  {
    this->numerator = rhs.numerator;
    this->denuminator = rhs.denuminator;
  }
return *this;
}

// dtor
~rational(){std::cout << " dtor \n";}

// getter
T getNum(){return numerator;}
T getDen(){return denumenator;}

T getNum() const {return numerator;}
T getDen() const {return denumenator;}


private:
T numerator, denumenator;

};

//=============================================
template <typename T>
std::ostream &operator<<(std::ostream &out, const rational<T> &val)
{
  return out << val.getNum() << "/" << val.getDen();
}

// ================================
int main()
{
  std::cout << " starts here ... \n";
  rational<double> r1;
  rational<float> r2;
  rational<int> r3(1,2);
  rational r4(r3); // type deduction for classes was not allowed in c++17 before, run with c++17
  rational<int> r5(r3);

  std::cout << r1 << std::endl;
  std::cout << r2 << std::endl;
  std::cout << r3 << std::endl;
   
  
  std::cout << " Done. \n";
  return 0;
}
