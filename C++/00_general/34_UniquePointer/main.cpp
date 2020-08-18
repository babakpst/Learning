

// working with unique pointers
// based on the book: discovering, pp 55~

#include <iostream>
#include <memory>
#include <string>

class model {
private:
  std::unique_ptr<double> pntr_cls;

public:
  model(double num) : pntr_cls{&num} {};

  void print_cls() { std::cout << " print: " << *pntr_cls << "\n"; };
};

int main() {

  std::unique_ptr<double> upnt{new double};
  *upnt = 12;

  std::cout << " The unique pointer is defined as: " << *upnt << "\n";
  // std::cout << " The unique pointer is defined as: " <<  "\n";

  // double dvar =5.0;
  // std::unique_ptr<double> upnt2{&dvar};   // wrong allocation

  // double var = 5.0;
  // double *dvar =&var;
  // std::unique_ptr<double> upnt2{dvar};   // wrong allocation

  // std::unique_ptr<double> upnt2{upnt};   wrong

  std::unique_ptr<double> upnt3;
  // upnt3 = upnt; wrong, you cannot assign it

  double *raw_pntr = upnt.get();
  std::cout << " This is a raw pointer: " << *raw_pntr << "\n";

  // class
  double a_num = 12.2;

  model model_obj(a_num);
  model_obj.print_cls();

  return 0;
}
