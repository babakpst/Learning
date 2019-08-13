
// libraries

// classes
#include "../../include/timing_cls/timing_cls.h"

measure_time_cls::measure_time_cls() {}

void measure_time_cls::set_time_fn(
    std::chrono::steady_clock::time_point input_time) {
  input_time = std::chrono::steady_clock::now();
}

void measure_time_cls::elasped_time_fn() { elapsed_time = ends - starts; }
