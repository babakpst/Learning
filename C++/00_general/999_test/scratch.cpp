
#include <iostream>
#include <vector>
#include <memory>

class A
{
  //int &b;
  int b;
  public:
    A(){std::cout << " ctor\n";}
    A(int a):b(a){std::cout << " data: " << a << std::endl;}
    ~A(){std::cout << " dtor\n";}
};


// ===================================
int main()
{

std::cout << " starts ... \n";

std::unique_ptr<int> iptr(std::make_unique<int>(5));

std::cout << " here: " << *iptr << std::endl;

std::unique_ptr<A> aptr(std::make_unique<A>(12));
auto aptr2 = aptr;



std::cout << " ends. \n";
return 0;
}
