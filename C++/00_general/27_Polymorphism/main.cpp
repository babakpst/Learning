// Babak Poursartip

// inheritance
// polymorphism
// overriding: allowing a child class to replace the implementation of a method from the parent class.

#include <iostream>

struct A {

  int a_var;
  void call_func(double d1) {
    std::cout << "in call_func" << std::endl;
    calc_func(1);
  }
  virtual void calc_func(int c1) = 0;

  void any_func(double d2){
    printf(" I am in the A class. Number is: %f \n",d2);
  }

};

struct B : public A {
  int b_var;
  virtual void calc_func(int c1) {
    std::cout << "I am in B::calc_func" << std::endl;
    std::cout << "here is the var in B: " << c1 << std::endl;
  }

  void any_func(double d2){
    printf(" Hey, I am in the B class. Number is: %f \n",d2);
  }

};

struct C : public A {
  int c_var;
  virtual void calc_func(int c1) {
    std::cout << "I am in C::calc_func" << std::endl;
    std::cout << "here is the var in C: " << c1 << std::endl;
  }

  void any_func(double d2){
    printf(" Hey, I am in the B class. Number is: %f \n",d2);
  }

};

struct AA{
  AA(){puts(" constructor of AA");}
  ~AA(){puts(" destructor of AA");}
  void any_func(double d2){
    printf(" I am in the AA class. Number is: %f \n",d2);
  }
};

struct BB: public AA{
  BB(){puts(" constructor of BB");}
  ~BB(){puts(" destructor of BB");}
  void any_func(double d2){
    printf(" I am in the BB class. Number is: %f \n",d2);
  }
};

struct CC: public AA{
  CC(){puts(" constructor of CC");}
  ~CC(){puts(" destructor of CC");}
  void any_func(double d2){
    printf(" I am in the CC class. Number is: %f \n",d2);
  }
};

int main() {

  A *p_a, *p_b, *p_c;
  //p_a = new A; instantiation from an abstract class is not possible.
  p_b = new B;
  p_c = new C;

  puts("===========");  
  p_b->call_func(1.0);
  p_c->call_func(5.0);

  p_b->calc_func(44);
  p_c->calc_func(45);

  p_a->any_func(1.123);
  p_b->any_func(1.124);
  p_c->any_func(1.125);

  (*p_b).a_var = 91;
  //(*p_b).b_var = 92;  // This is wrong, bcs p_b is an A instantiation.
  printf("a_var %d \n", (*p_b).a_var);
  //printf("a_var %d, b_var %d \n", (*p_b).a_var, (*p_b).b_var);

  p_b->a_var = 93;
  printf("a_var %d \n", (*p_b).a_var);
  puts("===========");  

  
  delete p_b, p_c;



  puts("===========");    
  puts("===========");  
  B b_obj;
  b_obj.calc_func(8);
  b_obj.a_var = 81;
  b_obj.b_var = 82;
  printf("a_var %d, b_var %d \n", b_obj.a_var, b_obj.b_var);

  C c_obj;
  c_obj.calc_func(12);


  puts("===========");    
  puts("===========");  
  C *pc = new C;
  pc->calc_func(129);
  pc->a_var = 987;
  pc->c_var = 986;
  printf("a_var %d, c_var %d \n", pc->a_var, pc->c_var);

  puts("===========");  
  B *pb = new B;
  pb->calc_func(188);

  pb->a_var = 1987;
  pb->b_var = 1986;
  printf("a_var %d, b_var %d \n", pb->a_var, pb->b_var);

  puts("===========");  
  AA *paa, *pbb, *pcc;
  paa = new AA;
  pbb = new BB;
  pcc = new CC;

  paa->any_func(1.126);
  pbb->any_func(1.127);
  pcc->any_func(1.128);

  BB *pntr_b=new BB;
  CC *pntr_c=new CC;
  pntr_b->any_func(1.227);
  pntr_c->any_func(1.327);

  delete paa;
  delete pbb;
  delete pcc;

  delete pntr_b;
  delete pntr_c;
  


  puts("===========");  
  puts("===========");  
  puts(" Code terminates successfully!");    
  delete pb, pc;
 
 return 0;
}
