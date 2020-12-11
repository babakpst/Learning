
/*

Babak Poursartip
12/06/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

reverse iterator

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(){

std::cout << " starts here ...\n";

std::vector<int> v1{1,2,3,4,5,6,7,8};
std::vector<int> v2;

copy(rbegin(v1), rend(v1), back_inserter(v2));

std::cout << " vec:\n";
for_each(begin(v1), end(v1),[](int e){std::cout << e << " ";});
std::cout << "\n";

std::cout << " vec:\n";
for_each(begin(v2), end(v2),[](int e){std::cout << e << " ";});
std::cout << "\n";


//===
	v1[5] = 2;
	auto two = find(begin(v1), end(v1), 2);
	auto distance = two - begin(v1);
	two++;
  std::cout << " here: " << *two << " " << distance << std::endl;

	auto rtwo = find(rbegin(v1), rend(v1), 2);
	distance = rtwo - rbegin(v1);
	rtwo++;

  std::cout << " here: " << *rtwo << " " << distance << std::endl;

std::cout << " finished.\n";

return 0;
}
