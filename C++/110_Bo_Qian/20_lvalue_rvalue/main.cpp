// reference+ rvalue + lvalue

/*
Babak Poursartip
5/17/2020

Bo Qian
Advanced c++

important notes:
If a function has an identifiable memory address that is a lvalue var, otherwise it is rvalue.

*/

#include <cstdio>
#include <iostream>


int square(int &x){return x*x;}
int square2(const int &x){return x*x;}

int globalVar;

int & foo(){return globalVar;};
int foo2(){return globalVar;};

// =======================================
// Is there a way to write a function that only accpet temporary rvalue objects? Yes
// &&name is an rvalue reference
void printName(std::string &&name){
std::cout << "rvalue: "  << name << std::endl;
}


// in both cases the previous function would be prefered by the compiler for rvalues.
//void printName(const std::string &name){
void printName(std::string &name){
std::cout << "lvalue: " << name << std::endl;
}


// =======================================
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


// ===============================
// cherono.
// only accepts temp rvalue objects

std:: string str = "shiva";
printName(str); // calls the func that accept lvalue only.
printName("Bob"); // calls the func that only accepts the rvalue.


printf (" \n program ends! \n");

return 0;
}

