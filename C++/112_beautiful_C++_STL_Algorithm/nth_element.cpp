
/*

Babak Poursartip
11/19/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

nth_element: it partitions the container into two parts based the nth element, but the two partitions are not sorted, just all the elements below the nth elements are smaller, and all the elements after the nth element are larger


1 5 4 2 9 7 3 8 2---> pick 5th element, then 4 would be the 5th element from bottom if we sort the container. The output would be:

1 2 3 2 (4) 7 9 8 5

*/
#include <iostream>
#include <vector>
#include <algorithm>


int main(){

std::cout << " starts here ...\n";
std::vector<int> myV{1,5,4,2,9,7,3,8,2};

std::cout << " here is the vector: \n";
for (auto c:myV) std::cout << c << " ";
std::cout << "\n\n";

int middle = *(begin(myV)+4);
std::cout << " middle " << middle << std::endl;

nth_element(begin(myV),begin(myV)+4, end(myV));

middle = *(begin(myV)+4);
std::cout << " middle new " << middle << std::endl;

std::cout << " here is the vector: \n";
for (auto c:myV) std::cout << c << " ";
std::cout << "\n\n";


std::cout << " finished.\n";

return 0;
}
