// Babak Poursartip
// 10/01/2020

#include <iostream>


// not semicolon here. During the pre-processing stage, this text would be replaced. 
#define WAIT std::cin.get()
//#define WAIT std::cin.get(); // the other makes better sense.

#define DEBUG 0

#if DEBUG == 1
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif


int main(){

LOG("Hello");
WAIT;

return 0;
}



