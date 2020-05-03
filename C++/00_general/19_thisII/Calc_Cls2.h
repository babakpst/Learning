

#include <iostream>
using namespace std;

class Calc_Cls {

  int a_int, b_int;
  double a_dbl, b_dbl;

public:
  int res_int;
  double res_dbl;

  Calc_Cls(int, int, double, double);
  Calc_Cls(int, double);
  //~Calc_Cls();

  void Calculation_fn();
};
