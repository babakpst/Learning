
/** @file message_cls.h
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

// libraries
#include <stdio.h>

// classes

// GUARD
#ifndef MESSAGE_CLS_H
#define MESSAGE_CLS_H

class message_cls {
  char *text;

public:
  void pt(const char *text) const;
  /**<
  prints a text.

  @return void

  @param text a string to be printed.

  @pre
  -# text contains a string to be printed.

  @post
  -# no output.
  */

  void pi(const int num) const;
  /**<
  prints an integer.

  @return void

  @param num an int variable.

  @pre
  -# int number to be printed.

  @post
  -# no output.
  */

  void pti(const char *text, const int num) const;
  /**<
  prints a string followed by an integer .

  @return void

  @param
  text a char variable.
  num an int variable.

  @pre
  -# int number to be printed.

  @post
  -# no output.
  */

  void ptf(const char *text, const float num) const;
  /**<
  prints a string followed by a float.

  @return void

  @param
  text a char variable.
  num a float variable.

  @pre
  -# float number to be printed.

  @post
  -# no output.
  */

  void chk(const int) const;
  /**<
  prints the checkpoint location: checkpoint ---.

  @return void

  @param
  num checkpoint.

  @pre
  -# int checkpoint be printed.

  @post
  -# no output.
  */
};

#endif // !MESSAGE_CLS_H