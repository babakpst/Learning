// side-effects.cpp by Bill Weinman <http://bw.org/>



#include <sstream>

#include <cstdlib>
#include <ctime>

namespace mine {

    static unsigned x = 0;

    // returns random numbers, each time called
    class random {
      public:
        unsigned operator()() {
          srand(x + (unsigned) time(0));
          return (x += rand()) % 100;
        }
    };
}


// this is a text replacement.
#define TIMES(a, b) (a * b)
#define MAXIMUM(a, b) (a > b?a:b)


template<typename T>
void print_maximum(T a, T b){
  printf("max %d and %d: %d  \n", a, b, (a > b?a:b) );
}



int main() {

    printf("macro returns %d  \n", TIMES(5, 25));

    int var1 = 5;
    int var2 = 15;
    printf("max %d and %d: %d  \n",var1, var2, MAXIMUM(var1, var2));

    mine::random cvar1,cvar2;
    // each time cvar1 and cvar2 is called, they generate random numbers.
    // the the MAXIMUM def is not correct.
    printf("max %d and %d: %d  \n", cvar1(), cvar2(), MAXIMUM(cvar1(), cvar2()));
    print_maximum(cvar1(), cvar2());

    return 0;
}
