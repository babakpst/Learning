

// Babak Poursartip
// 09/03/2020

// factorial template

#include <iostream>
using namespace std;

// ===============================
template <size_t n> struct fib; // incomplete  declaration

template <> // base case, which is also a partial specialization
struct fib<0>{
  const static auto value = 1;
};

template <> // base case, which is also a partial specialization
struct fib<1>{
  const static auto value = 1;
};


template <size_t n> struct fib{ // recursive definition
const static auto value = fib<n-1>::value+ fib<n-2>::value;
};
// ===============================

// ===============================
size_t fib_func(size_t n){
if (n<= 1) return 1; // base case
return fib_func(n-1) + fib_func(n-2); // recursion
}

// great fibonacci
constexpr size_t fib_funcg(size_t n){
return n<= 1? 1: fib_func(n-1) + fib_func(n-2); // recursion
}


// ===============================
int main(){

cout << "start ----------\n";
cout  << fib<2>::value << ' '
      << fib<3>::value << ' '
      << fib<4>::value << ' '
      << fib<5>::value << endl;

cout << "func ----------\n";
cout  << fib_func(2) << ' '
      << fib_func(3) << ' '
      << fib_func(4) << ' '
      << fib_func(5) << endl;

cout << "func g----------\n";
cout  << fib_funcg(2) << ' '
      << fib_funcg(3) << ' '
      << fib_funcg(4) << ' '
      << fib_funcg(5) << endl;

//static_assert(fct<5>::value == 120, "factorial math prob");

cout << " end  ----------\n";
return 0;
}
