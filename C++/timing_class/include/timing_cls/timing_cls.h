// libraries
#include <chrono>
#include <iostream>

// classes

#ifndef TIMING_H
#define TIMING_H

class measure_time_cls {
  // objects
private:
public:
  std::chrono::steady_clock::time_point starts;
  std::chrono::steady_clock::time_point ends;
  std::chrono::steady_clock::duration elapsed_time;

  // methods
private:
public:
  measure_time_cls();

  void set_time_fn(std::chrono::steady_clock::time_point input_time);

  void elasped_time_fn();
};

#endif // !TIMING_H