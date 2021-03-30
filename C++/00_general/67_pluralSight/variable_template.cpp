/*

based on pluralsight: Practical C++14 and C++17 features

*/
#include "iostream"

template<typename T>
constexpr T max = T(123);

template<>
constexpr double max<double> = 456;

template<>
constexpr char max<char> = 'a';

int main(int argc, char *argv[])
{
std::cout << " starts ... \n";

std::cout << max<int> << std::endl;
std::cout << max<double> << std::endl;
std::cout << max<char> << std::endl;

std::cout << " ends  \n";
return 0;
}
