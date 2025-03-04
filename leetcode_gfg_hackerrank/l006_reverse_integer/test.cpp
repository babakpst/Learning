#include <climits>
#include <iostream>

int main(int argc, char* argv[])

{
  std::cout << " starts ... \n";

  int num1 = INT_MAX;

  int num2 = num1 - 20;

  std::cout << INT_MAX << std::endl;

  std::cout << std::boolalpha << (num2 + 20 > num1) << " " << num2 + 20 << std::endl;
  std::cout << std::boolalpha << (746384741 * 10 + 2 > num1) << " " << 746384741 * 10 + 2 << std::endl;
  std::cout << std::boolalpha << (746384741 * 10 > num1) << " " << 746384741 * 10 << std::endl;

  std::cout << std::boolalpha << (num2 + 21 > num1) << " " << num2 + 21 << std::endl;

  int num3 = INT_MIN;

  int num4 = num3 + 20;

  std::cout << INT_MIN << std::endl;

  std::cout << std::boolalpha << (num4 - 20 < num3) << " " << num4 - 20 << std::endl;

  std::cout << std::boolalpha << (num4 - 21 < num3) << " " << num4 - 21 << std::endl;

  std::cout << " done \n";

  return 0;
}
