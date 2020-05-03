// weak.cpp by Bill Weinman <http://bw.org/>
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

// display object value from weak_ptr (with reference count)
void disp(const std::weak_ptr<strc> & o) {
    // must get a lock to use a weak_ptr
    size_t count = o.use_count(); // weak pointer count
    if(auto sp = o.lock()) printf("%s (w:%ld s:%ld)\n", sp->value(), count, sp.use_count());
    else puts("[null]");
    fflush(stdout);
}

int main() {
    
    message("create shared_ptr");
    auto a = std::make_shared<strc>("thing");
    
    message("make several copies");
    auto c1 = a;
    auto c2 = a;
    auto c3 = a;
    auto c4 = a;
    auto c5 = a;
    
    message("reference count is now 6");
    disp(a);
    
    message("create weak_ptr");
    auto w1 = std::weak_ptr<strc>(a);
    disp(w1);
    
    message("destroy copies");
    c1.reset();
    c2.reset();
    c3.reset();
    c4.reset();
    c5.reset();
    
    message("reference count should be 1");
    disp(a);
    
    message("check weak pointer");
    disp(w1);
    
    message("destroy a");
    a.reset();
    
    message("check weak pointer");
    disp(w1);
    
    message("end of scope");
    return 0;
    
}
