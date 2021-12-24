/*

Babak Poursartip

12/23/2021

Forward declaration

*/


#include "myClass.h"

class B;

int main()
{
  std::cout << " starts ... \n";

  // ==================
  myClass myvar1;
  myvar1.func();

  myClass myvar2(5, A());
  myvar2.func();

  std::cout << " Done. \n";
  return 0;
}
