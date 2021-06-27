
/*
Babak Poursartip
05/02/2020

Linkedin: advanced topics in cpp

chapter 1: Namespaces

important note:
1- namespace is great for name managing, in case we have several classes and
there is a possibility for name inclusion.

Here string is defined in the BABAk namespace and is different from the string
in the std namespace.

"::" this is scope resolusion operator.


*/

#include <cstdio>
#include <string>

namespace babak {
const std::string prefix = "(babak::string)";

class string {
  std::string _s = "";
  string(); // default constructor is in the private section, which means it
            // will not be called.

public:
  string(const std::string &s) : _s(prefix + s){};
  const char *c_str() const { return _s.c_str(); }
  operator std::string &() { return _s; }
  operator const char *() const { return _s.c_str(); }
};

}; // namespace babak

int main() {
  const std::string s1("This is a string.");
  std::puts(s1.c_str());

  const babak::string s2(s1);
  std::puts(s2);
  return 0;
}