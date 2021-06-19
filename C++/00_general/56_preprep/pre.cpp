
// Babak Poursartip
// 09/30/2020

//partially from https://www.youtube.com/watch?v=3tIqpEmWMLI&ab_channel=TheCherno

// To see the file after preprocessing/preprocessor: g++ -E main.cpp > main_prep
// To treat a non-cpp extension as a c++ file: g++ -X main.cpp > main_prep
// To see the assembly output: g++ -S pre.cpp  . This will generate pre.s, that has the assembly translation of the cpp file.

// assembly without compiler optimization: g++ -g -S pre.cpp
// assembly with compiler optimization: g++ -O3 -g -S pre.cpp				


#include <iostream>


#define babak INTEGER
#define BABAK babak
#define INTEGER int

const char *log(const char *message){return message;}



//#if 0
//#if Shiva // shiva has not been pre-defined, and the compiler set it to 0.
#if 1
BABAK
#include "inc_main.includeMe"
{

std::cout << "hello\n";

std::cout << log("check") << std::endl;

int a = 1, b = 2, results;
results = a+b;

#define BABAK }

return 0;
BABAK
#endif

