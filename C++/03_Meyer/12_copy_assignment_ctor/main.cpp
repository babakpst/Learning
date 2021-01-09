
/*

Babak Poursartip
01/09/2021

source: Effective C++, Meyer

Topic:
item 12: The takeaway is that when we define the copy ctor and the assignment operator for the child class, we need to take care of the parent's variables.

*/

#include <iostream>

// ==================================
class parent{

private:
  int m_var1;
  int *m_p;
  double m_var2;

public:

  parent():m_var1(0), m_var2(0.0), m_p(new int(11)){} // default ctro
  parent(int a, int p, double b):m_var1(a), m_p(new int(p)), m_var2(b){} // ctor

  // copy ctor
  parent(const parent &rhs):
    m_var1(rhs.m_var1),
    m_var2(rhs.m_var2),
    m_p(new int(*rhs.m_p))
  {
  }

  // assignment operator
  parent &operator=(const parent &rhs)
  {
    if (&rhs != this)
    {
      m_var1 = rhs.m_var1;
    }
    return *this;
  }

  // setter
  void setInt(int a){m_var1=a;}
  void setPtr(int a){m_p=new int(a);}
  void setDouble(double a){m_var2=a;}

  // getters
  int getInt()const{return m_var1;}
  int getPtr()const{return *m_p;}
  double getDouble()const{return m_var2;}
};

// ==================================
class child: public parent{

private:
  int m_cvar1;
  int *m_cp;
  double m_cvar2;

public:

child():parent(), m_cvar1(8), m_cp(new int(9)), m_cvar2(19.01) {}
child(int const pa, int const pb, double const pc, int const ca, int const cb, double const cc):
parent(pa, pb, pc), m_cvar1(ca), m_cp(new int(cb)), m_cvar2(cc) {}

// copy ctor
child(child const &rhs)
{
  m_cvar1 = rhs.m_cvar1;
  //delete m_cp;
  m_cp = new int(*rhs.m_cp);
  m_cvar2 = rhs.m_cvar2;

  // we need to take care of the parent's variables, otherwise they would not be copies here.
  setInt(rhs.getInt());
  //delete m_cp;
  setPtr(rhs.getPtr());
  setDouble(rhs.getDouble());
}

// assignment operator
child &operator=(child const &rhs)
{
  if (this != &rhs)
  {
    m_cvar1 = rhs.m_cvar1;
    delete m_cp;
    m_cp = new int(*rhs.m_cp);
    m_cvar2 = rhs.m_cvar2;    

    // we need to take care of the parent's variables, otherwise they would not be copies here.
    setInt(rhs.getInt());
    //delete m_cp;
    setPtr(rhs.getPtr());
    setDouble(rhs.getDouble());

  }
  return *this;
}

  // getter for the child class
  int getCInt(){return m_cvar1;}
  int getCPtr(){return *m_cp;}
  double getCDouble(){return m_cvar2;}
};

// ==================================
int main(){

std::cout << " starts ...\n";

// 1 ==============================
std::cout << " 1 ==============================\n";
parent myP1;
std::cout << " default ctor: " << myP1.getInt() << " " << myP1.getPtr() << " " << myP1.getDouble() << std::endl;

parent myP2(15, 16, 1.1);
std::cout << "ctor: " << myP2.getInt() << "  " << myP2.getPtr() << "  " << myP2.getDouble() << std::endl;

parent myP3(myP2);
std::cout << "copy ctor: " << myP3.getInt() << "  " << myP3.getPtr() << "  " << myP3.getDouble() << std::endl;

parent myP4;
myP4 = myP3;
std::cout << "assignment operator: " << myP4.getInt() << "  " << myP4.getPtr() << "  " << myP4.getDouble() << std::endl;

std::cout << " 2 ==============================\n";
child myChild;
std::cout << " == default ctor: \n child: " << myChild.getCInt() << " " << myChild.getCPtr() << " " << myChild.getCDouble() 
          << "\n parent: "  << myChild.getInt() << " " << myChild.getPtr() << " " << myChild.getDouble() << "\n";

child myChild2(1,2,3.1,4,5,6.1);
std::cout << " == ctor: \n child: " << myChild2.getCInt() << " " << myChild2.getCPtr() << " " << myChild2.getCDouble() 
          << "\n parent: "  << myChild2.getInt() << " " << myChild2.getPtr() << " " << myChild2.getDouble() << "\n";


child myChild3(myChild2);
std::cout << " == copy ctor: \n child: " << myChild3.getCInt() << " " << myChild3.getCPtr() << " " << myChild3.getCDouble() 
          << "\n parent: "  << myChild3.getInt() << " " << myChild3.getPtr() << " " << myChild3.getDouble() << "\n";

child myChild4;
myChild4 = myChild3;
std::cout << " == assingment: \n child: " << myChild4.getCInt() << " " << myChild4.getCPtr() << " " << myChild4.getCDouble() 
          << "\n parent: "  << myChild4.getInt() << " " << myChild4.getPtr() << " " << myChild4.getDouble() << "\n";

std::cout << " finished!\n";

return 0;
}





























