// lambda-02.cpp by Bill Weinman <http://bw.org/>
// modified 2018-10-10


/*
[var] capture var by value
[&var] capture var by reference
[=] capture all variables by value 
[&] capture all variables by reference
[&,var] capture all variables by reference, except var by value
[&var,var2] capture var by reference, and var2 by value 
*/

#include <cstdio>
#include <locale>
#include <algorithm>
#include <string.h>

using namespace std;

constexpr size_t _maxlen = 128;

int main() {
    char s[] = "life is too short not to enjoy it";
    
    char lastc = 0;
    // =: lambda has access to all var by value, but it cannot change the 
    //var. By adding mutable, we can change. Not a good idea to use mutable.
    transform( s, s + strnlen(s, _maxlen), s, [=] (const char & c) mutable -> char {
        const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c);
        lastc = c;
        return r;
    } );
    puts(s);
    
    return 0;
}
