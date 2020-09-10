
// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// delegation constructor: calling a ctor from another

// In c++98, we cannot call a ctor of a class from another ctor, but it is
// possible to do that in c++11.

#include <iostream>

using namespace std;
//====================================================
class parent {
  int dogs;
  string text;

public:
  parent() : parent("shiva") {
    dogs = 5;
    cout << "No parameter parent ctor\n";
  }

  parent(string text) {
    dogs = 5;
    this->text = text;
    cout << "string parent ctor\n";
  }
};

class child : public parent {
public:
  child() : parent("bob") {}
};

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";
  parent pr;
  child chd;

  cout << " \n ends\n";

  return 0;
}
