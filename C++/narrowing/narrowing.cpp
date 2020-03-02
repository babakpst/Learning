#include <iostream>
#include <iomanip> // to be able to use setw.

int main(){

  std::cout << " Code starts ... \n";

  double var_1=12.1234567890123456789f;
  float var_2=12.1234567890123456789f;
  double var_3={12.1234567890123456789f};
  double var_4={12.1234567890123456789f};
  double var_5=12.1234567890123456789;
  float var_6={12.1234567890123456789};
  // int var_7    ={12.1234567890123456789};  ERROR
  double var_8 ={12};
  double var_9 ={12.0};

  std::cout << " double:" <<  std::setprecision (20) << var_1 << "\n";
  std::cout << " double:" <<  var_2 << "\n";
  std::cout << " double:" <<  var_3 << "\n";
  std::cout << " double:" <<  var_4 << "\n";
  std::cout << " double:" <<  var_5 << "\n";
  std::cout << " float: " <<  var_6 << "\n";
//  std::cout << " int:   " <<  var_7 << "\n";
  std::cout << " double:" << std::setprecision (20)<< var_8 << "\n";
  std::cout << " double:" << std::setprecision (20)<< var_9 << "\n";

  std::cout << " Code ends. \n"; 
  return 0;
}
