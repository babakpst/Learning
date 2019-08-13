
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

// classes
#include "../include/timing_cls/date_cls.h"
#include "../include/timing_cls/timing_cls.h"

int main(int argc, char *argv[]) {

  date_cls getDates;
  getDates.exe_starts = std::time(NULL);

  std::string CurrentTime = getDates.get_date(getDates.exe_starts);

  std::cout << "\n This is the timing code! \n  Time now is: " << CurrentTime
            << "\n\n";

  // timings ------------------------------------------------------------------
  // current time of the system
  measure_time_cls input_time;
  input_time.set_time_fn(input_time.starts);

  std::cout << " just to waist some time.\n";

  input_time.set_time_fn(input_time.ends);

  input_time.elasped_time_fn();

  std::cout << " elapsed time: " << input_time.elapsed_time.count()
            << " and in microsecond: "
            << std::chrono::duration_cast<std::chrono::microseconds>(
                   input_time.elapsed_time)
                   .count()
            << " in nanoseconds: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(
                   input_time.elapsed_time)
                   .count()
            << " in seconds: "
            << std::chrono::duration_cast<std::chrono::seconds>(
                   input_time.elapsed_time)
                   .count()
            << "\n";

  // -----------------------------------------------------------------------------

  getDates.exe_ends = std::time(NULL);

  CurrentTime = getDates.get_date(getDates.exe_ends);

  std::cout << " \n End of the code. Success! \n Time now is: " << CurrentTime
            << "\n\n";

  return 0;
}