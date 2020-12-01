
/*

Babak Poursartip
11/17/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

transform:
 - do sth to every element of in a range
 - put it in another collection
 - or can work pairwise with elements

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

int main(){

std::cout << " starts here ...\n";

std::vector<int> m{1,2,3,4,2,8,2,10};
std::vector<int> m2(m.size());

// double each element and putting back the result in-place
std::cout << " vec: \n";
for (auto c:m) std::cout << c <<" ";
std::cout <<"\n";
transform(begin(m), end(m), begin(m), [](int e){return e*2;});
std::cout << " after vec: \n";
for (auto c:m) std::cout << c <<" ";
std::cout <<"\n";

// pairwise operation with transform
std::cout << " pairwise vec: \n";
for (auto c:m) std::cout << c <<" ";
std::cout <<"\n";
transform(begin(m), end(m)-1, begin(m)+1, begin(m2), [](int e1, int e2){return e1-e2;});
std::cout << " after vec: \n";
for (auto c:m2) std::cout << c <<" ";
std::cout <<"\n";

//
std::vector<int> m3(10);
std::vector<int> m4(10);
std::vector<int> m5(10);
iota(begin(m3), end(m3), 1);
iota(begin(m4), end(m4), 2);
transform(begin(m4), end(m4), begin(m3), begin(m5), [](int elem1, int elem2) {return elem1 + elem2; });

std::cout << " vec1: \n";
for (auto c:m3) std::cout << c <<" ";
std::cout <<"\n";

std::cout << " vec2: \n";
for (auto c:m4) std::cout << c <<" ";
std::cout <<"\n";

std::cout << " vec3c: \n";
for (auto c:m5) std::cout << c <<" ";
std::cout <<"\n";
std::cout << " finished.\n";

return 0;
}
