/** @file main.cpp
@author Poursartip:Babak:PhD:Algo
@version Revision 1.1
@brief Illustrates doxygen-style comments for documenting a C++
program file and the functions in that file.
@details If you want to add any further detailed description of
what is in the file, then place it here (after the first statement)
and it will appear in the detailed description section of the HTML
output description for the file.
@date Monday, July 20, 2020
*/

/**
@mainpage
This short program contains some sample code illustrating
how the doxygen comments must appear
- for documenting a file, and in particular
- for documenting functions
.
when we intend to use the doxygen tool for preparing HTML
documentation of our code. Note that this file is intended
<em>only</em> to illustrate a particular set of <b>commenting
conventions</b> and how they show up when implemented with
doxygen. Your actual requirements may not be the same as
shown here. Im particular you may need less (or more) than
is shown here.

Pay careful attention, in the source code,\n to the distinction
between the special doxygen comments,<br>which produce output
here, and regular C++ comments which are ignored by doxygen,
and look at the source code to see how line breaks in this
paragraph are produced.
*/

// libraries
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// classes
#include "../include/module_1/division_cls.h"
#include "../include/module_1/message_cls.h"
#include "../include/module_1/mult_cls.h"

/**<
Compute and return the number of digits in a positive integer.
The style used for the pre/post coditions of this function is
purposely different from that for the void function given above,
just so you can see the differnce in the HTML output.
@return The number of digits in n.
@param n An integer, the number of whose digits is desired.
@pre n contains a positive integer.
This is some other precondition, and note that it does not
start on a new line.
@post
The number of digits in n has been returned.
\n This is some other post condition, and note that it does start
on a new line.
*/
int main() {

  message_cls m;
  m.pt(" Code starts here ... ");
  int ioutput;
  float foutput;
  mult_cls mult(5);
  ioutput = mult.doit(10, 5);
  m.pti(" int by int ", ioutput);

  foutput = mult.doit(10.1f, 5.2f);
  m.ptf(" float by float ", foutput);

  std::vector<int> vec1, vec2;
  vec1.resize(10);
  vec2.resize(10);

  std::vector<int>::iterator it2 = vec2.begin();
  for (std::vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end();
       ++it1) {
    *it1 = 3;
    *it2 = 4;
    ++it2;
  }
  ioutput = mult.vecXvec(vec1, vec2);
  m.pti(" vec by vec ", ioutput);

  m.pt(" Terminates successfully!");
  return 0;
}
