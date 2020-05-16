
/*
Babak Poursartip
05/07/2020

linkedin smart pointer

notes:
- unique pointer is defined in include <memory>
- A unique poniter is a type of pointer that cannot be copied. There is only one
copy of the pointer. You cannot inadvertently make a copy of this. This way, you
can avoid memory leaks.

- you cannot pass a unique pointer to a function by value, because that means we
need to make a copy of the pointer, which is not possible for the unique
pointer. Instead, we need to pass the unique pointer to the function by value.

*/

#include "strc.h"
#include <cstdio>
#include <memory>

//========================================
void message(const char *s) {
  printf("\n%s\n", s);
  fflush(stdout);
}

//========================================
void disp(std::unique_ptr<strc> &o) {
  if (o)
    puts(o->value());
  else
    puts("null");
  fflush(stdout);
}

//========================================
// this the make unique pointer in c++14, but is supported anymore.
namespace notstd {
template <typename T, typename P>
std::unique_ptr<T> make_unique(P initializer) {
  return std::unique_ptr<T>(new T(initializer));
}
} // namespace notstd

// error bcs unique pointer cannot be copied.
// void f(std::unique_ptr<strc> p) {
void f(std::unique_ptr<strc> &p) {
  message("inside the function.");
  disp(p);
}

//========================================
int main(int argc, const char **argv) {

  message("creatinga a unique pointer:");
  std::unique_ptr<strc> a(new strc("one"));
  disp(a);
  message("end here");

  // passing a unique pointer to a function
  f(a);

  message("make_unique two");
  auto b = notstd::make_unique<strc>("two");
  disp(a);
  disp(b);
  message("end here");

  message("reset a to three");
  // reset: resets a unique pointer (this is an intrinsic attribute within the
  // unique pointer).
  // The other option instead of reset, is release, but release does not call
  // the destructor. It is recommended to use reset.
  a.reset(new strc("three"));
  disp(a);
  disp(b);
  message("end here");

  message("move b to c");

  // b is a unique pointer and cannot be copied.
  // auto c= b; // error.
  auto c = std::move(b);
  disp(a);
  disp(b);
  disp(c);
  message("end here");

  message("reset a");
  a.reset();
  disp(a);
  disp(b);
  disp(c);

  message("reset c");
  c.reset();
  disp(a);
  disp(b);
  disp(c);

  return 0;
}
