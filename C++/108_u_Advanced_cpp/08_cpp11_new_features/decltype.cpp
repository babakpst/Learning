
// Babak Poursartip
// 09/08/2020

// decltype, typeid, name mangling
// Udemy: Advanced c++

// notes:
// decltype a cpp 11 feature
// typeid output: i: int, d: double

// name mangling (this mine not in the video): c++ compiler changes the name of
// funcs, variables, internally. To see the name of variable in the object file:
// g++ -c main.cpp and then nm main.o. This will list the name of the variables.

#include <iostream>
// it is recommended to be included if you want to use typid, but w/o this is
// working as well!
#include <typeinfo>

using namespace std;

//====================================================
struct Base {}; // non-polymorphic
struct Derived : Base {};
//====================================================
struct Base2 {
  virtual void foo() {}
}; // polymorphic
struct Derived2 : Base2 {};
//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";
  int v1;     // i
  double v2;  // d
  float v3;   // f
  int *v4;    // Pi
  double *v5; // Pd
  float *v6;  // Pf
  char v7;    // c
  string v8;  // wierd: depending on the compiler

  cout << "v1: " << typeid(v1).name() << " "
       << "v2: " << typeid(v2).name() << " "
       << "v3: " << typeid(v3).name() << " "
       << "v4: " << typeid(v4).name() << " "
       << "v5: " << typeid(v5).name() << " "
       << "v6: " << typeid(v6).name() << " "
       << "v7: " << typeid(v7).name() << " "
       << "v8: " << typeid(v8).name() << " " << endl;

  cout << "\n2-----\n";
  int i, j;
  char c;

  // Get the type info using typeid operator
  const type_info &ti1 = typeid(i);
  const type_info &ti2 = typeid(j);
  const type_info &ti3 = typeid(c);

  // Check if both types are same
  if (ti1 == ti2)
    cout << "i and j are of simiar type" << endl;
  else
    cout << "i and j are of different type" << endl;

  // Check if both types are same
  if (ti2 == ti3)
    cout << "j and c are of simiar type" << endl;
  else
    cout << "j and c are of different type" << endl;

  cout << ti1.name() << endl;

  cout << "\n3-----\n";
  int myint = 50;
  string mystr = "string";
  double *mydoubleptr = nullptr;
  // cout << myint is a glvalue expression of polymorphic type; it is
  // evaluated
  const type_info &r1 = typeid(cout << myint);
  cout << '\n' << "cout<<myint has type : " << r1.name() << '\n';

  // printf() is not a glvalue expression of polymorphic type; NOT
  // evaluated
  const type_info &r2 = typeid(printf("%d\n", myint));
  cout << "printf(\"%d\\n\",myint) has type : " << r2.name() << '\n';

  cout << "\n4-----\n";
  // Non-polymorphic lvalue is a static type
  Derived d1;
  Base &b1 = d1;
  cout << "reference to non-polymorphic base: " << typeid(b1).name() << '\n';

  cout << "\n5-----\n";
  Derived2 d2;
  Base2 &b2 = d2;
  cout << "reference to polymorphic base: " << typeid(b2).name() << '\n';

  cout << "\n6-----\n";
  try {
    // dereferencing a null pointer: okay for a non-polymorphic expression
    cout << "mydoubleptr points to " << typeid(*mydoubleptr).name() << '\n';
    // dereferencing a null pointer: not okay for a polymorphic lvalue
    Derived2 *bad_ptr = nullptr;
    cout << "bad_ptr points to... ";
    cout << typeid(*bad_ptr).name() << '\n';
  } catch (const bad_typeid &e) {
    cout << " caught " << e.what() << '\n';
  }
  cout << "\n7-----\n";

  string value;
  // decltype extract the type of value, and use it to define name, basically,
  // the second line is equivalent to:
  // string name="Bob";
  decltype(value) name = "Bob";
  cout << typeid(name).name() << '\n';
  cout << name << '\n';

  puts(" \n ends");

  return 0;
}
