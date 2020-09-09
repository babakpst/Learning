
// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// object initialization, default, and delete.

#include <iostream>

using namespace std;

//====================================================
class test {
private:
  int id{3}; // class member initialization.
  string name{"bob"};

public:
  // Since we defined a ctor with some variables, the compiler won't generate
  // the default ctor, thus, we cannot use the default ctor, to generate new
  // objects using the default variables in the class

  // The next line asks the compiler to generate the default ctor.
  test() = default;

  // ===============================
  // copy ctor with the default version.
  test(const test &lhs) = default;
  // This generates the default assignment operator.
  test &operator=(const test &lhs) = default;

  // ===============================
  // to make an obj not copyable, we can delete copy and assignment ctor
  // test(const test &lhs) = delete;
  // This generates the default assignment operator.
  // test &operator=(const test &lhs) = delete;

  test(int id) : id{id} {} // only id has been redefined.
  void print() { cout << id << ": " << name << endl; }
};

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  test tst;
  tst.print();

  test tst1(77);
  tst1.print();
  test tst2 = tst1; // copy ctor (initializatino)
  test tst3(tst1);  // copy ctor (initializatino)
  test tst4;
  tst4 = tst1; // assignment ctor

  cout << " \n ends";

  return 0;
}
