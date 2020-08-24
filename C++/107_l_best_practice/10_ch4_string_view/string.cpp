// from https://www.learncpp.com/cpp-tutorial/6-6a-an-introduction-to-stdstring_view/
// not in the linkedin course

#include <iostream>
#include <string_view>
 
int main()
{
  std::string_view str{ "Trains are fast!" };
 
  std::cout << str.length() << '\n'; // 16
  std::cout << str.substr(0, str.find(' ')) << '\n'; // Trains
  std::cout << (str == "Trains are fast!") << '\n'; // 1
 
  // Since C++20
  std::cout << str.starts_with("Boats") << '\n'; // 0
  std::cout << str.ends_with("fast!") << '\n'; // 1
 
  std::cout << str << '\n'; // Trains are fast!
 
  return 0;
}


