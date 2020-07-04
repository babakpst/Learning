// conditional.h by Bill Weinman <http://bw.org/>


// All the preprocessor start with #, and # should be at the begining of the line
// it can be white space btw # and the command

#   define _SPACE 12

#ifndef CONDITIONS_H_
#define CONDITIONS_H_

#ifdef _CONSTANT
#  undef _CONSTANT
#endif

#ifdef _FOO
#  define _CONSTANT 47
#else
#  define _CONSTANT 2
#endif

#endif /* CONDITIONS_H_ */
