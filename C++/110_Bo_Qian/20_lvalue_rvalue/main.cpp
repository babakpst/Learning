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

// function overload: the function with const would never be used, bcs other always proceeds. 
int square(int &x){puts("lvalue"); return x*x;} // only accepts lvalues.
int square(int &&x){puts("rvalue"); return x*x;} // only accepts rvalues.
int square(const int &x){puts("lvalue/rvalue"); return x*x;} // accepts rvalues and lvalues.


int globalVar;

int & foo(){return globalVar;};
int foo2(){return globalVar;}; //

// =======================================
// function overloading to accept either rvalue or lvalue.

// only accpets temporary rvalue objects
// &&name is an rvalue reference
void printName(std::string &&name){
  std::cout << "rvalue: "  << name << std::endl;
}

// in both cases the previous function would be prefered by the compiler for rvalues.
//void printName(const std::string &name){  // accepts both rvalues and lvalues.
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

printf(" square %d \n", square(40));

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

