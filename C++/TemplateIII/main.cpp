
#include "calc_cls.cpp"
#include "calc_cls.h"

//=======================================
int main() {

  std::cout << " OK, Lets get started:" << std::endl;

  main_ns::calc_cls<double, int> object(3.0, 3);

  object.calc1_fn();
  object.calc2_fn();
  object.print_fn();

  std::cout << " Alright. Done." << std::endl;

  return 0;
}
