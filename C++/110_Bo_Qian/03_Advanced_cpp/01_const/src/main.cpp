
/*

Babak Poursartip
04/30/2020

Bo Qian- Advaced c++: const

*/

#include <iostream>


int main(){

std::cout << "------ The code starts ------ \n\n";

// compile time constraint that an object cannot be modified.

// const var ------------------------------------------------------------------
const int ii = 10;
int jj = 3;
//ii = 12; error i is a constant

// const data, but pointer is not a constant ----------------------------------
const int *p1 = &ii;

std::cout << " pointer1: " << *p1 << "\n";
//*p1= 5; error.
p1++;
std::cout << " pointer1: " << *p1 << "\n";

// const pointer not data
int* const p2= &jj;
std::cout << " pointer2: " << *p2 << "\n";
*p2 = 5;
//p2 = &ii; error
std::cout << " pointer2: " << *p2 << "\n";

// data and pointer are borh constants ---------------------------------------
const int* const p3  = &ii;
std::cout << " pointer3: " << p3 << " "<<*p3 << "\n";
//p3=&jj; error


// data cosntant
int const *p4 = &ii; // this is the same as: const int*p4;
std::cout << " pointer4: " << p4 << " "<<*p4 << "\n";


// if const is on the left of *, data is const
// if const is on the right of *, pointer is cosnt

//=============================================================================
// remove the constantness of a constant
const int kk = 10;
std::cout<< " the constant is: " << kk << "\n";
const_cast<int&>(kk) = 12;
std::cout<< " the constant is: " << kk << "\n"; // not actually working.


//make a var constant in the middle of the code.
int j=4;
std::cout << " var is: " << j << "\n";
//static_cast<const int&>(j) = 13;  Not working !
std::cout << " var is: " << j << "\n";  
j = 16;
std::cout << " var is: " << j << "\n";

/*
benefits of const:
- Guard against inadvertent write.
- self documentation
- enables compiler to do more optimization
*/

std::cout<< " \n ---- Finished successfully ----- \n";

return 0;
}
