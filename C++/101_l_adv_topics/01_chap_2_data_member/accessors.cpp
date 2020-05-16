

/*
Babak Poursartip
05/02/2020

Linkedin: advanced topics in cpp

chapter 1: accessors

*/

#include <cstdio>
// class by default the variables are private.
// use struct when we only have data members.
class A {

  int ia = 0;
  const char *sb = "";
  int ic = 0;

public:
  A(const int a, const char *b, const int c) : ia(a), sb(b), ic(c){};
  void seta(const int a) { ia = a; }
  void setb(const char *b) { sb = b; }
  void setc(const int c) { ic = c; }
  int geta() const { return ia; }
  const char *getb() const { return sb; }
  int getc() const { return ic; }
};

int main() {

  printf(" code starts..\n");

  A a(1, "Babak", 4);
  printf(" ia: %d, sb: %s, ic: %d \n", a.geta(), a.getb(), a.getc());

  printf(" end of the code.\n");

  return 0;
}
