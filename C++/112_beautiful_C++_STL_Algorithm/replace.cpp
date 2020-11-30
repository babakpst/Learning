
/*

Babak Poursartip
11/29/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

replace

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(){

std::cout << " starts here ...\n";
std::vector<int> m{1,2,3,4,2,8,2,10};

std::cout << " vec: \n";
for (auto c: m) std::cout << c << " ";
std::cout << "\n";

replace(begin(m), end(m), 2, 77);
std::cout << "replace vec: \n";
for (auto c: m) std::cout << c << " ";
std::cout << "\n";

auto lm = [](int e){return e<6;};
replace_if(begin(m), end(m), lm, 123);
std::cout << "replace_if vec: \n";
for (auto c: m) std::cout << c << " ";
std::cout << "\n";

std::cout << " finished.\n";

return 0;
}
