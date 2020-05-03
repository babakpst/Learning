// shared.cpp by Bill Weinman <http://bw.org/>
// 2018-11-10

#include <cstdio>
#include <memory>
#include "strc.h"

void message(const char * s) {
    printf("\n%s\n", s);
    fflush(stdout);
}

// display object value from shared_ptr (with reference count)
void disp(const std::shared_ptr<strc> & o) {
    if(o) printf("%s (%ld)\n", o->value(), o.use_count());
    else puts("[null]");
    fflush(stdout);
}

int main() {
    
    message("create pointer with one");
    auto a = std::make_shared<strc>("one");
    disp(a);
    
    std::shared_ptr<strc> b(new strc("two"));
    disp(b);
    
    message("reset a to three");
    a.reset(new strc("three"));
    disp(a);
    
    message("b = a");
    auto c = a;
    disp(a);
    disp(b);
    disp(c);
    
    message("end of scope");
    return 0;
    
}
