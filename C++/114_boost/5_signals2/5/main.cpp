/*

Babak Poursartip
01/02/2021

Reference: Boost
PluralSight

signal2: signal other classes and function that a variable has changed, 

slot functions may return values.
the result of firing a signal is a pointer to the last value.

*/

#include <iostream>
#include <boost/signals2.hpp>
using std::cout;
using std::endl;


// ============================
template<typename T> struct average
{
typedef T result_type;
template <typename II> T operator()(II one,II two) const
{
if (one == two) return T();
float sum = 0.0;
int count =0;
while (one != two)
{
sum += *one++;
count++;
}
return sum/count;
} 
};


// ============================

// ======================================
int main(int argc, char* argv[]){

boost::signals2::signal<float(float, float)>  sig;

sig.connect([](float a, float b){cout << "plus" << endl; return a + b;});
sig.connect([](float a, float b){cout << "cross" << endl; return a * b;});
std::cout << *sig(4,5) << std::endl; // pointer to the last value.


// ======================
boost::signals2::signal<float(float, float), average<float>>  sig2;

sig2.connect([](float a, float b){cout << "plus" << endl; return a + b;}); // 9
sig2.connect([](float a, float b){cout << "cross" << endl; return a * b;}); //20, (20+9)/2=14.5
std::cout << sig2(4,5) << std::endl; // pointer to the last value.

// ======================
boost::signals2::signal<void(int)> values;

values.connect_extended(
[](const boost::signals2::connection& conn, int value)
{
static int count = 0;
if (++count>5) conn.disconnect();
else
cout << "got a value of " << value << endl;
}
);

srand((unsigned)time(nullptr));
for (int i =0; i< 100; i++)
{
values(rand());
}

std::cout << " finished.\n";

return 0;
} 
