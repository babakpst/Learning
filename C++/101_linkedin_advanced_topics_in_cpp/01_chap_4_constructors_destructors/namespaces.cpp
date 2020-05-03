
/*
Babak Poursartip
05/02/2020

Linkedin: advanced topics in cpp

chapter 1: Namespaces

important note:


*/

#include <cstdio>
#include <string>

namespace babak {
const std::string prefix = "(babak::string)";

class string {
  std::string _s = "";
  string();

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