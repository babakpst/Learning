// function overload override
// virtual

/*
Function Overloading VS Function Overriding

-- Inheritance: Overriding of functions occurs when one class is inherited from another class. Overloading can occur without inheritance.

-- Function Signature: Overloaded functions must differ in function signature ie either number of parameters or type of parameters should differ. In overriding, function signatures must be same.

-- Scope of functions: Overridden functions are in different scopes; whereas overloaded functions are in same scope.

-- Behavior of functions: Overriding is needed when derived class function has to do some added or different job than the base class function. Overloading is used to have same name functions which behave differently depending upon parameters passed to them.
*/

//override: When a method in a subclass has the same name and type signatures as a method in the superclass, then the method in the subclass overrides the method in the superclass.

//Overloading allows different methods to have same name, but different signatures where signature can differ by number of input parameters or type of input parameters or both. Overloading is related to compile time (or static) polymorphism..





// CPP program to illustrate Function Overloading
#include <iostream>
using namespace std;

// overloaded functions
// Method 1
void test(int var) { cout << "Integer number: " << var << endl; }

// Method 2
void test(float var) { cout << "Float number: " << var << endl; }

// Method 3
void test(int var1, float var2) {
  cout << "Integer number: " << var1;
  cout << " and float number:" << var2;
}

// ======================================================================
// CPP program to illustrate Function Overriding
class BaseClass {
public:
  int x;
  BaseClass() {
    x = 10;
    cout << "\nThis is ctor of BaseClass\n";
  };
  virtual void Display() {
    cout << "\nThis is Display() method of BaseClass\n";
  }
  void Show() { cout << "\nThis is Show() method of BaseClass\n"; }
  void scrBase() { cout << "\nThis is scrBase() method of BaseClass\n"; }
};

class DerivedClass : public BaseClass {
public:
  int y;
  DerivedClass() {
    y = 15;
    cout << "\nThis is ctor of DerivedClass\n";
  };
  // Overriding method - new working of base class's display method
  void Display() { cout << "\nThis is Display() method of DerivedClass\n"; }
  void Show() { cout << "\nThis is Show() method of DerivedClass\n"; }
  void scrDerived() { cout << "\nThis is scrDerived() method of DerivedClass\n"; }
};

// ======================================================================
int main() {
  int a = 5;
  float b = 5.5;

  // ====================================================================
  // Overloaded functions with different type and number of parameters
  test(a);
  test(b);
  test(a, b);
  puts("\n\n =============== overload ends");

  // ====================================================================
  puts("0 ===============");
  DerivedClass dr;
  dr.Show();
  dr.Display();
  dr.scrBase();
  dr.scrDerived();

  dr.BaseClass::Show();
  dr.BaseClass::Display();
  dr.BaseClass::scrBase();
  cout << "x=" << dr.x << "\n";
  cout << "y=" << dr.y << "\n";

  puts("1 ===============");
  BaseClass bs;
  bs.Show();
  bs.Display();
  bs.scrBase();
  // bs.scrDerived();  error
  cout << "x=" << bs.x << "\n";
  // cout << "y=" << bs.y << "\n"; error

  puts("2 ===============");
  BaseClass *pbs = new DerivedClass;
  pbs->Show();    // base
  pbs->Display(); // derived
  pbs->scrBase(); // base
  // pbs->scrDerived(); error
  cout << "x=" << pbs->x << "\n";
  // cout << "y=" << pbs->y << "\n"; error

  puts("3 ===============");
  DerivedClass *pbs2 = new DerivedClass;
  pbs2->Show();       
  pbs2->Display();
  pbs2->scrBase();
  pbs2->scrDerived();

  pbs2->BaseClass::Show();
  pbs2->BaseClass::Display();
  pbs2->BaseClass::scrBase();
  cout << "x=" << pbs2->x << "\n";
  cout << "y=" << pbs2->y << "\n";

  puts("4 ===============");
  BaseClass &bs2 = dr;
  bs2.Display();

  return 0;
}
