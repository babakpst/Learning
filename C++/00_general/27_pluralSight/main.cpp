/*

based on pluralsight: Practical C++14 and C++17 features

*/
#include <iostream>
#include <map>

namespace babak::shiva{
int a;
};

int main(int argc, char *argv[])
{
std::cout << " starts ... \n";

int a = 10'000'000;
std::cout << " a: " << a << std::endl;

int b = 0b00000100;
std::cout << " b: " << b << std::endl;

int c = 0B00001100;
std::cout << " c: " << c << std::endl;

int d = 0b00001100'00000100;
std::cout << " d: " << d << std::endl;


// nested namesapce



std::map<std::string, std::string> italianDictionary{
{"123","258"},
{"196","266"},
{"885","98"},
{"4","487"},
};

for (const auto &[one, two]: italianDictionary){
  std::cout << one << " " << two << std::endl;
}

std::cout << " ends  \n";
return 0;
}
