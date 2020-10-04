
// Babak Poursartip
// 10/04/2020

// header:

/*

- header file is a common file to only store declarations, but not the
implementation. So that any other file that wants to use those functions can
include the header file.

- #pragam once this is guard, instead of #ifndef LOG_H
- #include <> or "" defines the include path/directories. If <>, it searches in
the include path folder. "" relative in the current folder. "" can be used for
everything, instead of <>.

- To separet C and C++ standard libraries: C libraries have .h (<cstdlib.h>) but
C++ don't (<iostream>).



*/

#include "common.h"
#include "log.h"
#include <iostream>

void initLog();
void Log(const char *message);
void Log(const char *message);
void Log(const char *message);
void Log(const char *message);

using std::cout;
using std::endl;

void Log(const char *message) { cout << message << endl; }

int main() {

  initLog();
  // cout << "Hello wolrd.\n";
  Log("Hello wolrd.");
  Log(" Hello yourself");
  return 0;
}