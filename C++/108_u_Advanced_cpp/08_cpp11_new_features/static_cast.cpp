
// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// static cast: This is compile time command. No run time checking.

#include <iostream>

class parent {
public:
  void speak() { std::cout << "parent\n"; }
};
class brother : public parent {};
class sister : public parent {};

using namespace std;

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  float val = 3.2435;
  cout << " float: " << val << endl;
  cout << " cast as int: " << int(val) << endl;
  cout << " static cast as int: " << static_cast<int>(val) << endl;

  cout << "\n2-----\n";
  parent pr;
  brother br;

  parent *pp = &br;
  // borther *pb = &pr; // this is error
  brother *pb = static_cast<brother *>(&pr); // this is not safe

  parent *ppb = &br;
  cout << ppb << endl;

  brother *pbb = &br;

  // error: even though both are pointing to brother, but since the types are
  // different, they are not working. To fix it, we need to use static_cast.
  // brother *pbb2 = ppb;
  brother *pbb2 = static_cast<brother *>(ppb); // fine
  cout << pbb2 << endl;

  // rvalue referenced to parent obj
  parent &&p = parent();

  // parent &&p = pr; error lvalue cannot be set equal to rvalue! but next fine
  parent &&p2 = static_cast<parent &&>(pr);
  p2.speak();

  cout << " \n ends\n";

  return 0;
}
