// working.cpp by Bill Weinman <http://bw.org/>
// 2018-10-12

#include <cstdio>
#include "BWString.h"

void message(const char * s) {
    puts(s);
    fflush(stdout);
}

int main() {
    BWString hello = "Hello, World!";
    message(hello);
    return 0;
}
