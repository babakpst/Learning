/*

Babak Poursartip

12/5/2021

Discovering Modern C++: section 5.3: expression template
page 245 (The actual code in the book is not compiling).


*/

#include <algorithm>
#include <iostream>
#include <memory>

// using namespace std;

template <typename T>
class vector
{
 public:
  vector(int size) : my_size(size), data(new T[my_size]) { std::cout << " vector class ctor\n"; }
  // explicit vector(int size) : my_size(size), data(new T[my_size]) {std::cout <<" vector class
  // ctor\n";}

  ~vector() { std::cout << " vector class dtor\n"; }

  vector(const vector& that) : my_size(that.my_size), data(new T[my_size])
  {
    data = that.data;
    // std::copy(&that.data[0], &that.data[my_size], &data[0]);
  }

  int size() const { return my_size; }

  const bool check_index(int i) { return i < my_size; }
  bool check_size(int i) { return i == my_size; }

  const T& operator[](int i) const
  {
    if (check_index(i)) return data[i];
    return 0;
  }

  void setData(int i, T val) { data[i] = val; }

 private:
  int my_size;
  std::unique_ptr<T[]> data;
};

template <typename T>
inline vector<T> operator+(const vector<T>& x, const vector<T>& y)
{
  vector<T> sum(size(x));
  if (x.check_size(size(y)))

    for (int i = 0; i < size(x); ++i) sum[i] = x[i] + y[i];

  return sum;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& input)
{
  out << "vector is: ";
  for (int i = 0; i < input.size(); ++i) out << input[i] << ", ";
  out << std::endl;
  return out;
}

int main()
{
  std::cout << " starts ...\n";

  // vector<float> x = {1.1,2.1,3.1,4.1};
  // vector<float> y = {1.1, 2.1, 3.1, 4.1};
  // vector<float> z = {1.1, 2.1, 3.1, 4.1};
  const int vec_size = 4;
  vector<float> x(vec_size), y(vec_size), z(vec_size), w(vec_size);
  for (int i = 0; i < vec_size; ++i)
  {
    x.setData(i, i * .1);
    y.setData(i, i * .1);
    z.setData(i, i * .1);
  }

  std::cout << " x = " << x << std::endl;
  std::cout << " y = " << x << std::endl;
  std::cout << " z = " << x << std::endl;

  w = x + y + z;
  std::cout << " w = x + y + z = " << w << std::endl;

  std::cout << " Done.\n";
  return 0;
}
