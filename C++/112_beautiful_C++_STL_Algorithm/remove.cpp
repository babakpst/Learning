
/*

Babak Poursartip
11/24/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

remove:

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

int main(){

std::cout << " starts here ...\n";

std::vector<int> s{1,2,3,4,3,5,6,7};

std::cout << " vec: \n";
for (auto c: s) std::cout << c << " ";
std::cout << "\n";

// newEnd is an iterator to the end of operation after removing
auto newEnd = remove(begin(s),end(s), 3);
std::cout << " vec after remove: \n";
for (auto c: s) std::cout << c << " ";
std::cout << "\n";

std::cout << " size: " << s.size() << " logical size: " << newEnd-begin(s) << "\n";
// erasing the extra element from the end of the vector
s.erase(newEnd, end(s));
std::cout << " size: " << s.size() <<"\n";


// shrink the above commands in one line.
s.erase(remove(begin(s),end(s), 3),end(s));


std::cout << " finished.\n";

return 0;
}
