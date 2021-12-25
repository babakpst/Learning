/*

based on pluralsight: Practical C++14 and C++17 features

*/
#include "iostream"

[[deprecated]]
void oldercode(){std::cout << "this is the older code \n";};

[[deprecated("This is an old code. Do not use it.")]]
void oldcode(){std::cout << "this is the old code \n";};


void newcode(){std::cout << "this is the new code \n";};

int main(int argc, char *argv[])
{
std::cout << " starts ... \n";

oldercode();
oldcode();
newcode();

std::cout << " ends  \n";
return 0;
}
