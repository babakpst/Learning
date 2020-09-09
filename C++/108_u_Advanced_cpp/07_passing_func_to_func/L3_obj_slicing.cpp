
// Babak Poursartip
// 08/31/2020

// passing function to function
// Udemy: Advanced c++

#include <iostream>

using namespace std;

//====================================================
class parent {
private:
  int one;

public:
  int three;
  parent() : one(0), three(0){};
  // copy constructor
  parent(const parent &other) : one(0) {
    one = other.one;
    cout << " copy ctor parent \n";
  }

  // void print() { cout << "parent\n"; }
  virtual void print() { cout << "parent\n"; }
  virtual ~parent(){};
};

//====================================================
class child : public parent {
private:
  int two;

public:
  child() : two(0), parent() {}
  void print() { cout << "child\n"; }
};

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  child c1;
  parent &p1 = c1;
  p1.print(); // prints parent w/o virtual, and prints child with virtual

  // Calls the copy ctor of the parent and not the child. Thus, we only have a
  // copy of parent variables of the child class, and not the variables of the
  // child class.
  parent p2 = child(); // implicit copy constructor-
  p2.print();          // prints parent

  parent *p3 = new child; //
  p3->print();            // prints child

  puts(" \n ends");

  return 0;
}
