// conditional.cpp by Bill Weinman <http://bw.org/>



#include <sstream>
#define _FOO
#include "preprocessor_condition.h"



int main() {

    printf("CONSTANT:  %d\n", _CONSTANT);

    printf(" here is the def: %d \n", _SPACE);
    return 0;
}
