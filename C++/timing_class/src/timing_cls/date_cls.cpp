
// libraries

// classes
#include "../../include/timing_cls/date_cls.h"

date_cls::date_cls() { std::cout << " date class \n"; }

std::string date_cls::get_date() {
  std::time_t temp = std::time(NULL);
  return std::ctime(&temp);
}
