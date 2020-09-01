

// Babak Poursartip
// 08/31/2020

// passing function to function: functor
// Udemy: Advanced c++

#include <iostream>

using namespace std;

struct test {
  virtual bool operator()(string &text) = 0;
  virtual ~test() {}
};

struct match_test : public test {
  // overloading ()
  virtual bool operator()(string &text) { return text == "lion"; }
};

void checK(string text, test &test) {
  if (test(text)) {
    cout << "text matched\n";
  } else
    cout << "text did not matched\n";
}

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  match_test pred;
  string value = "lion";

  cout << pred(value) << endl;

  match_test m;
  checK("lion", m);

  puts(" \n ends");

  return 0;
}
