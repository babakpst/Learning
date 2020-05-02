// conditional.h by Bill Weinman <http://bw.org/>
// updated 2018-10-10

#ifndef CONDITIONAL_H_
#define CONDITIONAL_H_

#ifdef _NUMBER
#  undef _NUMBER
#endif

#ifdef _FOO
#  define _NUMBER 47
#else
#  define _NUMBER 2
#endif

#endif /* CONDITIONAL_H_ */
