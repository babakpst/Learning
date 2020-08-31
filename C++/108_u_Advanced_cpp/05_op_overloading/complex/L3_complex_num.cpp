
// Babak Poursartip
// 08/30/2020

// Operator overloading:
// Udemy: Advanced c++

#include "complex.h"
#include <iostream>

using namespace std;
using namespace myComplex;
//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  complex c1;
  complex c2(3.0, 4.0);
  complex c3(c2);

  c1 = c3;

  cout << c1 << ":" << c2 << endl;
  cout << (c1 + c2) << endl;
  cout << c1 + c2 + c3 << endl;
  cout << c1 + 10.0 << endl;
  cout << 10 + c1 << endl;

  cout << "==================================" << endl;
  if (c1 == c2)
    cout << "equal\n";
  else
    cout << "not equal\n";

  if (c1 != c2)
    cout << "not equal--\n";
  else
    cout << "equal--\n";

  puts(" \n ends");

  cout << " conjugate ============================" << endl;

  cout << *c1 << endl;
  cout << *c1 + complex(6, 3) << endl;
  cout << *c1 + *complex(6, 3) << endl;

  return 0;
}
