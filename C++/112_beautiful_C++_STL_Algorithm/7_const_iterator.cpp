
/*

Babak Poursartip
12/10/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

const interators

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(){

std::cout << " starts here ...\n";

std::array<const int, 5> ca{3,1,5,2,0};
auto it = begin(ca);
it++; // this is fine.
//*it = 7 ; // wrong it is const.
int i = *it; // this is possible.


//std::vector<const int> vc; // vector cannot have const element.

it =std::find(begin(ca), end(ca), 1);
it++;
// *it = 7; // error bcs array is const int, and cannot be change.
// it = cbegin(c); // error because the type of it is an iterator to a const int, but cbegin is a constant iterator.


std::vector<int> v1{1,2,3,4,5};
auto it2 = begin(v1);
it2++;
*it2=8;

auto cit = cbegin(v1);
cit++;
//cit = 7; // this is an error.

std::cout << " finished.\n";

return 0;
}
