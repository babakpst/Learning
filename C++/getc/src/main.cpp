

// Babak Poursartip
// 24 August 2019


#include <iostream>


int power(int x){return x*x;}

int main(){

  int z;

  if (getc(stdin)=='a') z=power(6)+6;
  else z=power(7)-7;

  std::cout << " Here are the results: " << z << "\n";
  
  
  return 0;
}
