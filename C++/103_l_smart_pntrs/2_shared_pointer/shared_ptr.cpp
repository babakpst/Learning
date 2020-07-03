

/*
Babak Poursartip
05/13/2020

linkedin smart pointer

notes:
a shared pointer, as opposed to the unique pointer can be coppied.
use_count to access the number of reference count.

*/

//  shared_ptr.cpp
//  Copyright (c) 2015 Bill Weinman <http://bw.org/>

#include "strc.h"
#include <cstdio>
#include <memory>

void message(const char *s) {
  printf("\n%s\n", s);
  fflush(stdout);
}

// display object value from shared_ptr (with reference count)
void disp(const std::shared_ptr<strc> &o) {
  if (o)
    printf("%s (%ld)\n", o->value(), o.use_count());
  else
    puts("[null]");
  fflush(stdout);
}

int main(int argc, const char **argv) {

  // this is how we create a shared pointer: make_shared, it is recommended to
  // use this one instead of the standard shared_ptr in the next line.
  message("create pointer with new");
  auto a = std::make_shared<strc>("new");

  // you can directly define a shared pointer:
  std::shared_ptr<strc> x(new strc("foo"));
  disp(x);

  disp(a);

  message("reset a to one");
  a.reset(new strc("one"));
  disp(a);

  // making copies of a to check the use_count
  auto copy1 = a;
  auto copy2 = a;
  auto copy3 = a;
  auto copy4 = a;
  disp(a); // reference count is 5

  // destroying copies of a to check the use_count
  copy1.reset();
  copy2.reset();
  copy3.reset();
  copy4.reset();
  disp(a);

  message("b = a");
  auto b = a;
  disp(a);
  disp(b);

  printf("a == b %s\n", a == b ? "true" : "false");     // true
  printf("*a == *b %s\n", *a == *b ? "true" : "false"); // true

  message("reset a to two");
  a.reset(new strc("two"));
  disp(a);
  disp(b);

  printf("a == b %s\n", a == b ? "true" : "false");
  printf("*a == *b %s\n", *a == *b ? "true" : "false");

  message("b.swap(a)");
  b.swap(a); // no constructor/destructor is called.
  disp(a);
  disp(b);

  message("std::swap pointer");
  std::swap(*a, *b); // constructors and destructors are called.
  disp(a);
  disp(b);

  message("std::swap objects");
  std::swap(a, b); // cosntructor/destructors are not called.
  disp(a);
  disp(b);

  message("end of scope");
  return 0;
}