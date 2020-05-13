//  shared_ptr.cpp
//  Copyright (c) 2015 Bill Weinman <http://bw.org/>

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

int main(int argc, const char ** argv) {

    message("create pointer with new");
    auto a = std::make_shared<strc>("new");

    message("reset a to one");
    a.reset(new strc("one"));
    disp(a);

    message("b = a");
    auto b = a;
    disp(a);
    disp(b);
    
    printf("a == b %s\n", a == b ? "true" : "false");
    printf("*a == *b %s\n", *a == *b ? "true" : "false");
    
    message("reset a to two");
    a.reset(new strc("two"));
    disp(a);
    disp(b);

    printf("a == b %s\n", a == b ? "true" : "false");
    printf("*a == *b %s\n", *a == *b ? "true" : "false");

    message("b.swap(a)");
    b.swap(a);
    disp(a);
    disp(b);
    
    message("std::swap");
    std::swap(*a, *b);
    disp(a);
    disp(b);
    
    message("end of scope");
    return 0;

}
