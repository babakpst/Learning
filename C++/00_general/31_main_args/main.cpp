
/*

Babak Poursartip
11/04/2020

main arguments

*/

#include <iostream>

//int main(int argv, char **argc){
int main(int argv, char *argc[]){

  std::cout << " code starts ... \n";

  std::cout << " number of args: " << argv << std::endl;
  for (int i = 0; i<argv; ++i){
    std::cout << " arg: " << i << " is: " << argc[i] << std::endl;
  }

  std::cout << " finished! \n";
  return 0;
}


