
#include <iostream>
#pragma once

class B
{
public:
  B();
  B(int);
  void set(int);
  int get();

private:
  int bvar;
  float bfvar;
};
