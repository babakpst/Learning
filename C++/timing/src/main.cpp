
/*
Babak Poursartip
Aug 11, 0219
timing class
sources: https://www.youtube.com/watch?v=M13otPgOePs
 */

/*
Introduction to <chrono>

std::chrono::system_clock: current time according to system - is not steady
std::chrono::steady_clock: goes at a uniform rate
std::chrono::high_resolution_clock: provides the smallest possible tick period
                                    represented by a ratio (see below).

*/

// libraries
#include "chrono"
#include "iostream"

// classes

int main(int argc, char *argv[]) {
  std::cout << "\n This is the timing code ! \n \n";

  // ratio
  std::ratio<1, 10> r; // 1/10
  std::cout << " ratio: " << r.num << "/" << r.den << "\n";

  std::cout << "\n End of the code. Success! \n";
  return 0;
}