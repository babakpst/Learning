// libraries
#include <ctime>
#include <iostream>

// classes

#ifndef DATE_H
#define DATE_H

class date_cls {

  // objects
private:
public:
  std::time_t exe_starts; // the date the execution starts
  std::time_t exe_ends;   // the date the execution ends

  // methods
private:
public:
  date_cls();
  std::string get_date(std::time_t &date); // returning the date
};

#endif // ! DATE_H