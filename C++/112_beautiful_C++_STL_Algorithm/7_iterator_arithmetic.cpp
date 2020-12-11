
/*

Babak Poursartip
12/09/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

iterator arithmetic
- in case of a reverse iterator, ++ adds the iterator in the other direction.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(){

std::cout << " starts here ...\n";
int j;
int i = j = 0;

std::vector<int> v1{1,2,3,4,5,6,7};

// ================
auto index= find(begin(v1), end(v1),3);
auto distance = index - begin(v1);
index++;
std::cout << " index: " << *index << std::endl;

// ================
auto index2= find(rbegin(v1), rend(v1),3);
//auto distance = index - begin(v1);
index2++;
std::cout << " index2: " << *index2 << std::endl;

// == 
auto three = find (begin(v1), end(v1), 3);
bool firsthalf = (three - begin(v1)< end(v1)-three);
std::cout << " is it in the first half: " << std::boolalpha << firsthalf << std::endl;


std::cout << " finished.\n";

return 0;
}
