// lambda-02.cpp by Bill Weinman <http://bw.org/>
// modified 2018-10-10
#include <cstdio>
#include <locale>
#include <algorithm>
using namespace std;

constexpr size_t _maxlen = 128;

int main() {
    char s[] = "big light in sky slated to appear in east";
    
    char lastc = 0;
    transform( s, s + strnlen(s, _maxlen), s, [&lastc] (const char & c) -> char {
        const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c);
        lastc = c;
        return r;
    } );
    puts(s);
    
    return 0;
}
