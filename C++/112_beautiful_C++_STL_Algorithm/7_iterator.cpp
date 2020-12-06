
/*

Babak Poursartip
12/06/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

Iterators: 

- back_inserter: we get an iterator to the end of the collection, new iterators are added at the end.
- front_inserter: the iterator is at the beginning, inserts at the beginning of the collection.
- Not all containers support these iterators. Ex: vector only supports back_inserter.

- it works with fill_n (not fill) and generate_n (not generate), and transfrom, copy, copy_if, unique_copy, and reverse_copy.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <queue>

int main(){

std::cout << " starts here ...\n";

// pre-allocated containers =============
std::vector<int> v1(10);
std::cout << " vec: \n";
for_each(begin(v1), end(v1), [](int e){std::cout << e << " ";});
std::cout << "\n";

fill(begin(v1), end(v1), 1);
std::cout << " vec: \n";
for_each(begin(v1), end(v1), [](int e){std::cout << e << " ";});
std::cout << "\n";

fill_n(begin(v1),6,2);
std::cout << " vec: \n";
for_each(begin(v1), end(v1), [](int e){std::cout << e << " ";});
std::cout << "\n";

iota(begin(v1), end(v1), 1);
std::cout << " vec: \n";
for_each(begin(v1), end(v1), [](int e){std::cout << e << " ";});
std::cout << "\n";

// wo preallocating ==============================
std::vector<int> v2; // has not been allocated.
//fill_n(begin(v2),6,2); // not going to workin bcs v2 has need been allocated. COMPILE ERROR
fill_n(back_inserter(v2),6,2);
std::cout << " vec: \n";
for_each(begin(v2), end(v2), [](int e){std::cout << e << " ";});
std::cout << "\n";
std::cout << v2.size()<<std::endl;

generate_n(back_inserter(v2),10,[n=0]()mutable{return n++;});
std::cout << " vec: \n";
for_each(begin(v2), end(v2), [](int e){std::cout << e << " ";});
std::cout << "\n";



// deque with fornt_inserter ==========================
std::deque<int> q3;
fill_n(front_inserter(q3), 6, 2);
generate_n(front_inserter(q3),10,[n=0]()mutable{return n++;});
std::cout << " vec: \n";
for_each(begin(q3), end(q3), [](int e){std::cout << e << " ";});
std::cout << "\n";


// transfrom with back_inserter ============================
v2.clear(); // romoves all the elements. (like just defining the vector)
std::cout << " vec: \n";
for_each(begin(v2), end(v2), [](int e){std::cout << e << " ";});
std::cout << "\n";

std::transform(begin(v1), end(v1), back_inserter(v2), [](int e){return e*2;});
std::cout << " vec: \n";
for_each(begin(v2), end(v2), [](int e){std::cout << e << " ";});
std::cout << "\n";

// copy_if with back_inserter ========================
std::vector<int> v3{5,2,8,6,7,3};
std::vector<int> v4; // we do not need to know how many even elements are in v3, with back_inserter
copy_if(begin(v3), end(v3), back_inserter(v4), [](int e){return e%2==0;});

std::cout << " vec: \n";
for_each(begin(v4), end(v4), [](int e){std::cout << e << " ";});
std::cout << "\n";

// unique_copy with back_inserter ==================
v3[3]=8;
std::vector<int> v6; // no need to know the number of unique elements in the vector.
unique_copy(begin(v3),end(v3), back_inserter(v6));
std::cout << " vec: \n";
for_each(begin(v6), end(v6), [](int e){std::cout << e << " ";});
std::cout << "\n";


// string with back_inserter
std::string sentence = " Babak is great";
std::string reverse;
reverse_copy(begin(sentence), end(sentence), back_inserter(reverse));
std::cout << sentence << " "  << reverse << std::endl;



std::cout << " finished.\n";

return 0;
}
