// working with unique pointers
// based on the book: discovering, pp 55~

#include <iostream>
#include <memory>
#include <string>

// ========================================
class model {
public:
  model(double num) : pntr_cls{new double(num)}, var{num} {std::cout << " ctor \n";};
  model(){std::cout << " default ctor\n";}
  ~model(){std::cout << "dtor\n";}
  void print_cls() { std::cout << " print: " << *pntr_cls << "\n"; };
  void setVar(double var){this->var=var;}
  double getVar(){return var;}
private:
  std::unique_ptr<double> pntr_cls;
  double var;
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
  // std::unique_ptr<double> upnt5 = new double[5]; //  error: conversion from ‘double*’ to non-scalar type ‘std::unique_ptr<double>’ requested
  double *dptr = new double[5]; // a double vector of size 5
  double *dptr2 = new double(5); // a double pointer initialized to 5
  std::cout << " double pointer: " << *dptr2 << std::endl;
  // std::unique_ptr<double> upnt5(std::make_unique<double>[5]); // error
  //upnt3[0] = 0.0,upnt3[1] = 0.1,upnt3[2] = 0.2,upnt3[3] = 0.3,upnt3[4] = 0.4;
  //std::cout << upnt3[0] << " " << upnt3[1] << " " << upnt3[2] << " " << upnt3[3] << " " << upnt3[4] << std::endl;

  double dvar =5.0;
  std::unique_ptr<double> upnt_test{&dvar};  

  double var = 5.0;
  double *pvar =&var;
  std::unique_ptr<double> upnt_more{pvar};

  // std::unique_ptr<double> upnt_another{upnt};   //wrong

  std::cout << "2 =========\n";
  double *raw_pntr(new double);
  raw_pntr = upnt.get();
  std::cout << " This is a raw pointer: " << *raw_pntr << "\n";
  *raw_pntr=15;
  std::cout << " This is a raw pointer: " << *raw_pntr << "\n";
  std::cout << " The unique pointer is defined as: " << *upnt << "\n";
  raw_pntr = nullptr; // we need this otherwise it would a double free.
  delete raw_pntr;

  /*
                                          // foo   bar    p
                                           // ---   ---   ---
  std::unique_ptr<int> foo;                // null
  std::unique_ptr<int> bar;                // null  null
  int* p = nullptr;                        // null  null  null

  foo = std::unique_ptr<int>(new int(10)); // (10)  null  null
  bar = std::move(foo);                    // null  (10)  null
  p = bar.get();                           // null  (10)  (10)
  *p = 20;                                 // null  (20)  (20)
  p = nullptr;                             // null  (20)  null

  foo = std::unique_ptr<int>(new int(30)); // (30)  (20)  null
  p = foo.release();                       // null  (20)  (30)
  *p = 40;                                 // null  (20)  (40)
  */

  // class ==== important
  std::cout << "3a =========\n";

  double a_num = 12.2;

  model model_obj(a_num);
  model_obj.print_cls();

  std::cout << "3b =========\n";
  model *pM = new model; // this will trigger the default ctor, but dtor will never trigger if we do not delete it: memory leak.
  delete pM;

  std::cout << "3c =========\n";
  //std::unique_ptr<model> pM1(new model);
  std::unique_ptr<model> pM1(std::make_unique<model>()); // calls the default ctor, dtor will be called at the end of the code.
  //pM1 = new model;
  std::unique_ptr<model> pM2(std::make_unique<model>(5.5)); // calls the ctor, dtor will be called at the end of the code.
  
  std::cout << "4a =========\n";
  // pass to a function with a reference ======== 
  std::unique_ptr<int> mUP(new int(5));
  std::cout << " the value of the unique_ptr in the main function is: " << *mUP << std::endl;
  f(mUP);
  std::cout << " the value of the unique_ptr in the main function after passing to the func is: " << *mUP << std::endl;  

  std::cout << "\n\n5 =========\n";
  // pass to a function ======== 
  std::unique_ptr<int> mUP3(new int(60));
  std::cout << " the value of the unique_ptr in the main function is: " << *mUP3 << std::endl;
  func(mUP3.get()); // the raw pointer has the same value as the unique pointer.
  std::cout << " the value of the unique_ptr in the main function is: " << *mUP3 << std::endl;


  std::cout << "\n\n6 =========\n";
  // assign raw pointer to a unique pointer
  // unique_ptr's constructor from a pointer is declared explicit, thus considered by the compiler only in explicit contexts. This is done so to prevent accidental dangerous conversions, where a unique_ptr can hijack a pointer and delete it without programmer's knowledge. In general, not only for unique_ptr, it is considered a good practice to declare all single-argument constructors as explicit to prevent accidental conversions.

  model *pModel = new model();
  // error
  //std::unique_ptr<model> uPtr  = pModel;
  std::unique_ptr<model> uPtr  = static_cast<std::unique_ptr<model>>(pModel);

  model *pModel2 = new model();
  pModel2->setVar(8.8);
  std::cout << " var: " << pModel2->getVar() << std::endl;
  std::unique_ptr<model> uPtr2 = std::unique_ptr<model>(pModel2);
  std::cout << " unique var: " << uPtr2->getVar() << std::endl;
  //uPtr = pModel;
  //delete pModel;

  std::cout << "\n finished successfully\n";
  return 0;
}







