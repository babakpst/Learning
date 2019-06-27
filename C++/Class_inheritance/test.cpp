#include <iostream>

struct A {
  void call_func(double d1) {
    std::cout << "in call_func" << std::endl;
    calc_func(1);
  }
  virtual void calc_func(int c1) = 0;
};

struct B : public A {
  virtual void calc_func(int c1) {
    std::cout << "I am in B::calc_func" << std::endl;
  }
};

struct C : public A {
  virtual void calc_func(int c1) {
    std::cout << "I am in C::calc_func" << std::endl;
  }
};

int main() {
  A *p_a, *p_c;
  p_a = new B;
  p_c = new C;
  p_a->call_func(1.0);
  p_c->call_func(5.0);
  return 0;
}
