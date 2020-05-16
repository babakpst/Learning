
/*
Babak Poursartip
05/02/2020

Linkedin: advanced topics in cpp

chapter 1: constructors and destructors
important notes:

implicit op
1- default constructor
2- copy constructor
3- copy operator assignment
4- destructor

*/

#include <cstdio>

class c1 {
private:
  int i = 0;

public:
  void setvalue(const int &value) { i = value; };
  int getvalue() const { return i; }
};

int main() {

  printf(" program starts ... \n\n");
  const int i = 64;
  c1 o1;
  o1.setvalue(i);
  printf("i is: %d  \n", o1.getvalue());

  c1 o2 = o1; // copy constrcutor
  printf("i is: %d  \n", o2.getvalue());

  o1.setvalue(472);
  o2 = o1; // copy operator assignment
  printf("i is: %d  \n", o2.getvalue());

  printf(" \n program ends! \n");

  return 0;
}
