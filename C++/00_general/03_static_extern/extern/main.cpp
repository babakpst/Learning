
// Babak Poursartip

//10/04/2020

// https://www.youtube.com/watch?v=f3FVU-iwNuA&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=21&ab_channel=TheCherno

/* 
- We cannot have two variables/functions with the same name, unless one of them is static.

- The other option is to modify one of them as the extern. Than means the compiler is going to look for this variable in an external translation unit. 

*/


#include <iostream>

//int s_var = 10; // 1
extern int s_var;  // 2

void func(){
static int i = 0; // stay alive, 
i++;
std::cout << " func: " << i << std::endl;
}

int main(){

  func(); // 1
  func(); // 2
  func(); // 3
  func(); // 4
  func(); // 5
  std::cout << " main: " <<  s_var << std::endl;

return 0;
}
