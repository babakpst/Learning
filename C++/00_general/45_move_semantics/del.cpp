
#include <iostream>
#include <climits>

int main(int argc, char* argv[])
{

std::cout << " starts ... \n";

int num1 = INT_MAX;
int num2 = num1 - 20;

std::cout << INT_MAX << std::endl;
std::cout << std::boolalpha << (num2+20 > num1) << " " << num2+20  << std::endl;
std::cout << std::boolalpha << (num2+21 > num1) << " " << num2+21  << std::endl;


int num3 = INT_MIN;
int num4 = num3 + 20;
std::cout << INT_MIN << std::endl;
std::cout << std::boolalpha << (num4-20 < num3) << " " << num4-20 << std::endl;
std::cout << std::boolalpha << (num4-21 < num3) << " " << num4-21 << std::endl;


std::cout << " done \n";

return 0;
}
