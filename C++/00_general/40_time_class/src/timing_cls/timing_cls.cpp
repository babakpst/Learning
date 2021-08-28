
// libraries

// classes
#include "../../include/timing_cls/timing_cls.h"

measure_time_cls::measure_time_cls() {}

std::chrono::steady_clock::time_point measure_time_cls::set_time_fn() {
  return std::chrono::steady_clock::now();
}

void measure_time_cls::elasped_time_fn() { elapsed_time = ends - starts; }
