
// Babak Poursartip
// 09/08/2020

// buffer
// Udemy: Advanced c++

#include <iostream>

#include "ring.h"
using namespace std;
// Ring buffer/ circular buffer: a buffer that when you reach to the end of the
// buffer, it starts to write or read at the beginning of the buffer.

//====================================================
int main() {
  puts(" starts \n");
  cout << "\n1-----\n";

  ring<string> txtring(3);
  txtring.add("one");
  txtring.add("two");
  txtring.add("three");
  txtring.add("four"); // this will overwrite on "one"
  // txtring.add("five");

  // iterate in the class
  for (int i = 0; i < txtring.size(); ++i) {
    cout << txtring.get(i) << endl;
  }

  cout << "----" << endl;
  for (ring<string>::iterator it = txtring.begin(); it != txtring.end(); it++) {
    cout << *it << endl;
  }

  cout << "----" << endl;
  for (string c : txtring) {
    cout << c << endl;
  }

  /*
  output would be:
  four
  one
  two
  */

  puts(" \n ends");

  return 0;
}
