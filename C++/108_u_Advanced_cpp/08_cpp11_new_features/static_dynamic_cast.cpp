
// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// static cast: 
// -This is compile time command. No run time checking.
// - static cast perform conversions between pointers to related classes, base<-->derived



// dynamic cast:
// - can be used only with pointers and references to objects. 
// - it is slower bcs it has a type check.
// -casts a derived class to the base class at the run time. It
// uses RTTI, Run Time Type Information. RTTI should be on for this cast to
// work.
// -dynamic is always successful if you cast a derived to a base.
// -If conversion is not correct, it throws bad_cast exception.
// -dynamic_cast only works with polymorphic class. Should have virtual.

/*
base       base       base->derived   base->base
 /\         |             |               |
 /\         |             |               |
 |          |             |               |
 |          \/           \/               \/
 |          \/           \/               \/
derived   derived       derived         derived
ok          wrong         ok             wrong

*/

#include <iostream>

class parent {
public:
  virtual void speak() { std::cout << "parent\n"; }
};

class brother : public parent {
void speak() { std::cout << "brother\n"; }
};
class sister : public parent {
void speak() { std::cout << "sister\n"; }
};

using namespace std;

//====================================================
int main() {
  cout << " starts \n";

  // =================================================
  cout << "\n1: static -----\n";

  float fVal = 3.2435;
  int iVal1 = fVal;      // implicit conversion
  int iVal2 = (int)fVal; // explicit conversion

  cout << " float: " << fVal << endl;
  cout << " implicit conversion: " << iVal1 << endl;
  cout << " explicit conversion: " << iVal2 << endl;
  cout << " static cast as int: " << static_cast<int>(fVal) << endl;

  int a = 50;
  // Here we copy the content of a var in double var. Thus the output is not the same.
  // This is what happens: It take the address of a, convert to a double pointer,
  // dereference it, and set in v.
  double v = *(double *) &a;

  cout << "int: " << a << " double: " << v << endl;



  // =================================================
  cout << "\n2: static -----\n";
  parent pr;
  brother br;

  parent *pp = &br;
  // borther *pb = &pr; // this is error
  brother *pb = static_cast<brother *>(&pr); // this is not safe

  parent *ppb = &br;
  cout << "checkpoint 000: " << ppb   << endl;

  brother *pbb = &br;
  // error: even though both are pointing to brother, but since the types are
  // different, they are not working. To fix it, we need to use static_cast.
  // brother *pbb2 = ppb;
  brother *pbb2 = static_cast<brother *>(ppb); // fine
  cout << pbb2 << endl;

  // rvalue referenced to parent obj
  parent &&p = parent();

  // parent &&p = pr; error lvalue cannot be set equal to rvalue! but next fine
  parent &&p2 = static_cast<parent &&>(pr);
  p2.speak();


  //========================================================
  cout << "\n3: dynamic -----\n";
  // This is valid
  parent *ppb3 = &br;
  brother *pbb3 = dynamic_cast<brother *>(ppb3);
  if (pbb3 == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << pbb3 << endl;

  // This dynamic casting results in a nullpntr, bcs this is an down cast.
  parent *ppb4 = &pr;
  brother *pbb4 = dynamic_cast<brother *>(ppb4);
  if (pbb4 == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << pbb4 << endl;

  // This dynamic casting results in a nullpntr, bcs this is an down cast.
  parent *pPar, Par;
  brother *pBro, Bro;

  // Valid
  pPar = dynamic_cast<parent *>(&Bro);
  if (pPar == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << pPar << endl;

  // invalid with warning
  pBro = dynamic_cast<brother *>(&Par);
  if (pPar == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << pPar << endl;

  //========================================================
  cout << "\n4: reinterpret_cast -----\n";
  parent par;
  brother dadash;
  sister sis;

  // invalid -> nulpntr.
  parent *ppb5 = &dadash;
  sister *psb = dynamic_cast<sister *>(ppb5);
  if (psb == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << psb << endl;

  // valid, but silly
  sister *psb2 = static_cast<sister *>(ppb5);
  if (psb2 == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << psb2 << endl;

  // even more silly that static cast, less checking.
  sister *psb3 = reinterpret_cast<sister *>(ppb5);
  if (psb3 == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << psb3 << endl;

  //========================================================
  cout << "\n5: all_casts -----\n";
  parent *obj1 = new brother;
  parent *obj2 = new sister;

  obj1->speak();
  obj2->speak();

  parent *s1 = static_cast<parent*> (obj1);
  parent *s2 = dynamic_cast<parent*> (obj1);
  parent *s3 = reinterpret_cast<parent*> (obj1);

  s1->speak();
  s2->speak();
  s3->speak();



  cout << " \n ends\n";

  return 0;
}