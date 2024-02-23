
#include <iostream>
#include <vector>

class test
{
 public:
  test(int a, double b) : a{a}, b{b} {}  // no default ctor
 private:
  int a;
  double b;
};

int main()
{
  std::cout << " starts \n";

  // test obj0; // error no matching function, there is no default ctor

  test obj1(2, 3);

  // test *ptr = new test[10]; // cannot instantiate an array if there is no default
  // std::vector<test> vec(10); // cannot instantiate an array if there is no default
  std::vector<test> myVec(10, test(2, 3.0));  // ok.

  // option one to bypass
  test *arr[10];  // this is the array of pointers, and is fine, no ctor is called.
  for (int i = 0; i < 10; ++i) arr[i] = new test(2, 3.0);

  // option two to bypass
  std::vector<test> yourVec;  // ok, this is just a definition.

  for (int i = 0; i < 10; ++i) yourVec.push_back(test(2, 3.0));

  std::cout << " done \n";

  return 0;
}
