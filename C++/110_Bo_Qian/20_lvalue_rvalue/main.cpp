
/*
Babak Poursartip
5/17/2020

Bo Qian
Advanced c++

important notes:
If a function has an identifiable memory address that is a lvalue var, otherwise it is rvalue.

*/

#include <cstdio>


int square(int &x){return x*x;}
int square2(const int &x){return x*x;}

int globalVar;

int & foo(){return globalVar;};
int foo2(){return globalVar;};

int main(){

printf (" program starts ... \n\n");

// reference (lvalue reference)
int i; 
i = 5;
int & r = i;
//int & r = 5; // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int'

const int & d = 5; // ok

printf(" square %d \n", square(i));
//printf(" square %d \n", square(10)); cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

printf(" square %d \n", square2(40));



// rvalue can be used to define lvalue
// v+2 is rvalue but *(v+2) is lvalue.
int v[3];
*(v+2) = 4;

// Misconcept 1: function or operator always yields rvalues.
foo() = 5;
printf("my global variable: %d \n", globalVar);

//foo2() = 5; error.


// Misconcept 2: lvalue is modifiable
const int c = 2;
// c = 1; ERORR: c is lvalue but not modifiable.




printf (" \n program ends! \n");

return 0;
}

