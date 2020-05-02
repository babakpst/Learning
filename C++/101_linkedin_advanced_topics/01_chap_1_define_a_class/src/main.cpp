// Linkein:  Advanced topics in c++
// Babak Poursartip
// 04/26/2020

#include "../include/c1_cls/c1_cls.h"

int main() {

  // std::cout << " code starts ... \n\n";
  printf(" code starts ... \n\n");
  const int i = 47;
  c1_cls o1;
  o1.setvalue(i);

  // std::cout << " value is: " << o1.getvalue() << "\n";
  // std::cout << "\n code ends. \n";

  printf(" value is: %d  \n", o1.getvalue());
  printf(" code ends. \n");

  return 0;
}
