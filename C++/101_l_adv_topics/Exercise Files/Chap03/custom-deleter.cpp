// custom-deleter.cpp by Bill Weinman <http://bw.org/>
// 2018-10-09

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

void deleter(const strc * o) {
    printf("deleter: ");
    if(o) {
        printf("%s\n", o->value());
        delete o;
    } else {
        printf("[null]\n");
    }
    fflush(stdout);
}

int main() {
    
    message("create shared_ptr");
    std::shared_ptr<strc> a(new strc("thing"), deleter);
    disp(a);
    
    a.reset();
    disp(a);
    
    message("end of scope");
    return 0;
    
}
