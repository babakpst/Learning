
/*

Babak Poursartip
11/19/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

partial sort, partial_sort

- if you have a large set and you do not want to sort the entire set, you can use partial sort.
- ex: {1,5,4,2,9,7}, sort the first 3 elements: {1,2,4,9,5,7}, now the first three are ordered, and the rest are not necessarily in order, but they are all greater that the 3rd element.
- partial sort takes three parameters: first and last are the iterators to the container, the middle indicate where the non-sortedness begins.

- is_sorted_until: returns the iterator/pointer, in which the vector is sorted up to.

- partial_sort_copy: copies from a first vector, indicated by its iterators, to a second copy, indicated by its iterators. The size of the vector that is being copied is determined by the size of the second vector. 

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main(){

std::cout << " starts here ...\n";
std::vector<int> myV{4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };

// this is partial sort to all of the myV. Here the first 4 elements would be sorted, and the rest of the elements are larger, in no particular order.
partial_sort(begin(myV), find(begin(myV), end(myV),-2), end(myV));
std::cout << " here is my vec: \n";
for (auto c:myV) std::cout << c << " ";
std::cout << "\n\n";


//std::vector<int>::iterator breakpoint = is_sorted_until(begin(myV), end(myV));
auto breakpoint = is_sorted_until(begin(myV), end(myV));
std::cout << " sorted until: " << *breakpoint << "\n";

// ==========================================
// shuffle for partial copy
std::random_device randomdevice; // creating a random device
std::mt19937 generator(randomdevice()); // creating a generator from the random device.
                            // Here, it is a Mersenne Twister to use as a generator
                            //The Mersenne Twister is a pseudorandom number generator. 
                            // 19937 is how many bits exist in the Mersenne prime.

shuffle(begin(myV),end(myV), generator);
std::cout << " here is after shuffle: \n";
for (auto c:myV) std::cout << c << " ";
std::cout << "\n\n";


std::vector<int> nV(5);
partial_sort_copy(begin(myV), end(myV), begin(nV), end(nV));
std::cout << " here is the new vec: \n";
for (auto c:nV) std::cout << c << " ";
std::cout << "\n\n";

std::cout << " finished.\n";

return 0;
}
