
// Babak Poursartip
// 08/14/2020

// Credit goes to linkedin course Design pattern creational

#include <iostream>
// =====================================================
class leader {
private:
  static leader *_instance;
  leader() { puts(" The new leader elected."); };

public:
  static leader *getInstance() {
    if (_instance == NULL) {
      _instance = new leader;
    }
    return _instance;
  }
  void giveSpeach() { puts(" Address the public"); }
};

leader *leader::_instance = NULL;

// =====================================================
int main() {
  puts(" Code starts ...");

  // leader *elected = new leader();
  // error: the constructor is private and is not accessible outside the class.

  leader::getInstance()->giveSpeach();
  leader *elected = leader::getInstance();
  elected->giveSpeach();

  puts(" Successfully ends.");
  return 0;
}
