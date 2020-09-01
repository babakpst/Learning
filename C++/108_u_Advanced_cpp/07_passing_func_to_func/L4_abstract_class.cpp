
// Babak Poursartip
// 08/31/2020

// passing function to function
// Udemy: Advanced c++

#include <iostream>

using namespace std;

// This is an abstract class bcs it has a pure virtual func (no implementation)
class animal {
private:
public:
  virtual void speak() = 0;
  virtual void run() = 0;
};

class dog : public animal {
private:
public:
  // the virtual is not necessary, just for decoration
  virtual void speak() { cout << " haw\n"; }
};

class german_sh : public dog {
public:
  german_sh() { cout << "german created\n"; }
  virtual void run() { cout << "shepherd runs\n"; }
};

void test(animal &a) { a.run(); }

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  german_sh dog2[5];
  german_sh dog1;
  dog1.speak();
  dog1.run();

  // error bcs animal in pure, and we cannot instantiate an obj from a pure
  // funciton
  // animal anim;

  // but instantiating a pointer is fine
  animal *anim[5];
  anim[0] = &dog1;
  anim[0]->speak();

  test(dog1);

  puts(" \n ends");

  return 0;
}
