

// Babak

// preprocessor
// each of #... is a MACRO
#include <sstream>

// NO semicolon at the end. 
// This is not a real constant, but just text replacement macro
#define ONE 1
//#define FOUR 4;
#define HELLO "hello world!"

const int TEN = 10;
const char * HI = "a new hello world!";

// ACTUAL CONSTANT
constexpr int NINE = 10;
constexpr const char * HIII = "a new hello world!";


#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

int main(){

puts(" starts here ... ");

#define TWO 2


printf(" here is one: %d \n", ONE);
printf(" here is two: %d \n", TWO);
//printf(" here is FOUR: %S \n", FOUR);

puts(HELLO);
puts(HI);


printf(" MAX %d \n", MAX(5,2));
printf(" MIN %d \n", MIN(5,2));

puts(" End successfully. ");
return 0;
}
