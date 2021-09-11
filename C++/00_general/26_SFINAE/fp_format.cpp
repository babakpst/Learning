
/*
Babak Poursartip
09/11/2021

floating point format

The code is borrowed from:  Discoverity Modern C++, chapther 5: meta-programming.

*/


#include <iostream>
#include <limits>

// ========================================
template <typename T>
inline void test(const T & x)
{
std::cout <<  " x= " << x << " (" ;
int oldp= std::cout.precision(std::numeric_limits<T>::digits10+1);
std::cout << x << ")" << std::endl;
std::cout.precision(oldp);
}


//=========================================
template<typename T>
void values()
{
std::cout << 
std::numeric_limits<T>::lowest() << "\t│ " << 
std::numeric_limits<T>::min() << "\t│ "    << 
std::numeric_limits<T>::max() << "\t| " <<
std::numeric_limits<T>::digits10 << '\n';
}



// ========================================
int main()
{
std::cout << "\n starts here...	 \n\n";

test(1.f/3.f);
test(1./3.);
test(1./3.l);

std::cout << "\n\n";

std::cout << "type\t│ lowest()\t│ min()\t\t│ max()\t\t│ precistion\n";

std::cout << "float\t│ ";
values<float>();

std::cout << "double\t│ ";
values<double>();

std::cout << "int\t│ ";
values<int>();

std::cout << "\n\n ends here \n";
return 0;
}

