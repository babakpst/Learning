// BWUTest.cpp
// A simple unit test class
// by Bill Weinman <http://bw.org/>
// as of 2018-10-12

#include "BWUTest.h"

BWUTest::BWUTest( const char * tstr ) {
    init(tstr);
}

void BWUTest::init( const char * tstr ) {
    _tstr = tstr;
    _pass_count = _fail_count = 0;
}

void BWUTest::test ( const char * description, const int flag ) {
    const char * pf = nullptr;
    if (flag) {
        pf = __bwu_pstr;
        ++_pass_count;
    } else {
        pf = __bwu_fstr;
        ++_fail_count;
    }
    if(!_summary_flag) printf("%s: %s -> %s\n", _tstr, description, pf);
}

void BWUTest::report() const {
    printf("%s: pass: %ld, fail: %ld\n", _tstr, pass_count(), fail_count());
    fflush(stdout);
}
