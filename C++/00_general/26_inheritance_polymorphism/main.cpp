// Babak Poursartip

// inheritance
// polymorphism
// overloading

#include <iostream>

struct A {

  int a_var;
  void call_func(double d1) {
    std::cout << "in call_func" << std::endl;
    calc_func(1);
  }
  virtual void calc_func(int c1) = 0;
};

struct B : public A {
  int b_var;
  virtual void calc_func(int c1) {
    std::cout << "I am in B::calc_func" << std::endl;
    std::cout << "here is the var in B: " << c1 << std::endl;
  }
};

struct C : public A {
  int c_var;
  virtual void calc_func(int c1) {
    std::cout << "I am in C::calc_func" << std::endl;
    std::cout << "here is the var in C: " << c1 << std::endl;
  }
};

int main() {

  A *p_b, *p_c;
  p_b = new B;
  p_c = new C;

  puts("===========");  
  p_b->call_func(1.0);
  p_c->call_func(5.0);

  (*p_b).a_var = 91;
  //(*p_b).b_var = 92;
  printf("a_var %d \n", (*p_b).a_var);
  //printf("a_var %d, b_var %d \n", (*p_b).a_var, (*p_b).b_var);

  p_b->a_var = 93;
  printf("a_var %d \n", (*p_b).a_var);
  puts("===========");  
  p_b->calc_func(44);
  p_c->calc_func(45);
  
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
  puts("===========");  
  puts(" Code terminates successfully!");    
  delete pb, pc;
 
 return 0;
}
