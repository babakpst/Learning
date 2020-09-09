
// Babak Poursartip
// 09/08/2020

// auto
// Udemy: Advanced c++

#include <iostream>

using namespace std;

//====================================================
// auto with function: this is great for template function.
// The following is an error in c++11 but ok in c++17
// auto test() { return 10; }

// The following is correct in c++11 and c++17
// -> this is called trailing return type.
auto test() -> int { return 10; }

//====================================================
template <typename T1, typename T2> auto test2(T1 a, T2 b) -> decltype(a + b) {
  return (a + b);
}
//====================================================
int get() { return 100; }

// This is wrong in c++11, but ok in c++17
// auto test3() { return get(); }

// This is ok in c++11, and c++17
auto test4() -> decltype(get()) { return get(); }
decltype(get()) test5() { return get(); }

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  auto value = 7;
  cout << value << endl;
  cout << test() << endl;

  cout << "\n2-----\n";
  cout << test2(1, 1.8) << endl;
  cout << test2(1.8, 1) << endl;
  cout << get() << endl;
  // cout << test3() << endl;
  cout << test4() << endl;
  cout << test5() << endl;

  puts(" \n ends");

  return 0;
}
