

// Babak Poursartip
// 09/03/2020

// factorial template

#include <iostream>
using namespace std;

template <size_t n> struct fact; // incomplete  declaration


template <> // base case, which is also a partial specialization
struct fact<0>{
  const static auto value = 1;
};


template <size_t n> struct fact{ // recursive definition
const static auto value = n * fact<n-1>::value;
};

int main(){

cout << "start ----------\n";
cout  << fact<2>::value << ' '
      << fact<3>::value << ' '
      << fact<4>::value << ' '
      << fact<5>::value << endl;

static_assert(fact<5>::value == 120, "factorial math prob");

cout << " end  ----------\n";
return 0;
}
