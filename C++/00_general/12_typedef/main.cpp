
/*

Babak Poursartip
11/14/2021
	
typedef

*/
#include <iostream>
#include <vector>
#include <algorithm>

// ========================
struct myStruct
{
  int var;
  double dvar;
};

// combining typedef and struct:
typedef struct {
    int data1;
    char data2;
} newtype;

// ========================
float addition(float arg1, int arg2) {
    return arg1+arg2;
}


float subtraction(float arg1, int arg2) {
    return arg1-arg2;
}

// ========================
// without typedef
float call_a_func1(float (*call_this)(float, int), float arg1, int arg2) {
    return call_this(arg1, arg2);
}

// with typedef
typedef float (*aMathFunc)(float, int);
float call_a_func2(aMathFunc call_this, float arg1, int arg2) {
    return call_this(arg1, arg2);
}




int main()
{
std::cout << " starts here \n";

// alias ======= ===================
typedef unsigned long ulong;
ulong l2=2;

std::cout << " long: " << l2 << std::endl;


// simplify the declaration of a compound type================
// A variable declaration of myStruct in C also requires the keyword struct, but it may be omitted in C++:
struct myStruct myStructVar; // C style
myStruct myStructVar2; // C++ style

myStructVar.var = 5;
myStructVar.dvar = 5.2;
myStructVar2.var = 7;


typedef struct myStruct myStructCstyle;
myStructCstyle myStructVar3;
myStructVar3.var = 3;

typedef myStruct myStructCppstyle;
myStructCppstyle myStructVar4;
myStructVar4.var = 3;
std::cout << "cpp style: " << myStructVar4.var << std::endl;

newtype myStructVar5;
myStructVar5.data1 = 8;

std::cout << "struct type style: " << myStructVar5.data1 << std::endl;

// The typedef may be used to define a new pointer type========================
typedef int *intptr;

intptr ptr = new int;
*ptr= 12;
std::cout << "pointer: " << *ptr << std::endl;

// Function pointers================================
// without typedef
float out1 = call_a_func1( &addition, 5.2, 12 );
std::cout << " this is the output: "  << out1 << std::endl;

float out2 = call_a_func1( &subtraction, 5.2, 12 );
std::cout << " this is the output: "  << out2 << std::endl;

// with typedef
float out3 = call_a_func2( &addition, 5.2, 12 );
std::cout << " this is the output: "  << out3 << std::endl;

float out4 = call_a_func2( &subtraction, 5.2, 12 );
std::cout << " this is the output: "  << out4 << std::endl;

// C++11 introduced the possibility to express typedefs with using instead of typedef
using vector_t = std::vector<int>;
vector_t myVec(5,1);
std::for_each(begin(myVec), end(myVec), [](int a){std::cout << a << "  ";});
std::cout << std::endl;

std::cout << " End. \n";
return 0;
}
