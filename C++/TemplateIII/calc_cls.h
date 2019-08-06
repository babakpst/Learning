
#include <iostream>

#ifndef CALC_CLS
#define CALC_CLS

namespace main_ns {

template <class T1, class T2> class calc_cls {
  T1 var1, results1;
  T2 var2, results2;

public:
  calc_cls(T1, T2);
  void calc1_fn();
  void calc2_fn();
  void print_fn();
};
}

#include "calc_cls.tcpp"

#endif // !CALC_CLS