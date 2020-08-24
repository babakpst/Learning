#include <iostream>

using namespace std;

class Base {
public:
  Base() { puts(" base ctor"); }
  void f() { cout << "Base\n"; }
};

class Derived : public Base {
public:
  Derived() { puts(" derived ctor"); }
  void f() { cout << "Derived\n"; }
};

int main() {
  Derived obj;

  obj.f();
  obj.Base::f();

  puts("=============");
  Base *p = new Derived();
  p->f();
  puts("=============");
  Derived *p2 = new Derived();
  p2->f();
}