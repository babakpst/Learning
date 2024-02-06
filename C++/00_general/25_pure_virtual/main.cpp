#include <iostream>
using namespace std;

class Base
{
  int x;

 public:
  // pure virtual function
  virtual void fun() = 0;
  int getX() { return x; }
};

// This class inherits from Base and implements fun()
class Derived : public Base
{
  int y;

 public:
  void fun() override { cout << "fun() called\n"; }
};

int main(void)
{
  //  Base obj; cannot instantiate from an abstract class.

  Derived d;
  d.fun();
  return 0;
}
