/*
Babak Poursartip
05/03/2020

Linkedin: advanced topics in cpp

chapter 1: this

important note:
The two addresses of the objects are the same. We can refer to this to refer to
the members of the object.

*/

#include <cstdio>

// simplest class
class c1 {

private: // data encapsulation
  int i = 0;

public: // methods
  void setvalue(const int &value);
  int getvalue() const;  // this method member is const saved.
  int getvalue2() const; // this method member is const saved.
};

void c1::setvalue(const int &value) { i = value; }

int c1::getvalue() const {
  printf("getvalue: this is: %p \n", this);
  return i;
} // this method member is const saved.

int c1::getvalue2() const {
  printf("getvalue2\n");
  return this->getvalue();
} // this method member is const saved.

int main() {

  printf(" code starts ... \n");
  const int i = 47;
  c1 o1;
  o1.setvalue(i);
  printf("print the address of o1 %p \n", &o1);
  printf(" value is: %d  \n", o1.getvalue());
  printf(" getvalue2: %d  \n", o1.getvalue2());
  printf(" code ends. \n");

  return 0;
}