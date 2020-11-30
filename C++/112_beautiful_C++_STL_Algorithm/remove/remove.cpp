
/*

Babak Poursartip
11/24/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

remove: removes all elements with particular values
remove_if: removes with a lambda

- If we use remove with vector, it does not shrink the size of the vector, or change the values past the new end. If we want to shrink the vector, we need to use erase to shrink the size of the vector. 

before remove       after remove
  _ _
1 2 3 4 5 6 7  ==> 1 4 5 6 7 6 7
  
- remove returns an iterator to the new end.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#include "Resource.h"

int main(){

std::cout << " starts here ...\n";

std::vector<int> s{1,2,3,4,3,5,6,7};
std::vector<int> ss=s;

std::cout << " vec: \n";
for (auto c: s) std::cout << c << " ";
std::cout << "\n";

// newEnd is an iterator to the end of operation after removing
auto newEnd = remove(begin(s),end(s), 3); // removes 3 from the vector
std::cout << " vec after remove: \n";
for (auto c: s) std::cout << c << " ";
std::cout << "\n";

std::cout << " size: " << s.size() << " logical size: " << newEnd-begin(s) << "\n";
// erasing the extra element from the end of the vector
s.erase(newEnd, end(s));
std::cout << " size: " << s.size() <<"\n";
std::cout << " vec after erase: \n";
for (auto c: s) std::cout << c << " ";
std::cout << "\n";


std::cout << " short \n";
std::cout << " vec: \n";
for (auto c: ss) std::cout << c << " ";
std::cout << "\n";
// shrink the above commands in one line.
ss.erase(remove(begin(ss),end(ss), 3),end(ss));
std::cout << " vec: \n";
for (auto c: ss) std::cout << c << " ";
std::cout << "\n";

// remove_if with a class ===========================
std::vector<Resource> myV(2);
std::cout << "now\n";
myV[0].setValue(10);
myV[1].setValue(11);
std::cout << "now2\n";
for(auto c:myV) std::cout << " i: " << c.getValue() << " cout: " << c.get2() << std::endl;
auto lm = [](const Resource &r){return r.getValue()==10;};
auto newEnd2 = remove_if(begin(myV), end(myV),lm);
myV.erase(newEnd2,end(myV));
for(auto c:myV) std::cout << " i: " << c.getValue() << " cout: " << c.get2() << std::endl;

std::cout << " finished.\n";

return 0;
}
