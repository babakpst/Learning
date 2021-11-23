
/*

Babak Poursartip
11/21/2021

type_traits type traits

source: https://www.cplusplus.com/reference/type_traits/is_integral/
topic: SFINAE, is_same, is_same_v
SFINAE: Substitution Failure Is Not An Error
Should be run with -std=c++17 flag for is_same_v

*/
#include <iostream>
#include <type_traits>


//================================
struct AA{int x,y;};
struct BB{int x,y;};
typedef AA CC;
using DD = AA;


// ==============================
int main() {
  
  std::cout << " starts \n";
  // is_same
  std::cout << " int & int32_t: " << std::boolalpha << std::is_same<int, int32_t>::value << std::endl;
  std::cout << " int & int64_t: " << std::boolalpha << std::is_same<int, int64_t>::value << std::endl;
  std::cout << " int & size_t: " << std::boolalpha << std::is_same<int, size_t>::value << std::endl;
  std::cout << " uint64_t & size_t: " << std::boolalpha << std::is_same<uint64_t, size_t>::value << std::endl;

  std::cout << " AA & BB: " << std::boolalpha << std::is_same_v<AA, BB> << std::endl;
  std::cout << " AA & CC: " << std::boolalpha << std::is_same_v<AA, CC> << std::endl;
  std::cout << " AA & DD: " << std::boolalpha << std::is_same_v<AA, DD> << std::endl;

  long double num1 = 1.0;
  long double num2 = 2.0;
  std::cout << std::is_same_v<decltype(num1), decltype(num2)> << '\n'; 
  
  // is_integral
  std::cout << std::boolalpha;
  std::cout << "is_integral:" << std::endl;
  std::cout << "char: " << std::is_integral<char>::value << std::endl;
  std::cout << "int: " << std::is_integral<int>::value << std::endl;
  std::cout << "float: " << std::is_integral<float>::value << std::endl;
  std::cout << "double: " << std::is_integral<double>::value << std::endl;

  std::cout << "uint: " << std::is_integral_v<uint> << std::endl;

  // is_floating_point
  std::cout << " is_floating_point<float>: " << std::is_floating_point<float>::value << '\n';
  std::cout << " is_floating_point<float&>: " << std::is_floating_point<float&>::value << '\n';
  std::cout << " is_floating_point<double>: " << std::is_floating_point<double>::value << '\n';
  std::cout << " is_floating_point<double&>: " << std::is_floating_point<double&>::value << '\n';
  std::cout << " is_floating_point<int>: " << std::is_floating_point<int>::value << '\n';  

  std::cout << " ends here \n";
  return 0;
}