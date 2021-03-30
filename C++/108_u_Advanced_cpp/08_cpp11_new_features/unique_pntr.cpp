
// Babak Poursartip
// 09/11/2020

// Udemy: Advanced c++
// unique shared pointer
// Unique ptr: It handles the destruction of the pointer, i.e. prevents memory leaks.

// shared ptr: They don't delete the memory associated with the object until all
// the pointers that point to that object go out of scope.

#include <iostream>
#include <memory>

using namespace std;

//====================================================
class Test {
public:
  Test() { cout << "default ctor\n"; }
  void greet() { cout << "Hi\n"; }
  ~Test() { cout << "dctor\n"; }
};

//====================================================
class Temp {
private:
  unique_ptr<Test[]> pTest;

public:
  // can be initialized only in the ctor initialization list.
  Temp() : pTest(new Test[2]) {}
};

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  // we need to do the memory allocation this way.
  unique_ptr<int> pTest(new int);
  *pTest = 12;
  cout << *pTest << endl;

  unique_ptr<Test> pTest2(new Test);
  pTest2->greet();

  unique_ptr<Test[]> pTest3(new Test[2]);
  pTest3[1].greet();

  cout << "\n2-----\n";
  Temp temp;

  cout << "\n3 shared -----\n";
  shared_ptr<Test> pTest4(new Test());
  // the best way to make a shared pointer is to use make_shared_ptr macro

  shared_ptr<Test> pTest6(nullptr);
  {
    shared_ptr<Test> pTest5 = make_shared<Test>();

    pTest6 = pTest5;
  }

  // Test5 won't destroy here bcs pTest6 is pointing to it. They all destroy at
  // the end.

  cout << " finished\n";

  cout << " \n ends\n";

  return 0;
}
