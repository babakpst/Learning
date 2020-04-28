// side-effects.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-11
#include <cstdio>
#include <cstdlib>
#include <ctime>

namespace bw {
    static unsigned _x = 0;
    class R {
    public:
        unsigned operator()() {
            srand(_x + (unsigned) time(0));
            return (_x += rand()) % 100;
        }
    };
}

#define TIMES(a, b) (a * b)

int main() {
    printf("macro returns %d\n", TIMES(5, 25));
    return 0;
}
