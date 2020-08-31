
// Babak Poursartip
// shallow copy
// deep copy

// From Modern C++
// Copying large amount of data is expensive, and people use a lot of tricks to avoid unneccessary copies. 
// Shallow copy means we only copy the address of the data but not the data itself. 


#include <iostream>

int main(){

puts(" Code starts ...");

// shallow copy
puts("\n null pointer ====");
// This is a null pointer and cannot be dereferenced (may work by garbage output).
// Most of the compilers does not signal an error or a warning for uninitialized pointer
int *pAA;
std::cout << "is it null? " << std::boolalpha << (pAA == NULL) << std::endl;
std::cout << "pAA:  " << pAA << std::endl;
std::cout << "*pAA: " << *pAA << std::endl;
std::cout << "-------------\n ";

puts("\n shallow copy ====");
int *pA = new int; // This is not a null pointer and can be dereferenced, with random output.
std::cout << "is it null? " << std::boolalpha << (pA == NULL) << std::endl;
std::cout << "pA:  " << pA << std::endl;
std::cout << "*pA: " << *pA << std::endl;
std::cout << "-------------\n ";
int i = 5;
pA = &i;

int *pB = pA; // pB points to the same location in the memory as pA. Thus if I change the content of either pA or PB, the other one is changing.

printf(" Here is pA: %d \n", *pA);
printf(" Here is pB: %d \n", *pB);

i++;

printf(" Here is pA: %d \n", *pA);
printf(" Here is pB: %d \n", *pB);

// deep copy
// Here we copy the content of the memory rather than only the addresses.
puts("\n deep copy ====");
int j = 10;
int *pC=new int, *pD=new int;
*pC = j;
*pD = j;
printf(" Here is pC: %d \n", *pC);
printf(" Here is pD: %d \n", *pD);

++j;

printf(" Here is pC: %d \n", *pC);
printf(" Here is pD: %d \n", *pD);


(*pC)++;

printf(" Here is pC: %d \n", *pC);
printf(" Here is pD: %d \n", *pD);


(*pD)++;

printf(" Here is pC: %d \n", *pC);
printf(" Here is pD: %d \n", *pD);

puts(" Terminated successfully.");
return 0;
}

