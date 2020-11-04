
#include <iostream>
using namespace std;

//=============
class ExBase {
private:
  static int stat;

public:
  static int GetStat() { return stat; }
};

int ExBase::stat = 25;

//=============
class ExDer1 : public ExBase {
public:
  // friend int Der1Fn() { return ExBase::stat; }
  friend int Der1Fn() { return GetStat(); }
};

//=============
class ExDer2 : public ExBase {};

//=============
class ExDer : public ExDer1, public ExDer2 {};

int main() {

  ExDer d;
  // cout << d.Der1Fn() << endl;
  cout << d.GetStat() << endl;
  cout << ExDer1::GetStat() << endl;
}