
// Babak Poursartip
// 08/31/2020

// Operator overloading:
// Udemy: Advanced c++

#include <iostream>

using namespace std;

template <class T> void print(T n) { cout << "template " << n << endl; }
template <class T> void show() { cout << T() << endl; }
void print(int n) { cout << "int version " << n << endl; }

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  print<string>("Babak");
  print<int>(5);
  print("Sihva, the dearest.");
  print(6);   // non-template version
  print<>(6); // template version

  // show(); // error bcs it cannot ifer the type.
  // show<>(); // error bcs it cannot ifer the type.

  // we need a type bcs show does not have an argumenet, and cpp cannot detect
  // the type
  show<float>();

  puts(" \n ends");

  return 0;
}
