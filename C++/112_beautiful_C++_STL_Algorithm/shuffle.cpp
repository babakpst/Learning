
/*

Babak Poursartip
11/19/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

shuffle

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <random> // this is need for the shuffle 

int main(){

std::cout << " starts here ...\n";
std::vector<int> myV{4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };

std::random_device randomdevice; // creating a random device
std::mt19937 generator(randomdevice()); // creating a generator from the random device.
                            // Here, it is a Mersenne Twister to use as a generator
                            //The Mersenne Twister is a pseudorandom number generator. 
                            // 19937 is how many bits exist in the Mersenne prime.

shuffle(begin(myV),end(myV), generator);
std::cout << " here is my vec 1 : \n";
for (auto c:myV) std::cout << c << " ";
std::cout << "\n\n";

std::cout << " finished.\n";

return 0;
}
