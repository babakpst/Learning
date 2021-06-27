
// Babak Poursartip
// 09/27/2020

// virtual function with default value

/*
- In general, it is a best practice to avoid default values in virtual functions
to avoid confusion.

- Default arguments do not participate in signature of functions. So signatures
of fun() in base class and derived class are considered same, hence the fun() of
base class is overridden.

- If you call through a base class object, pointer or reference, the default
denoted in the base class is used. Conversely, if you call through a derived
class object, pointer or reference the defaults denoted in the derived class are
used. There is an example below the Standard quotation that demonstrates this.

*/
#include <iostream>
using namespace std;

// ======================================
class Base {
public:
  virtual void fun(int x = 4) { cout << "Base::fun(), x = " << x << endl; }
};

class Derived : public Base {
public:
  virtual void fun(int x) { cout << "Derived::fun(), x = " << x << endl; }
};

// =========================================================
class Derived2 : public Base {
public:
  virtual void fun(int x = 10) // NOTE THIS CHANGE
  {
    cout << "Derived::fun(), x = " << x << endl;
  }
};

// ===========================================
int main() {
  cout << " 1 ======= \n";
  Derived d1;
  Base *bp = &d1;

  // This will cal the fun in the derived class, but initiate x with 4 from the
  // base class
  bp->fun();

  cout << " 2 ======= \n";
  // The output of this program is same as the previous program. The reason is
  // same, the default value is substituted at compile time. The fun() is called
  // on bp which is a pointer of Base type. So compiler substitutes 4 (not 10)

  // calling from a base pntr, thus it uses the base default.
  Base *bp2 = new Derived2;
  bp2->fun();

  cout << " 3 ======= \n";
  Derived *dp1 = new Derived;
  //dp1->fun(); // this is an error

  cout << " 4 ======= \n";
  Derived2 *dp2 = new Derived2;
  dp2->fun();

  return 0;
}
