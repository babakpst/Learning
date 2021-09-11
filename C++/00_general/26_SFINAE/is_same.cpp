
// Babak Poursartip
// 09/03/2021

// topic: SFINAE, is_same, is_same_v
// SFINAE: Substitution Failure Is Not An Error

// should be run with -std=c++17 flag for is_same_v

#include <iostream>


//================================
struct AA{int x,y;};
struct BB{int x,y;};
typedef AA CC;

// ===============================
int main()
{

std::cout << " starts \n";

std::cout << " int & int32_t: " << std::boolalpha << std::is_same<int, int32_t>::value << std::endl;
std::cout << " int & int64_t: " << std::boolalpha << std::is_same<int, int64_t>::value << std::endl;
std::cout << " int & size_t: " << std::boolalpha << std::is_same<int, size_t>::value << std::endl;
std::cout << " uint64_t & size_t: " << std::boolalpha << std::is_same<uint64_t, size_t>::value << std::endl;

std::cout << " AA & BB: " << std::boolalpha << std::is_same_v<AA, BB> << std::endl;
std::cout << " AA & CC: " << std::boolalpha << std::is_same_v<AA, CC> << std::endl;

long double num1 = 1.0;
long double num2 = 2.0;
std::cout << std::is_same_v<decltype(num1), decltype(num2)> << '\n'; 


std::cout << " ends here \n";

return 0;
}
