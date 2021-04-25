
#include "iostream"

/*
If you inherit from a base class with overloaded functions and you want to redefine or override only some of them, you need to include a using declaration for each name you would otherwise be hiding. If you do not, some of the names you would like to inherit will ge hideen. 
*/

// ==================================
class base
{

private:
int m_x;

public:
virtual void mf1() = 0;
virtual void mf1(int){std::cout << "mf1 base\n";}

virtual void mf2(){std::cout << "mf2 base\n";}
void mf3(){std::cout << "mf3 base\n";}

void mf3(double){std::cout << "mf3 base double \n";}

};

// ==================================
class derived: public base
{

private:

public:
// all the functions mf1 and mf3 in the base class are hidden by the functions named mf1 and mf3 in the derived class. 
// Base::mf1 and Base::mf3 are not inherited by derived.

using base::mf1;
using base::mf3;

virtual void mf1(){std::cout << "mf1 derived\n";} // this hides all mf1 in the base.
void mf3(){std::cout << "mf3 derived\n";}
void mf4(){std::cout << "mf4 derived\n";}
};

// ==================================
int main()
{
std::cout << " starts ... \n";

int x =1;
double y = 1.1;
derived d;

d.mf1();
d.mf1(x); // error we do not have using ...
d.mf2();
d.mf3();
d.mf3(y);  // error if we do not have the using base::

std::cout << " ends \n";
return 0;
}


