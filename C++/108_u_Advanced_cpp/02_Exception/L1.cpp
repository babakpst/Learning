
// Babak Poursartip
// 08/27/2020

// Exception
// Udemy: Advanced c++

// Use Exceptions for things that your program cannot recover from
// After the first throw, nothing will be executed

#include <iostream>
// =========================================
void mightGoWrong() {
  // bool error1 = true;
  bool error1 = false;
  bool error2 = true;
  if (error1)
    // throw 8;
    throw " Sth is wrong in the func."; // this is of type const char

  if (error2)
    throw std::string(" Sth else went wrong"); // this is string and not char
}

void useMightGoWrong() { mightGoWrong(); }
// =========================================

int main() {
  puts(" starts \n");

  // =========================================
  try {
    // mightGoWrong();
    useMightGoWrong();
  } catch (int e) {
    printf(" Error code: %d \n", e); // by value
  } catch (const char *e) {          // by pointer
    printf(" Error code: %s \n", e);
  } catch (std::string &e) { // by reference - recommended
    std::cout << " String error: " << e << std::endl;
  }

  puts(" code is still running");
  puts(" \n ends");

  return 0;
}
