
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
puts("\n shallow copy ====");
int i = 5;
int *pA = new int;
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

