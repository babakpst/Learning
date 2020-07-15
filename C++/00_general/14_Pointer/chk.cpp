
#include <iostream>
#include <sstream>



int main() {



  puts("checkpoint 100");
  float tmp;
  float *tax2=&tmp;
  *tax2 = 6325.1f;
  std::cout << " here is value the pointer is pointing: " << *tax2 << "\n";

 
  puts("End of the code.");
  return 0;
}
