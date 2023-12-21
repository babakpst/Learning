
#include <iostream>

int func1(int init)
{
  int ret = init;
  for (int j = 0; j < 10000; j++)
    for (int i = 0; i < 10000; i++)
    {
      ret += i - 14;
    }
  return ret;
}

int func2(int init)
{
  int ret = init;
  for (int j = 0; j < 20000; j++)
    for (int i = 0; i < 20000; i++)
    {
      ret += i - 14;
    }
  return ret;
}

int main()
{
  std::cout << " code starts here \n";

  std::cout << func1(18) << std::endl;

  std::cout << func2(20) << std::endl;

  std::cout << " done \n";
  return 0;
}
