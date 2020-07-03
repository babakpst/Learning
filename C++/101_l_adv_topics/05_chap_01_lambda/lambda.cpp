
// lambda.cpp by Bill Weinman <http://bw.org/>

// lambda: a function w/o name

// enclosure: an encapsulated block of the code

#include <cstdio>
#include <algorithm>
#include <locale>
#include <string.h> // header for strlen

constexpr size_t _maxlen = 128;

class title {
  char lastc;
public:
  title() :lastc(0){}
  char operator () (const char &c);
};


char title::operator() ( const char &c){
    const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c);
    lastc = c;
    return r;
}

int main() {
    char s[] = "Life is too short not to enjoy it.";
    std::transform( s, s + strnlen(s, _maxlen), s, title() );
    puts(s);
    
    return 0;
}
