
/*

Babak Poursartip
06/12/2021

keywords: virtual table, vtable, virtual pointer, vptr, sizeof


Remark:
There are four extra costs we need to pay if we want to use virtual functions in a class
1- space for virtual table array for each class
2- space for the extra virtual pointer for each class (can be seen the in the sizeof class)
3- no inlining for virtual functions
4- RTTI (Run Time Type Identification)

*/


#include "iostream"

// ================================================================================================
class empty 
{};


// ================================================================================================
class P1
{
virtual void f1(){};
};

// ================================================================================================
class C1: public P1 
{};

// ================================================================================================
// ================================================================================================
class P2
{
virtual void f1(){};
};

// ================================================================================================
class C2: public P2 
{
virtual void f1(){};
};

// ================================================================================================
// ================================================================================================
class P3
{
virtual void f1(){};
};

// ================================================================================================
class C3: public P3 
{
virtual void f1(){};
void f2(){};
virtual void f3(){};
};



// ================================================================================================
int main ()
{
std::cout << " starts ...\n";

std::cout << " size of an empty class: " << sizeof(empty) << std::endl;
std::cout << " ========== \n" ;
std::cout << " sizeof(P1): " << sizeof(P1	) << std::endl;
std::cout << " sizeof(C1): " << sizeof(C1) << std::endl;
std::cout << " ========== \n" ;
std::cout << " sizeof(P2): " << sizeof(P2) << std::endl;
std::cout << " sizeof(C2): " << sizeof(C2) << std::endl;
std::cout << " ========== \n" ;
std::cout << " sizeof(P3): " << sizeof(P3) << std::endl;
std::cout << " sizeof(C3): " << sizeof(C3) << std::endl;
std::cout << " ========== \n" ;
std::cout << " ends\n";
return 0;
}
