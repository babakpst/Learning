// working with unique pointers
// based on the book: discovering, pp 55~

#include <iostream>
#include <memory>
#include <string>

// ========================================
class model {
private:
  std::unique_ptr<double> pntr_cls;

public:
  model(double num) : pntr_cls{&num} {};

  void print_cls() { std::cout << " print: " << *pntr_cls << "\n"; };
};


// ========================================
void f(std::unique_ptr<int> &a){
  std::cout << " the current value of the unique_ptr inside the function is: " << *a << std::endl;
  *a = 10;
  std::cout << " the current value of the unique_ptr inside the function after change is: " << *a << std::endl;
}

// ==============================
void func(int* my){
  std::cout << " this is inside the function: " << *my << std::endl;
  *my = (*my)*3;
  std::cout << " this is inside the function: " << *my << std::endl;
}

// ==============================
int main() {

  // 1 =====================
  std::cout << "1 =========\n";
  std::unique_ptr<double> upnt{new double};
  *upnt = 12;
  std::cout << " The unique pointer is defined as: " << *upnt << "\n";

  // double dvar =5.0;
  // std::unique_ptr<double> upnt2{&dvar};   // wrong allocation

  // double var = 5.0;
  // double *dvar =&var;
  // std::unique_ptr<double> upnt2{dvar};   // wrong allocation

  // std::unique_ptr<double> upnt2{upnt};   wrong

  std::cout << "2 =========\n";
  std::unique_ptr<double> upnt3;
  // upnt3 = upnt; wrong, you cannot assign it


  double *raw_pntr(new double);
  raw_pntr = upnt.get();
  std::cout << " This is a raw pointer: " << *raw_pntr << "\n";
  *raw_pntr=15;
  std::cout << " This is a raw pointer: " << *raw_pntr << "\n";
  std::cout << " The unique pointer is defined as: " << *upnt << "\n";
  raw_pntr = nullptr; // we need this otherwise it would a double free.
  delete raw_pntr;

  std::cout << "3 =========\n";
  // class
  double a_num = 12.2;

  /*
  model model_obj(a_num);
  model_obj.print_cls();
  */


  
  std::cout << "4 =========\n";
  // pass to a function ======== 
  std::unique_ptr<int> mUP(new int(5));
  std::cout << " the value of the unique_ptr in the main function is: " << *mUP << std::endl;
  f(mUP);
  std::cout << " the value of the unique_ptr in the main function after passing to the func is: " << *mUP << std::endl;  

  std::cout << "\n\n5 =========\n";
  // pass to a function ======== 
  std::unique_ptr<int> mUP2(new int(60));
  std::cout << " the value of the unique_ptr in the main function is: " << *mUP2 << std::endl;
  func(mUP2.get());
  std::cout << " the value of the unique_ptr in the main function is: " << *mUP2 << std::endl;


  std::cout << "\n finished successfully\n";
  return 0;
}
