//  unique_ptr.cpp
//  Copyright (c) 2015 Bill Weinman <http://bw.org/>

#include <cstdio>
#include <memory>
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

namespace notstd {
    template <typename T, typename P>
    std::unique_ptr<T> make_unique(P initializer) {
        return std::unique_ptr<T>(new T(initializer));
    }
}

int main(int argc, const char ** argv) {

    message("create unique pointer one");
    std::unique_ptr<strc> a(new strc("one"));
    disp(a);

    message("make_unique two");
    auto b = notstd::make_unique<strc>("two");
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

    message("reset c");
    c.reset();
    disp(a);
    disp(b);
    disp(c);
    
    message("end of scope");
    return 0;
}
