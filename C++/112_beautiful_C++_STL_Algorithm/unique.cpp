
/*

Babak Poursartip
12/01/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

unique: to remove duplicates in a sroted vector.
- it does not erase the the extra elements.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(){

std::cout << " starts here ...\n";

std::vector<int> m{1, 2, 3, 4, 3, 2, -1, 2, 5, 3, 8};
std::vector<int> m2=m;
std::vector<int> m3(m.size());

// if vector is not sorted, there would be no change
std::cout << " vec: \n" ;
for (auto c: m) std::cout << c << " ";
std::cout << "\n" ;
unique(begin(m), end(m));
std::cout << " vec: \n" ;
for (auto c: m) std::cout << c << " ";
std::cout << "\n" ;

// sorted
sort(begin(m), end(m));
std::cout << " vec: \n" ;
for (auto c: m) std::cout << c << " ";
std::cout << "\n" ;
auto endit = unique(begin(m), end(m));
std::cout << " after vec: \n" ;
for (auto c: m) std::cout << c << " ";
std::cout << "\n" ;
m.erase(endit,end(m));
std::cout << " after vec: \n" ;
for (auto c: m) std::cout << c << " ";
std::cout << "\n" ;

// unique_copy
sort(begin(m2), end(m2));
unique_copy(begin(m2), end(m2), begin(m3)); // should be sorted
std::cout << " after unique_copy vec: \n" ;
for (auto c: m3) std::cout << c << " ";
std::cout << "\n" ;

std::cout << " finished.\n";

return 0;
}
