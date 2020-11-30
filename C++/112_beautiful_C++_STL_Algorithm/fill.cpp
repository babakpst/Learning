
/*

Babak Poursartip
11/29/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

fill: put a value in the container (first we need to have the size and then fill it)
fill_n: putting a value in the first n element of the container

iota: puts incremental values in the container (in the numeric lib)

generate:  generates values with lambda
generate_n:

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

int main(){

std::cout << " starts here ...\n";

// fill =========
std::vector<int> v(10);
std::cout << " vec: \n";
for(auto c:v) std::cout << c << " ";
std::cout << std::endl;
fill(begin(v),  end(v), 1);
std::cout << " fill after vec: \n";
for(auto c:v) std::cout << c << " ";
std::cout << std::endl;

fill_n(begin(v),  6, 2);
std::cout << "fill_n after vec: \n";
for(auto c:v) std::cout << c << " ";
std::cout << std::endl;

// iota
iota(begin(v), end(v), 2);  // starts from 2: 2, 3, 4, etc.
std::cout << " iota vec: \n";
for(auto c:v) std::cout << c << " ";
std::cout << std::endl;

// generate ===================
int ind = 10;
auto lm = [&ind](){return --ind;};
generate(begin(v), end(v), lm);
std::cout << " generate vec: \n";
for(auto c:v) std::cout << c << " ";
std::cout << std::endl;

ind = 1;
auto lm2 = [&ind](){return ind*=2;};
generate_n(begin(v), 6, lm2);
std::cout << " generate_n vec: \n";
for(auto c:v) std::cout << c << " ";
std::cout << std::endl;



std::cout << " finished.\n";

return 0;
}
