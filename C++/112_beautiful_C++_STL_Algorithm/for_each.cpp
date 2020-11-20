
/*

Babak Poursartip
11/20/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

- do not write raw for loop.
- for_each: takes a lambda function, but if the point is to iterate over the entire collection, probably a traditional for loop is more useful. 
- for_each is more usefull when you do not want to iterate over the entire collection.

*/
#include <iostream>
#include <vector>
#include <algorithm>


int main(){

std::cout << " starts here ...\n";

std::vector<int> mv{1,2,3,4,5,6};

// ordinary for loop
std::cout << "\n vec: \n";
for (auto it = begin(mv); it != end(mv); ++it) std::cout << *it << " ";
std::cout << std::endl;


// ordinary for loop ===============================
for (auto it = begin(mv); it != end(mv); ++it) *it = 0;

std::cout << "\n vec: \n";
for (auto it = begin(mv); it != end(mv); ++it) std::cout << *it << " ";
std::cout << std::endl;

// ranged-based for loop ===============================
for (auto &c : mv) c = 1;  // very important: it should be a reference to be modified.
std::cout << "\n vec: \n";
for (auto c : mv) std::cout << c << " ";
std::cout << std::endl;

//  for_each loop ===============================
for_each(begin(mv), end(mv), [](int& e){e = 2;});
std::cout << "\n vec: \n";
for (auto c : mv) std::cout << c << " ";
std::cout << std::endl;

//  for_each loop ===============================
mv={1,2,3,4,5,6};
auto firstthree = find(begin(mv), end(mv), 3);
for_each(firstthree, end(mv), [](int& e){e = 0;});
std::cout << "\n vec: \n";
for (auto c : mv) std::cout << c << " ";
std::cout << std::endl;





std::cout << " finished.\n";

return 0;
}
