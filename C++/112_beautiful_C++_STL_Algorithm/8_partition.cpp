
/*

Babak Poursartip
12/12/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

partition

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(){

std::cout << " starts here ...\n";

std::vector<int> num(8);
iota(begin(num), end(num),1);
std::cout << " vec: ";
for_each(begin(num), end(num), [](int e){std::cout << e << " ";});
std::cout << "\n";
auto selected = std::stable_partition(begin(num), end(num), [](int i ){return i%2!=0;}); // returns an iterator at the border of selected and unselected numbers.
std::cout << " vec: ";
for_each(begin(num), end(num), [](int e){std::cout << e << " ";});
std::cout << "\n";

auto four = std::find(begin(num), end(num), 4);
rotate(begin(num), selected, four);

std::cout << " vec: ";
for_each(begin(num), end(num), [](int e){std::cout << e << " ";});
std::cout << "\n";

std::cout << " finished.\n";

return 0;
}
