/*

based on pluralsight: Practical C++14 and C++17 features

constexpr: allows to evaluate the value of a function of variable at compile time, then be used where only compile time constant expressions are allowed.

- restrictions: The function should not be virtual
- return type should be a literal type (not in c++20)
- each parameter/argument should be a literal type
- should not have goto, label, try block, ... .
- a constexpr function can only call a constexpr function. 

*/
#include "iostream"

//===================================
constexpr int add(const int &a, const int &b)
{
  if (a>0) return a+b;
  else return -a+b;
}

//===================================
class AA
{
  public:
    static const int C1;
    //static constexpr int C2; // error, we should declare it : static data member ‘C2’ must have an initializer
    //constexpr int C3=2; // error non-static data member ‘C3’ declared ‘constexpr’
    static constexpr int C2 =2;

};

// =================================
int main(int argc, char *argv[])
{
  std::cout << " starts ... \n";

  constexpr int var=1; // error  

  std::cout << add(1,2) << std::endl; // runs at compile time
  std::cout << add(-1,2) << std::endl; // runs at compile time  

  int a, b;
  std::cin >> a >> b;
  std::cout << add(a,b) << std::endl;

  std::cout << " ends  \n";
  return 0;
}
