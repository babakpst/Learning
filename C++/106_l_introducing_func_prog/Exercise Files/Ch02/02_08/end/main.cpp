// 02_07 Lambdas
#include <iostream>

using namespace std;

auto incrementer = []() {
  auto increment = 0;
  return [increment]() mutable {
    return increment++;
  };
};

int main() {

 auto myInc = incrementer();
 cout << "myInc = " << myInc() << endl;
 cout << "myInc = " << myInc() << endl;
 cout << "myInc = " << myInc() << endl;
 cout << "myInc = " << myInc() << endl;

  return 0;
}