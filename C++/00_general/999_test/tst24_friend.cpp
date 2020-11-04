
#include <iostream>
using namespace std;

class A {
protected:
  int x;

public:
  A() { x = 0; }
  friend void show();
};

class B : public A {
public:
  B() : y(0) {}

private:
  int y;
};

class C : public A {
public:
  C() : z(0) {}
  friend void show2();

private:
  int z;
};

void show() {
  B b;
  cout << "The default value of A::x = " << b.x << "\n";

  // Can't access private member declared in class 'B'
  // cout << "The default value of B::y = " << b.y;
}

void show2() {
  C c;
  cout << "The default value of A::x = " << c.x << "\n";

  cout << "The default value of C::y = " << c.z << "\n";
}

int main() {
  show();
  show2();
  getchar();
  return 0;
}