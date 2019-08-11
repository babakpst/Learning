
#include "calc_cls.h"

template <class T1, class T2> main_ns::calc_cls<T1, T2>::calc_cls(T1 a, T2 b) {
  std::cout << " Yes, we are inside the constructor!" << std::endl << std::endl;
  var1 = a;
  var2 = b;
}

template <class T1, class T2> void main_ns::calc_cls<T1, T2>::calc1_fn() {
  std::cout << " inside calc1" << std::endl;
  results1 = 2 * var1;
}

template <class T1, class T2> void main_ns::calc_cls<T1, T2>::calc2_fn() {
  std::cout << " inside calc2" << std::endl;
  results2 = 2 * var2;
}

template <class T1, class T2> void main_ns::calc_cls<T1, T2>::print_fn() {
  std::cout << " printing ..." << std::endl;
  std::cout << " The first var is: " << results1 << std::endl;
  std::cout << " The second var is: " << results2 << std::endl;
}

// void temporaryFunction() { main_ns::calc_cls<double, int> object(3.0, 3); }
