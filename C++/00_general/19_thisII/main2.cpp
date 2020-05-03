
// This example shows the application of "this" in the code.

#include "Calc_Cls2.h"

int main() {

  Calc_Cls param(3, 4, 3.1, 4.1);
  param.Calculation_fn();
  cout << " the result integer is: " << param.res_int << endl;
  cout << " the result double is: " << param.res_dbl << endl;

  return 0;
}
