
/*

Babak Poursartip
12/01/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

unique: to remove duplicates in a sroted vector.
- it does not erase the the extra elements.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(){

std::cout << " starts here ...\n";
  std::vector<int> m{1,2,3,4,5,6,7};

	std::string sentence = "Hello, world!";
	reverse(begin(sentence), end(sentence));
  std::cout << sentence << std::endl;

	iter_swap(begin(m), end(m) - 1);

	std::string orig="             ";
	reverse_copy(begin(sentence), end(sentence), begin(orig));
  std::cout << orig << std::endl;

std::cout << " finished.\n";

return 0;
}