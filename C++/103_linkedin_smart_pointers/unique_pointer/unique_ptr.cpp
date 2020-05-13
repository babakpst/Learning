
/*
Babak Poursartip
05/07/2020

linkedin smart pointer

notes:
unique pointer is defined in include <memory>
A unique poniter is a typeo of pointer that cannot be copied. There is only one
copy of the pointer. You cannot inadvertently make a copy of this.

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
namespace notstd {
template <typename T, typename P>
std::unique_ptr<T> make_unique(P initializer) {
  return std::unique_ptr<T>(new T(initializer));
}
} // namespace notstd

//========================================
int main(int argc, const char **argv) {

  message("creatinga a unique pointer:");
  std::unique_ptr<strc> a(new strc("one"));
  disp(a);

  message("make_unique two");
  auto b = notstd::make_unique<strc>("two");
  disp(a);
  disp(b);

  return 0;
}
