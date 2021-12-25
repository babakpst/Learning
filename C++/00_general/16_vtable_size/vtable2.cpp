// To see th vtable/virtual table g++ -fdump-lang-class  -c *.cpp

class P3
{
virtual void f1(){};
virtual void f2(){};
void f3(){};
virtual void f4(){};

double obj;
};

class P33
{
virtual void f31(){};
virtual void f32(){};
void f33(){};
virtual void f34(){};

double obj;
};

// ================================================================================================
class C3: public P3, public P33
{
virtual void f1(){};
void f2(){};
virtual void f3(){};


private:
  int a;

};


class C33:public C3
{
virtual void fC1(){};
virtual void f1(){};

};

