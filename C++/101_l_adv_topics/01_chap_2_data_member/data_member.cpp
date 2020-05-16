
/*

Babak Poursartip
Linkedin Advanced topics in cpp

05/01/2020

*/

#include <cstdio>

struct A {

  int ia;
  const char *sb = "";
  int ic;
};

int main() {

  A a;
  a.ia = 1;
  a.sb = "two";
  printf(" char: %s \n", a.sb);
  a.sb = "three";
  printf(" char: %s \n", a.sb);
  a.ic = 3;
  printf(" ia: %d, sb: %s, ic: %d \n", a.ia, a.sb, a.ic);
}
