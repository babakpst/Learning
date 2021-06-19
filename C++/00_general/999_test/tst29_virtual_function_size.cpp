#include "iostream"

class AA
{
public:
int aa;
virtual void funcaa(){};
};


class A
{
public:
int a;
virtual void funca(){};
};

class B: virtual public A
{
public:
int b;
virtual void funcb(){};
};

class C: public A
{
public:
int c;
virtual void funcc(){};
};

class D: public B, public C
{
public:
int d;
virtual void funcD(){};
};

class DD: public A, public AA
{
public:
int dd;
virtual void funcdD(){};
};



int main()
{

std::cout << " size A: " << sizeof(A) << "\n"
          << " size B: " << sizeof(B) << "\n"
          << " size C: " << sizeof(C) << "\n"          
          << " size D: " << sizeof(D) << "\n"          
          << " size DD:" << sizeof(DD) << "\n";

return 0;
}
