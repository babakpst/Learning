
#include <stdint.h>
#include <sstream>
#include <inttypes.h>
#include <math.h>


#ifndef NUM_TO_WORD_H
#define NUM_TO_WORD_H

class num_to_word{
private:
 unsigned nDigits=0;
 unsigned nGroups=0;
public:
num_to_word();
unsigned GetNumberOfDigits (unsigned i);
void words(uint64_t n);

const char* One_digit(int n);
const char* two_digit(int n);
const char* p_digit(int n);

};

#endif
