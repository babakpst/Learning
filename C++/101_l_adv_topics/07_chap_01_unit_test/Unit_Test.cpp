
// A simple unit test class
// by Bill Weinman <http://bw.org/>

#include "Unit_Test.h"


Unit_Test::Unit_Test( const char * tstr ) {
    init(tstr);
}

void Unit_Test::init( const char * tstr ) {
    _tstr = tstr;
    _pass_count = _fail_count = 0;
}

void Unit_Test::test ( const char * description, const int flag ) {
    const char * pf = nullptr;
    if (flag) {
        pf = __u_pstr;
        ++_pass_count;
    } else {
        pf = __u_fstr;
        ++_fail_count;
    }
    if(!_summary_flag) printf("%s: %s -> %s\n", _tstr, description, pf);
}

void Unit_Test::report() const {
    printf("%s: pass: %ld, fail: %ld\n", _tstr, pass_count(), fail_count());
    fflush(stdout);
}
