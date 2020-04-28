// BWUTest.h
// A simple unit test class
// by Bill Weinman <http://bw.org/>
// as of 2018-10-12

#ifndef __BWLib__BWUTest__
#define __BWLib__BWUTest__

#include <cstdio>

#define __BWUTest_VERSION "1.0.5"

constexpr const char * __bwu_pstr = "pass";
constexpr const char * __bwu_fstr = "fail";

class BWUTest {
    const char * _tstr = nullptr;
    
    unsigned long int _pass_count = 0;
    unsigned long int _fail_count = 0;
    bool _summary_flag = false;
    
    BWUTest( BWUTest & );                   // no copy constructor
    BWUTest operator = ( BWUTest & );       // no assignment operator
    BWUTest(){}                             // no default constructor
public:
    BWUTest( const char * );
    void init ( const char * );
    bool summary ( bool flag ) { return _summary_flag = flag; }
    bool summary() { return _summary_flag; }
    unsigned long int pass_count() const { return _pass_count; }
    unsigned long int fail_count() const { return _fail_count; }
    static const char * version() { return __BWUTest_VERSION; }
    void test ( const char * description, const int flag );
    void report() const;
};

#endif /* defined(__BWLib__BWUTest__) */
