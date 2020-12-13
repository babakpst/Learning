
/*

Babak Poursartip
12/12/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

swap: Does not work on iterators of collections. It works on any two references on the same type.
iter_swap: 
Swap_ranges:

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(){

std::cout << " starts here ...\n";
int a{5}, b{6};
std::cout << " a: " << a << " b: " << b << std::endl;
std::swap(a,b);
std::cout << " a: " << a << " b: " << b << std::endl;	

std::vector<int> even{2,4,6,8,10}, odd{1,3,5,7,9};

// swap =================
auto v1 = even;
std::cout << " vec \n";
for_each(begin(v1), end(v1), [](int e){std::cout << e<< " ";});
std::cout << "\n";
std::swap(v1[0],v1[1]);
std::cout << " vec \n";
for_each(begin(v1), end(v1), [](int e){std::cout << e<< " ";});
std::cout << "\n";

// iter_swap =================
std::iter_swap(begin(v1),begin(v1)+1);
std::cout << " vec \n";
for_each(begin(v1), end(v1), [](int e){std::cout << e<< " ";});
std::cout << "\n";

// iter_swap =================
auto v2 = odd;
std::swap(v1[0], v2[0]);
std::cout << " swap: " << v1[0] << " " << v2[0] << std::endl;

iter_swap(begin(v1), find(begin(v2), end(v2),5));
std::cout << " vec1: ";
for_each(begin(v1), end(v1), [](int e){std::cout << e<< " ";});
std::cout << "\n";
std::cout << " vec2: ";
for_each(begin(v2), end(v2), [](int e){std::cout << e<< " ";});
std::cout << "\n";

// swap_range ======
v1 = even, v2 =odd;
std::swap_ranges(begin(v1), find(begin(v1), end(v1), 6), begin(v2));
std::cout << " vec1: ";
for_each(begin(v1), end(v1), [](int e){std::cout << e<< " ";});
std::cout << "\n";
std::cout << " vec2: ";
for_each(begin(v2), end(v2), [](int e){std::cout << e<< " ";});
std::cout << "\n";



std::cout << " finished.\n";

return 0;
}
