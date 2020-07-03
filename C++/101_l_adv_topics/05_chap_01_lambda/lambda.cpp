
// lambda.cpp by Bill Weinman <http://bw.org/>


// REMARKS:
// - lambda: a function w/o name
// - closure: an encapsulated block of the code
// - a lambda funciton creates a closure.
// - read about stl::transform here: https://www.geeksforgeeks.org/transform-c-stl-perform-operation-elements/

// The goal of this code to use (lambda function or a class), and converts a text to first letter 
// capitalized.

#include <cstdio>
#include <algorithm>
#include <locale>
#include <string.h> // header for strlen

constexpr size_t _maxlen = 128;

// This class is a functor
class title {
    char lastc;
  public:
    title() :lastc(0){}
    char operator () (const char &c);
};


char title::operator() ( const char &c){
    printf("%c -",lastc);
    // 
    const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c);
    lastc = c;
    //puts(lastc);
    printf("%c %c %c \n",lastc, c, r);
    return r;
}

int main() {
    char s[] = "life is too short not to enjoy it.";

    // Transform is from the algorithm library.

    // option 1: using the class
    //std::transform( s, s + strnlen(s, _maxlen), s, title() );

    // option 2: using the lambda function
    // inside [] in the lambda function is called capture, here it captures a reference to lastc. 
    // -> in lambda is the function return operator. Here the function returns a char. 

    char lastc=0;
    std::transform( s, s + strnlen(s, _maxlen), s, [&lastc](const char &c){
    const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c); 
    lastc = c;
    return r; } );

    puts(s);


    
    return 0;
}
