
// Linkein:  Advanced topics in c++
// Babak Poursartip
// 04/26/2020

#include <cstdio>

#ifndef C1_CLS
#define C1_CLS

// simplest class
class c1_cls {

private: // data encapsulation
  int i = 0;

public: // methods
  void setvalue(const int &);
  int getvalue() const; // this method member is const saved.
};

#endif
