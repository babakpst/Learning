// unique.cpp by Bill Weinman <http://bw.org/>
// 2018-11-10
#include <cstdio>
#include <memory>
#include <utility>
#include "strc.h"

void message(const char * s) {
    printf("\n%s\n", s);
    fflush(stdout);
}

// display object value from unique_ptr
void disp(std::unique_ptr<strc> & o) {
    if(o) puts(o->value());
    else puts("null");
    fflush(stdout);
}

int main() {
    
    message("create unique pointer one");
    std::unique_ptr<strc> a(new strc("one"));
    disp(a);
    
    message("make_unique two");
    auto b = std::make_unique<strc>("two");
    disp(a);
    disp(b);
    
    message("reset a to three");
    a.reset(new strc("three"));
    disp(a);
    disp(b);
    
    message("move b to c");
    auto c = std::move(b);
    disp(a);
    disp(b);
    disp(c);
    
    message("reset a");
    a.reset();
    disp(a);
    disp(b);
    disp(c);
    
    message("release c");
    c.release();
    disp(a);
    disp(b);
    disp(c);
    
    message("end of scope");
    return 0;
}
