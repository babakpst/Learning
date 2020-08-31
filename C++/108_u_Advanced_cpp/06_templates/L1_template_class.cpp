
// Babak Poursartip
// 08/30/2020

// Operator overloading:
// Udemy: Advanced c++

#include <iostream>

using namespace std;

template <class T, class K> class person {
private:
  T obj;

public:
  person(T obj) { this->obj = obj; }
  void print() { cout << obj << endl; }
};

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  person<string> per1("Babak");
  per1.print();

  puts(" \n ends");

  return 0;
}
