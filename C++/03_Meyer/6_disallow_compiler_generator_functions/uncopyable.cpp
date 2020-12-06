
/*

Babak Poursartip
12/05/2020

source: Effective C++, Meyer

Topic: item 6 Uncopyable class

// Any class inherited privately from uncopyable, cannot be copied. Because the
compiler generated copy ctor and copy assignment operator will call their base
class counterpart, which has been declared as private.

*/

#include <iostream>

// ============================================
class uncopyable {
private:
  uncopyable(const uncopyable &);
  uncopyable &operator=(const uncopyable &);

public:
  uncopyable(){};
  ~uncopyable(){}; // this does not need to be virtual, bcs uncopyable class has
                   // no data.
};

// Any class inherited privately from uncopyable, cannot be copied
class test : private uncopyable {
private:
  int _ivar = 0;

public:
  // test() { std::cout << " default ctor \n"; }
  // test(int i) : _ivar(i) { std::cout << " ctor \n"; }
};

// ============================================
int main() {

  std::cout << " starts ...\n";
  test obj0;
  test obj1(obj0);

  std::cout << " finished!\n";

  return 0;
}
