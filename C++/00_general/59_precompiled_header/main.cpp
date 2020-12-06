
// Babak Poursartip
// 10/05/2020

// https://www.youtube.com/watch?v=eSI4wctZUto&ab_channel=TheCherno

// precompiled header

/*
- precompiled header is to avoid compiling headers anytime we do some minor changes in the code. Here, we precompile pch.h, so that it does not need to be compiled everytime. 

- The name of the precompiled header is arbitrary. By default, it is "stdfax.h".

- To create precompiled headers, drop all the headers in a .h file. compile the header file: g++ pch.h. This will create a new file: pch.h.gch. This is a fairly large file. Next, we can just compile the main file. This would be very fast then. 





*/
#include "pch.h"	 


int main(){

std::cout << "Hello world\n";

return 0;
}
