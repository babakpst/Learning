
// numword.h by Bill Weinman <http://bw.org/>

// Babak

#include <sstream>
#include <cstdint>
#include <stdint.h>
#include <iostream>
#include <limits>

#include "num_to_word.h"

int main(){

puts(" code starts .... ");
num_to_word nw;

uint64_t n;


n = 8119456789;
nw.words(n);


puts(" End. ");
return 0;
}
