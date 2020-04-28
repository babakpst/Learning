// primes.cpp by Bill Weinman <http://bw.org/>
// 2018-11-13
#include <cstdio>
#include <cstdlib>
#include "BWString.h"

constexpr const char * csvprimes = "2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97";

void parray (unsigned long * array, size_t len) {
    printf("printing %zd unsigned long values:\n", len);
    for(unsigned i = 0; i < len; ++i) {
        printf("%ld ", array[i]);
    }
    puts("");
}

int main() {
    // split the string on commas
    BWString csvbwstr = csvprimes;
    auto & sp = csvbwstr.split(',');
    size_t primecount = csvbwstr.split_count();
    
    // array of unsigned long ints for results
    unsigned long * primes = new unsigned long[primecount]();
    
    // populate the array
    for ( unsigned i = 0; i < primecount; ++i ) {
        BWString & numstr = *sp[i];
        primes[i] = strtoul(numstr.trim(), nullptr, 10);
    }
    
    parray(primes, primecount);
    delete [] primes;
    
    return 0;
}
