
#include <iostream>

class test
{
 public:
  int var1 = 1;

 private:
  int var2_ = 2;

 public:
  int sum() { return var1 + var2_; }
  int getvar() { return var2_; }
};

int main()
{
  test obj;

  std::cout << obj.var1 << std::endl;
  // std::cout << obj.var2_ << std::endl; // error
  std::cout << obj.getvar() << std::endl;  // error
  std::cout << obj.sum() << std::endl;

  std::cout << "end of the code\n";
  return 0;
}
