
/*

Babak Poursartip
12/12/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

rotate: rotates items inside a collection.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(){

std::cout << " starts here ...\n";
std::vector<int> task(6);
iota(begin(task), end(task), 1);

auto two = find(begin(task), end(task), 2);
auto four = find(begin(task), end(task), 4);

// not very clear
rotate(two, four, four+1); // iterator: first middle (which element should be at the start of the range) last. 
std::cout << " vec: ";
for_each(begin(task), end(task), [](int e){std::cout << e << " ";});
std::cout << "\n";

std::cout << " finished.\n";

return 0;
}
