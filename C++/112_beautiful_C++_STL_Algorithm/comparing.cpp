
/*

Babak Poursartip
11/19/2020

Reference: Beautiful C++: STL Algorithm
PluralSight

comparing: 
- equal checks whether two containers are equal.
- mismatch: determines the first place the two container diverge.
  The output is a pair of iterators.
  It takes three params: begin and end of the first container, and the begin of the second container. The end of the second container is not needed, because the length of the comparison is dictated by the length of the first container.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

int main(){

std::cout << " starts here ...\n";


// equal with vectors ========================
std::vector<int> mV1{1,2,3,2,5,6};
std::vector<int> mV2{1,2,3,4,5,5};

bool same = equal(begin(mV1),end(mV1),begin(mV2),end(mV2));
std::cout << "are vecs the same: " << std::boolalpha << same << std::endl;

// equal with map ========================
std::map<int, int> M1{ {1,2}, {3,4},{5,6},{7,9},{9,10} };
std::map<int, int> M2{ {1,2}, {3,4},{5,6},{7,9},{9,11} };

same = equal(begin(M1),end(M1),begin(M2),end(M2));
std::cout << "are maps the same: " << std::boolalpha << same << std::endl;

// equal with map ========================
std::set<int> S1{ 7,2,5,6,9,8,7,6 };
std::set<int> S2{ 2,7,9,6,5,7,6,8 };

same = equal(begin(S1),end(S1),begin(S2),end(S2));
std::cout << "are sets the same: " << std::boolalpha << same << std::endl;

// mismatch ==============================
auto firstchange = mismatch(begin(mV1),end(mV1), begin(mV2));
int mV1_val = *firstchange.first;
int mV2_val = *firstchange.second;

// shows how long the two containers stayed the same.
auto distance1 = firstchange.first-begin(mV1);
auto distance2 = firstchange.second-begin(mV2);
std::cout << "mismatches: " << mV1_val << " "<< mV2_val <<std::endl;
std::cout << "how many simiar elements: " << distance1 << " "<< distance2 <<std::endl;

auto firstchange2 = mismatch(begin(M1),end(M1), begin(M2));
std::pair<int,int> mV3_val = *firstchange2.first;
std::pair<int,int> mV4_val = *firstchange2.second;

// shows how long the two containers stayed the same.
//auto distance3 = firstchange2.first-begin(M1);
//auto distance4 = firstchange2.second-begin(M2);
std::cout << "mismatches: " << mV3_val.first << " " << mV3_val.second <<std::endl;
std::cout << "mismatches: " << mV4_val.first << " " << mV4_val.second <<std::endl;
//std::cout << "how many simiar elements: " << distance1 << " "<< distance2 <<std::endl;


std::cout << " finished.\n";

return 0;
}
