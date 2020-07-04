// A simple unit test class
// by Bill Weinman <http://bw.org/>



#ifndef __Lib__UnitTest__
#define __Lib__UnitTest__

#include <sstream>

#define __UTest_VERSION "1.0.0"

constexpr const char * __u_pstr = "pass";
constexpr const char * __u_fstr = "fail";

class Unit_Test {
    const char * _tstr = nullptr;
    
    unsigned long int _pass_count = 0;
    unsigned long int _fail_count = 0;
    bool _summary_flag = false;
    
    Unit_Test( Unit_Test & );                   // no copy constructor
    Unit_Test operator = ( Unit_Test & );       // no assignment operator
    Unit_Test(){}                             // no default constructor
public:
    Unit_Test( const char * );
    void init ( const char * );
    bool summary ( bool flag ) { return _summary_flag = flag; }
    bool summary() { return _summary_flag; }
    unsigned long int pass_count() const { return _pass_count; }
    unsigned long int fail_count() const { return _fail_count; }
    static const char * version() { return __UTest_VERSION; }
    void test ( const char * description, const int flag );
    void report() const;
};

#endif /* defined(__Lib__UnitTest__) */
