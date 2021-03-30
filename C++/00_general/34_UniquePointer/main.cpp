// working with unique pointers
// based on the book: discovering, pp 55~

#include <iostream>
#include <memory>
#include <string>

// ========================================
class model {
public:
  model(double num) : pntr_cls{new double(num)} {};
  model(){std::cout << "ctor\n";}
  ~model(){std::cout << "dtor\n";}
  void print_cls() { std::cout << " print: " << *pntr_cls << "\n"; };
private:
  std::unique_ptr<double> pntr_cls;


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

  // class ==== important
  std::cout << "3 =========\n";

  double a_num = 12.2;

  model model_obj(a_num);
  model_obj.print_cls();

  model *pM = new model; // this will trigger the ctor, but dtor will never trigger if we do not delete it: memory leak.
  delete pM;

  //std::unique_ptr<model> pM1(new model);
  std::unique_ptr<model> pM1(std::make_unique<model>());
  //pM1 = new model;
  
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
