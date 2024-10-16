
// test.cpp : Defines the entry point for the console application.
//

#include "rec_cls.h"
#include <iostream>

using namespace std;

int main() {

  Rectangle_cls a, *b, *c;
  Rectangle_cls *d = new Rectangle_cls[2];

  b = new Rectangle_cls;
  c = &a;

  a.set_values(1, 2);
  b->set_values(3, 4);
  d->set_values(5, 6);
  d[1].set_values(7, 8);

  cout << " a area: " << a.area() << endl;
  cout << " b area: " << b->area() << endl;
  cout << " c area: " << c->area() << endl;
  cout << " d0 area: " << d[0].area() << endl;
  cout << " d1 area: " << d[1].area() << endl;

  delete[] d;
  delete b;
  delete c;

  return 0;
}