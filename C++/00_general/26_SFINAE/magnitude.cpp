

/*

Babak Poursartip
11/20/2021

type_traits type traits

source: modern C++ book, page: 228

*/

#include <iostream>
#include <complex>

template <typename T>
struct Magnitude
{
  using type=T;
};

template <typename T>
struct Magnitude <std::complex<T>>
{
  using type=T;
};

template<typename T>
T inline min_magnitude(const T& x, const T& y)
{
  using std::abs;
  typename Magnitude<T>::type ax=abs(x), ay=abs(y);
  return ax<ay?x:y;
};


int main()
{
  using std::cout, std::endl;

  cout << " starts here \n";

  int ix = 5, iy=-4;
  cout << " int: " << min_magnitude(ix, iy) << endl;

  std::complex<double> cx(5.0,2.0), cy(-4.0,8.1);
  cout << " complex x: " << cx << endl;
  cout << " complex y: " << cy << endl;
  auto out = min_magnitude(cx, cy);
  cout << " complex: " << out << endl;
  
  cout << " End. \n";
  return 0;
}