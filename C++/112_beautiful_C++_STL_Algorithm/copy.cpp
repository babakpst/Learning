
/*

Babak Poursartip
11/23/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

copying

- if you want to copy the entire container, just use the =.
- copy command is good if you want to partially copy a container.
- copy9)
- copy_n()
- copy_if()
- copy_backward(), only if we copy within the same collection.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(){

std::cout << " starts here ...\n";

std::vector<int> s {1,5,8,7,9,6,7,-5,-2};
std::vector<int> m(s.size());

std::cout << " source vec: \n";
for (auto c:s) std::cout << c << " ";
std::cout << "\n";

// simple copy ==================
copy(begin(s), end(s), begin(m)); // this is equivalent to auto v3 = s;
std::cout << " copy vec: \n";
for (auto c:m) std::cout << c << " ";
std::cout << "\n";


// partial copy ==================
auto pos = find(begin(s), end(s), 9);
std::vector<int> m2(s.size());
copy(begin(s), pos, begin(m2)); // copying up to position, not including position
std::cout << " partial copy vec: \n";
for (auto c:m2) std::cout << c << " ";
std::cout << "\n";

// partial copy with position copied (inclusive)
auto pos2 = find(begin(s), end(s), 9);
std::vector<int> m3(s.size());
copy(begin(s), pos2+1, begin(m3)); // copying up to position, not including position
std::cout << " partial copy vec: \n";
for (auto c:m3) std::cout << c << " ";
std::cout << "\n";


// copy_if ==================
std::vector<int> m4(s.size());
auto lf = [](int a){return a%2==0;};
copy_if(begin(s), end(s), begin(m4), lf); // copying only if the value of the lambda func is true
std::cout << " partial copy vec: \n";
for (auto c:m4) std::cout << c << " ";
std::cout << "\n";


// copy_n ==================
std::vector<int> m5(s.size());
copy_n(begin(s), 3, begin(m5)); // copying only 3 elements from the source to the destination vec
std::cout << " partial copy vec: \n";
for (auto c:m4) std::cout << c << " ";
std::cout << "\n";


// inplace copy  ================== (be careful: no overlap should be in the range)
pos = find(begin(s), end(s), 7);
copy(begin(s), pos+1, pos+1); // copying only 3 elements from the source to the destination vec
std::cout << " partial copy vec: \n";
for (auto c:s) std::cout << c << " ";
std::cout << "\n";

// copy_backward  ================== 
copy_backward(begin(m4), end(m4), end(s)); 
std::cout << " partial copy vec: \n";
for (auto c:s) std::cout << c << " ";
std::cout << "\n";

std::cout << " finished.\n";

return 0;
}
