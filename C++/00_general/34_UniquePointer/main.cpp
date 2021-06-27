// working with unique pointers
// based on the book: discovering, pp 55~

#include <iostream>
#include <memory>
#include <string>

// ========================================
class model {
public:
  model(double num) : pntr_cls{new double(num)} {std::cout << " ctor \n";};
  model(){std::cout << " default ctor\n";}
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

// ========================================
void myfunc(std::unique_ptr<int> &a){
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
// ==============================
// ==============================
int main() {

  // 1 =====================
  std::cout << "1a =========\n";
  std::unique_ptr<double> upnt{new double};
  *upnt = 12;
  std::cout << " The unique pointer is defined as: " << *upnt << "\n";

  std::cout << "1b =========\n";
  //std::unique_ptr<double> upnt2{std::make_unique<double>()};
  std::unique_ptr<double> upnt2=std::make_unique<double>();
  *upnt2 = 15;
  std::cout << " The unique pointer is defined as: " << *upnt2 << "\n";

  std::cout << "1c =========\n";
  std::unique_ptr<double[]> upnt3 =std::make_unique<double[]>(5); // a unique_ptr of type double and size 5
  upnt3[0] = 0.0,upnt3[1] = 0.1,upnt3[2] = 0.2,upnt3[3] = 0.3,upnt3[4] = 0.4;

  std::cout << upnt3[0] << " " << upnt3[1] << " " << upnt3[2] << " " << upnt3[3] << " " << upnt3[4] << std::endl;

  std::cout << "1d =========\n";
  std::unique_ptr<double> upnt4 =std::make_unique<double>(5); // a unique_ptr initialized to 5
  std::cout << " initialized: " <<*upnt4 << std::endl;

  std::cout << "1e =========\n";
  //std::unique_ptr<double> upnt5 = new double[5]; 
  double *dptr = new double[5];
  //std::unique_ptr<double> upnt5(std::make_unique<double>[5]); 
  //upnt3[0] = 0.0,upnt3[1] = 0.1,upnt3[2] = 0.2,upnt3[3] = 0.3,upnt3[4] = 0.4;
  //std::cout << upnt3[0] << " " << upnt3[1] << " " << upnt3[2] << " " << upnt3[3] << " " << upnt3[4] << std::endl;

  // double dvar =5.0;
  // std::unique_ptr<double> upnt2{&dvar};   // wrong allocation

  // double var = 5.0;
  // double *dvar =&var;
  // std::unique_ptr<double> upnt2{dvar};   // wrong allocation

  // std::unique_ptr<double> upnt2{upnt};   wrong

  std::cout << "2 =========\n";
  double *raw_pntr(new double);
  raw_pntr = upnt.get();
  std::cout << " This is a raw pointer: " << *raw_pntr << "\n";
  *raw_pntr=15;
  std::cout << " This is a raw pointer: " << *raw_pntr << "\n";
  std::cout << " The unique pointer is defined as: " << *upnt << "\n";
  raw_pntr = nullptr; // we need this otherwise it would a double free.
  delete raw_pntr;

  // class ==== important
  std::cout << "3a =========\n";

  double a_num = 12.2;

  model model_obj(a_num);
  model_obj.print_cls();

  std::cout << "3b =========\n";
  model *pM = new model; // this will trigger the ctor, but dtor will never trigger if we do not delete it: memory leak.
  delete pM;

  std::cout << "3c =========\n";
  //std::unique_ptr<model> pM1(new model);
  std::unique_ptr<model> pM1(std::make_unique<model>());
  //pM1 = new model;
  std::unique_ptr<model> pM2(std::make_unique<model>(5.5));
  
  std::cout << "4a =========\n";
  // pass to a function ======== 
  std::unique_ptr<int> mUP(new int(5));
  std::cout << " the value of the unique_ptr in the main function is: " << *mUP << std::endl;
  f(mUP);
  std::cout << " the value of the unique_ptr in the main function after passing to the func is: " << *mUP << std::endl;  

  std::cout << "4b =========\n";
  // pass to a function ======== 
  std::unique_ptr<int> mUP2(std::make_unique<int>(6));
  std::cout << " the value of the unique_ptr in the main function is: " << *mUP2 << std::endl;
  myfunc(mUP2);
  std::cout << " the value of the unique_ptr in the main function after passing to the func is: " << *mUP2 << std::endl;  


  std::cout << "\n\n5 =========\n";
  // pass to a function ======== 
  std::unique_ptr<int> mUP3(new int(60));
  std::cout << " the value of the unique_ptr in the main function is: " << *mUP3 << std::endl;
  func(mUP3.get());
  std::cout << " the value of the unique_ptr in the main function is: " << *mUP3 << std::endl;


  std::cout << "\n finished successfully\n";
  return 0;
}
