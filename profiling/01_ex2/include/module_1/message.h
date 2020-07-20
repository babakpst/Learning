
/*
===============================================================================
Developer: Babak Poursartip
Data:      05/23/2020
class:     all messaging functions
===============================================================================
*/

#include <stdio.h>

#define DEB 0 // 0 false 1 true

#ifndef MESSAGE_H
#define MESSAGE_H

class message {
  char *text;

public:
  void pt(const char *text) const;
  void pi(const int num) const;
  void pti(const char *text, const int num) const;
  void chk(const int) const;
};

#endif // !MESSAGE_H