
/*

Babak Poursartip

12/21/2021

Giant try-catch block.

*/


#include <iostream>


class test
{
private:
  int ivar;
public:
  test():ivar{0}{std::cout << "default ctor \n";}
  test(int a):ivar{a}{std::cout << "non-default ctor \n";}

  void throwException()
  {
    std::cout << " now throwing exception \n ";
    throw 20;
  }
};




int main()
try
{
  std::cout << " starts ... \n";
  test myT1;
  test myT2(5);  
  myT1.throwException();
  std::cout << " done. \n";
  return 0;
}
catch(const int &message)
{
  std::cout << " int catch starts ... \n";
  std::cout << message << std::endl;
  std::cout << " int catch done. \n";
  return 0;
}
catch(const std::exception &e)
{
  std::cout << " catch starts ... \n";
  std::cout << e.what() << std::endl;
  std::cout << " catch done. \n";
  return 0;
}
