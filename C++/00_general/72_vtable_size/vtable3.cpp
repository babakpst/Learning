// To see th vtable/virtual table g++ -fdump-lang-class  -c *.cpp

class P1
{
virtual void f11(){};
virtual void f12(){};
};

class P2
{
virtual void f21(){};
virtual void f22(){};
};

class P3
{
virtual void f31(){};
virtual void f32(){};
};
// ================================================================================================
class C1: public P1, public P2, public P3
{
//virtual void f11(){};
//virtual void f21(){};
//virtual void f31(){};
};



class P4
{
virtual void f41(){};
};
class P5
{
virtual void f51(){};
};
class C2:public P4, public P5
{};
