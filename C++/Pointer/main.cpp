
#include <iostream>

int main(){

std::cout << "this is inside the code" << std::endl;

int pp = 10;
int *p1;

p1 = & pp;

std::cout<<" here is the pointer: " << p1 << std::endl;
std::cout<<" here is value the pointer is pointing: " << *p1 << std::endl;

p1++;

std::cout<<" here is the pointer: " << p1 << std::endl;
std::cout<<" ====================== " << std::endl;

//    ======
const int i = 9;
const int *p11 = &i;  // data is const, not the pointer

std::cout<<" here is the pointer: " << p11 << std::endl; 
std::cout<<" here is the value of the pointer: " << *p11 << std::endl;
p11++;
std::cout<<" here is the pointer: " << *p11 << std::endl;

int* const p2; // pointer is const, not the data
const int* const p3; // pointer and the data is const

// if const is on the left of *, data is const
// if const is on the right of *, pointer is const

// These are equivalent: const int *p = &i   ====== int const *p=&i



return 0;
}
