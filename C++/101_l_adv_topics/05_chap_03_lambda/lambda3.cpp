// poly-lambda.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-10
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    long n = 42;
    auto fp = [](const auto & n) ->auto { return n * 4; };
    auto x = fp(n);
    
    cout << "value of x: " << x << " type of x: " << typeid(x).name() << endl;
    
    return 0;
}
