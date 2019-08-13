
/*
Babak Poursartip
Aug 11, 0219
timing class
sources: https://www.youtube.com/watch?v=M13otPgOePs
 */

/*
Introduction to <chrono>

- Clock
std::chrono::system_clock: current time according to system - is not steady
std::chrono::steady_clock: goes at a uniform rate
std::chrono::high_resolution_clock: provides the smallest possible tick period
                                    represented by a ratio (see below).

other clock periods are determined with ratios.

- Duration
std::chrono::duration<>: represent time duration (requires a number + a unit)
std::duration<int, ratio<1,1>> // number of seconds stored in int
std::duration<double, ratio<60,1>> // number of minutes stored in double

predefined durations:
     nanoseconds, microseconds, miliseconds, seconds, minutes, hours

Each of the clock has its own predefined duration
system_clock::duration -- duration<T, system_clock::period>

- timings
std::chrono::time_point<>: represents a time point
  00:00 Jan 1, 1970 (Coordinated Universal Time) -- epoch of a clock
std::time_clock<system_clock, milliseconds> according to the epoch, the elapsed
time since epoch in milliseconds.

std::system_clock::time_point --time_point<system_clock, system_clock::duration>
std::steady_clock::time_point --time_point<steady_clock, system_clock::duration>


*/

// libraries
#include <chrono>
#include <ctime>
#include <iostream>

// classes

int main(int argc, char *argv[]) {

  // std::time_t current_time = std::chrono::system_clock::to_time_t(end);
  std::time_t current_time = std::time(NULL);
  std::string CurrentTime = std::ctime(&current_time);
  std::cout << "\n This is the timing code! \n  Time now is: " << CurrentTime
            << "\n\n";

  // ratio-----------------------------------------------------------------
  std::ratio<1, 10> r; // 1/10

  std::cout << " ratio: " << r.num << "/" << r.den << "\n";

  // ratio of the system_clock
  std::cout << " the ratio of system_clock in chrono: "
            << std::chrono::system_clock::period::num << "/"
            << std::chrono::system_clock::period::den << "\n";

  // convert periods ----------------------------------------------------------
  std::chrono::microseconds mi(2700); // 2700 microseconds
  mi.count();                         // returns the value of var-here 2700
  std::chrono::nanoseconds na = mi;   // 2700000 nanoseconds
  na.count();                         // returns the value of var-here 27000000
  // information lost: converting from low period to high period
  // std::chrono::milliseconds mill = mi; // 2.7 miliseconds  WRONG

  // from low to high periods, the value truncates
  std::chrono::milliseconds mill =
      std::chrono::duration_cast<std::chrono::milliseconds>(
          mi); // 2 milliseconds

  mi = mill + mi; // 2000 + 2700 = 4700

  std::cout << " micro: " << mi.count() << " nano: " << na.count()
            << " mill:" << mill.count() << "\n";

  // timings ------------------------------------------------------------------
  // current time of the system
  std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
  std::cout << " current time (system_clock) : "
            << tp.time_since_epoch().count() << "\n";

  std::chrono::steady_clock::time_point start =
      std::chrono::steady_clock::now();

  std::cout << " just to waist some time.\n";

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  std::chrono::steady_clock::duration elapsed = end - start;

  if (elapsed == std::chrono::steady_clock::duration::zero()) {
    std::cout << " no time elapsed. \n";
  } else {
    std::cout
        << " elapsed time: " << elapsed.count() << " and in microsecond: "
        << std::chrono::duration_cast<std::chrono::microseconds>(elapsed)
               .count()
        << " in nanoseconds: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count()
        << " in seconds: "
        << std::chrono::duration_cast<std::chrono::seconds>(elapsed).count()
        << "\n";
  }

  current_time = std::time(NULL);

  std::cout << " \n End of the code. Success! \n Time now is: "
            << std::ctime(&current_time) << "\n\n";

  return 0;
}