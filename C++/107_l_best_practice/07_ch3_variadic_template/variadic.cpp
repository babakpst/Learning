#include <iostream>
#include <string>

// base case
template<typename T>
T rcatenate(T v) {
  return v;
}

template<typename T, typename... Args>
T rcatenate(T first, Args... args) {
  return rcatenate(args...) + " " + first;
}

int main() {
  std::string s1 = "biz", s2 = "fox", s3 = "wiz";
  std::string cc = rcatenate(s1, s2, s3);
  std::cout << "reverse concatenated = " << cc << std::endl;
  return 0;
}
