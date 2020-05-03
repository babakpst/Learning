#include "Dummy_Cls.h"
#include <iostream>

using namespace std;
int main() {
  Dummy a;
  Dummy *b = &a;
  if (b->isitme(a))
    cout << "yes, &a is b\n";
  return 0;
}