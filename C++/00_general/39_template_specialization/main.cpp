
// Babak Poursartip
// 08/31/2020

// template specialization
// templates -> parametric polymorphism.

#include <cmath>
#include <iostream>

using namespace std;

// a template that works but for char.
template <class T> class Babak {
public:
  Babak(T x) { cout << x << " is not a character\n"; }
};

// now we have a class that works for char (template specialization)
template <> // <> empty
class Babak<char> {
public:
  Babak(char x) { cout << x << " now x is a char\n"; }
};

//====================================================
// tag dispatch
// SFINAE: Specialization Is Not An Error
template <typename T> bool Equal(T lhs, T rhs) { return lhs == rhs; }
// for float
// template <typename T> bool Equal(T lhs, T rhs) { return lhs == rhs; }
// for nonfloat
// template <typename T> bool Equal(T lhs, T rhs) { return lhs == rhs; }

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  Babak<int> obj(5);
  Babak<float> obj2(5.0);
  Babak<double> obj3(6);
  Babak<char> obj4('b'); // specialization
  Babak<int> obj5(5.0);
  // Babak obj6(5.0); // error

  puts(" \n ends");

  return 0;
}