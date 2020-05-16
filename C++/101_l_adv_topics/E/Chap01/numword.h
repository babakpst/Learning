// numword.h by Bill Weinman <http://bw.org/>
// version as of 2018-10-05
#ifndef _NUMWORD_H
#define _NUMWORD_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <new>

namespace bw {
    
    constexpr const char * _version = "2018.10.05";
    typedef uint64_t numnum;    // yummy numbers
    
    // _maxstr is max size of string
    constexpr size_t _maxstr = 1024;
    
    // _maxnum is nine hundred ninty-nine quadrillion nine hundred ninty-nine trillion nine hundred ninty-nine billion nine hundred ninty-nine million nine hundred ninty-nine thousand nine hundred ninty-nine
    constexpr numnum _maxnum = 999999999999999999;
    
    static const char * errnum = "error";
    
    static const char * _singles[] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    
    static const char * _teens[] = {
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };
    
    static const char * _tens[] = {
        errnum, errnum, "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty",
    };
    
    static const char * _hundred = "hundred";
    
    static const char * _powers[] = {
        errnum, "thousand", "million", "billion", "trillion", "quadrillion"
    };
    
    static const char * _hyphen = "-";
    static const char * _space = " ";
    
    class numword {
        numnum _num = 0;
        char * _buf = nullptr;
        size_t _buflen = 0;
        bool hyphen_flag = false;
        
        void clearbuf();
        void initbuf();
        void appendspace();
        void appendbuf(const char * s);
        
    public:
        numword() : _num(0) {}
        numword(const numnum & num) : _num(num) {}
        ~numword();
        const char * version() const { return _version; }
        void setnum(const numnum & num) { _num = num; }
        numnum getnum() const { return _num; }
        numnum operator = ( const numnum & num );
        const char * words();
        const char * words( const numnum & num );
        const char * operator () ( const numnum & num ) { return words(num); };
    };
    
}

#endif /* _NUMWORD_H */

