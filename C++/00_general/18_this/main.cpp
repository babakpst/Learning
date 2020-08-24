#include "Dummy_Cls.h"
#include <iostream>

using namespace std;
int main() {
  Dummy a;
  Dummy *b = &a;
  if (b->isitme(a))
    cout << "yes, &a is b\n";

  Dummy bb, cc;
  if (bb.isitme(cc))
    cout << "yes, bb is ccn";
  else
    cout << "no, we are not the same\n";

  return 0;
}