
/*

Babak Poursartip
11/17/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

Count

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(){

std::cout << " starts here ...\n";

std::vector<int> v{2,5,8,1,4,7,3,6,9,6,5,4,4,8};

// ===================================================
// count how many 4 are there in the vector: =========
int fours = 0;
const int target = 4;

fours = count(v.begin(), v.end(), target);
std::cout << " number of fours: " << fours << std::endl;
fours = count(begin(v), end(v), target);
std::cout << " number of fours: " << fours << std::endl;

// ===================================================
// count_if: count odd numbers in the vector =========
auto o = [](int c){return c%2!=0;};
int odds = count_if(begin(v), end(v), o);
std::cout << " number of odd numbers: " << odds << std::endl;

// ===================================================
// count_if: with map ================================
std::map<int, int> m{{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};

auto t = [](auto c){return c.second==31;};
int longmonth = count_if(begin(m), end(m), t);
std::cout << " number of long months: " << longmonth << std::endl;

// ===================================================
// allof, anyof, noneof ==============================
bool allof = all_of(begin(v), end(v), o);
bool noneof = none_of(begin(v), end(v), o);
bool anyof = any_of(begin(v), end(v), o);

std::cout << " allof: "<< std::boolalpha  << allof 
          << ", anyof: "<< std::boolalpha  << anyof
          << ", noneof: "<< std::boolalpha  << noneof
          << std::endl;

std::cout << " finished.\n";

return 0;
}
