
/*
Babak Poursartip
25 August 2019

check the "assert" command

 */


#include <iostream>
#include <assert.h>

int main(){

  std::cout << " the code starts ...\n";

  int x=0;
  assert(x==0);

  std::cout << " The value of x is: " << x << "\n";


  int length = -12;
  std::cout << " Here is the length: " << length << "\n";
  
  //assert(4<3); // execution stops here, if uncomment
  std::cout << " here is passed\n";

  //assert(x<length);// execution stops here, if uncomment
  std::cout << " here is passed\n";


  // static_assert
  //static_assert(2>3, "four is greater than 3"); // execution stops here, if uncomment
  std::cout << " static_assert\n";
  
  
  assert("Length should be positive!" && length>=0);
  std::cout << " passed the assert. \n";


    
  return 0;
}
