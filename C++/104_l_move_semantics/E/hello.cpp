// hello.cpp by Bill Weinman <http://bw.org/>

#include <cstdio>

void message(const char * s) {
    puts(s);
    fflush(stdout);
}

int main( int argc, char ** argv ) {
    message("Hello, World!");
    return 0;
}
