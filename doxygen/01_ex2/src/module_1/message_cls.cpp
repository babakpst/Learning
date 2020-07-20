
/** @file message_cls.cpp
@author Poursartip:Babak:PhD:Algo
@version Revision 1.1
@brief A class for all print functions.
@details
pt: prints a text message
pi: prints an int number
pi: prints a text and an int number
chk: checkpoint printer
@date Monday, July 20, 2020
*/

#include "../../include/module_1/message_cls.h"

void message_cls::pt(const char *text) const { printf(" %s\n", text); }
void message_cls::pi(const int num) const { printf(" %d \n", num); }
void message_cls::pti(const char *text, const int num) const {
  printf(" %s %d \n", text, num);
}
void message_cls::ptf(const char *text, const float num) const {
  printf(" %s %f \n", text, num);
}
void message_cls::chk(const int num) const { printf(" checkpoint: %d\n", num); }