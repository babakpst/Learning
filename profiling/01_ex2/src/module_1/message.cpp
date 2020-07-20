
#include "../../include/module_1/message.h"

void message::pt(const char *text) const { printf(" %s\n", text); }
void message::pi(const int num) const { printf(" %d \n", num); }
void message::pti(const char *text, const int num) const {
  printf(" %s %d \n", text, num);
}
void message::chk(const int num) const { printf(" checkpoint: %d\n", num); }