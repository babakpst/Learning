
// Babak Poursartip
// 09/09/2020

// Udemy: Advanced c++
// static cast: 
// - This is compile time command. No run time checking.
// - static cast perform conversions between pointers to related classes, base<-->derived



// dynamic cast:
// - can be used only with pointers and references to objects. 
// - it is slower bcs it has a type check.
// - casts a derived class to the base class at the run time. It
// uses RTTI, Run Time Type Information. RTTI should be on for this cast to
// work.
// - Dynamic is always successful if you cast a derived to a base.
// - If the reference conversion is not correct, it throws bad_cast exception.
// IMPORTANT >>>>>>>>>>>>>>>>>>>>>>>>
// - Dynamic_cast only works with polymorphic class. Should have virtual.

/*
up casting: OK --- down casting: WRONG
base       base       base->derived   base->base
 /\         |             |               |
 /\         |             |               |
 |          |             |               |
 |          \/           \/               \/
 |          \/           \/               \/
derived   derived       derived         derived
ok          wrong         ok             wrong


- Exception (see the dynamic_cast section (3b) for some examples):
- When dynamic_cast cannot cast a pointer because it is not a complete object of the required class -as in the second conversion in the previous example- it returns a null pointer to indicate the failure.

- If dynamic_cast is used to convert to a reference type and the conversion is not possible, an exception of type bad_cast is thrown instead.


- Read about const_cast down there.
*/

#include <iostream>

// heirarchy without virtual functions =========================
class base{
public:
  void speak(){}
};

class subbase{
public:
  void speak(){}
};

// heirarchy with virtual functions ============================
class parent {
public:
  virtual void speak() { std::cout << "parent speaks\n"; }
  void order() { std::cout << "parent orders.\n"; }
};

class brother : public parent {
public:
  void speak() { std::cout << "brother speaks\n"; }
  void listen() { std::cout << "brother is listening.\n"; }
};

class sister : public parent {
public:
  void speak() { std::cout << "sister speaks\n"; }
  void listen() { std::cout << "sister is listening.\n"; }
};

//====================================================
int func(int *ptr)
{
*ptr = *ptr+2;
return *ptr;
}

//====================================================
int func2(int *ptr)
{

return (*ptr+5);
}


using namespace std;

//====================================================
//====================================================
//====================================================
int main() {
  cout << " starts \n";

  // STATIC CAST =================================================
  cout << "\n1: static ---------------------------------------\n";

  float fVal = 3.2435;
  int iVal1 = fVal;      // implicit conversion
  int iVal2 = (int)fVal; // explicit conversion

  cout << " float: " << fVal << endl;
  cout << " implicit conversion: " << iVal1 << endl;
  cout << " explicit conversion: " << iVal2 << endl;
  cout << " static cast as int: " << static_cast<int>(fVal) << endl;

  double dVal=static_cast<double>(fVal);
  cout << " double-static_cast: " << dVal << endl;  


  int a = 50;
  // Here we copy the content of a var in double var. Thus the output is not the same.
  // This is what happens: It take the address of a, convert to a double pointer,
  // dereference it, and set in v.
  double v = *(double *) &a;

  cout << "int: " << a << " double: " << v << endl;

  cout << "\n2: static --------------------------------------------\n";
  parent pr;
  brother br;

  parent *pp = &br;
  pp->speak();
  //pp->listen(); // error, parent does not have listen method.
  pp->order();
  cout << "1=======\n";
  
  //brother *pb = &pr; // this is error, but we can use the static_cast.
  brother *pb = static_cast<brother*>(&pr); // this is not safe
  pb->speak();
  pb->listen(); // error, parent does not have listen method.
  pb->order();

  cout << "2=======\n";
  parent *pp2 = &pr;
  brother *pb2 = static_cast<brother*>(pp2); // this is not safe
  pb2->speak();
  pb2->listen(); // error, parent does not have listen method.
  pb2->order();

  cout << "3=======\n";
  parent *ppb = &br;
  brother *pbb = &br;

  // error: even though both are pointing to brother, but since the types are
  // different, they are not working. To fix it, we need to use static_cast.
  // brother *pbb2 = ppb;
  brother *pbb2 = static_cast<brother *>(ppb); // fine
  pbb2->speak();
  pbb2->listen(); // error, parent does not have listen method.
  pbb2->order();
  cout << "4=======\n";

  // rvalue referenced to parent obj
  parent &&p = parent();

  // parent &&p = pr; error lvalue cannot be set equal to rvalue! but next fine
  parent &&p2 = static_cast<parent &&>(pr);
  p2.speak();
  cout << "5=======\n";
  
  sister myS;
  brother myB;
  parent *myPrt = &myS;
  brother *brot2 = static_cast<brother*>(myPrt);

  brot2->listen(); 
  brot2->speak(); // displays: sister speaks.
  brot2->order();

 
  // DYNAMIC CAST ========================================================
  cout << "\n3a: dynamic_cast --------------------------------------------\n";
  // This is valid
  parent *ppb3 = &br;
  ppb3->speak();
  //ppb3->listen(); // error, this is a pointer of type parent, which does not have a listen method, even though it points to an obj of type brother.
  ppb3->order();


  brother *pbb3 = dynamic_cast<brother *>(ppb3);  // valid
  if (pbb3 == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << pbb3 << endl;  //here

  cout << "1=======\n";
  pbb3->speak();
  pbb3->listen();
  pbb3->order();


  cout << "2=======\n";
  // down casting: wrong, nullptr
  parent *ppb4 = &pr;
  brother *pbb4 = dynamic_cast<brother *>(ppb4);

  if (pbb4 == nullptr)
    cout << "Invalid dynamic cast\n";  //here
  else
    cout << pbb4 << endl;

  cout << "\n3b: dynamic_cast with exception --------------------------------------- \n";
  // This dynamic casting results in a nullpntr, bcs this is a down cast.
  parent *pPar, Par;
  brother *pBro, Bro;

  // up casting: Valid
  pPar = dynamic_cast<parent *>(&Bro);
  if (pPar == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << pPar << endl;

  // down casting: invalid with warning
  pBro = dynamic_cast<brother *>(&Par);
  if (pBro == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << pBro << endl;

  cout << "\n3c: dynamic_cast with exception ---------------------------------------\n";
  parent *pPar2, Par2;
  brother *pBro2, Bro2;

  try{
    // up casting: Valid
    pPar2 = dynamic_cast<parent *>(&Bro2);
    if (pPar2 == nullptr)
      cout << "Invalid dynamic cast\n";
    else
      cout << pPar2 << endl;
  }catch(std::bad_cast &bc){
    std::cerr<< "bad_cast caught: " << bc.what() << endl;
  }

  try{
    // down casting: invalid with warning, no exception is thrown, even though it is invalid. But the result is a nullptr.
    pBro = dynamic_cast<brother *>(&Par);
    if (pBro == nullptr)
      cout << "Invalid dynamic cast\n";
    else
      cout << pBro << endl;
  }catch(std::bad_cast &bc){
    std::cerr<< "bad_cast caught: " << bc.what() << endl;
  }

  try{
    // casting base object to derived object: invalid, exception is thrown
    brother &Bro3 = dynamic_cast<brother &>(Par2);
    if (pPar == nullptr)
      cout << "Invalid dynamic cast\n";
    else
      cout << pPar << endl;
  }catch(std::bad_cast &bc){
    std::cerr<< "bad_cast caught: " << bc.what() << endl;
  }


  cout << "\n3d: dynamic_cast wrong derived type ---------------------------------------\n";
  
  sister mysis;
  brother mybro;
  parent *myParent = &mysis;
  brother *bro2 = dynamic_cast<brother*>(myParent);
  if (bro2 == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << bro2 << endl;  
  
  cout << "\n3e: dynamic_cast without virtual ---------------------------------------\n";


  //compile error:
  //cannot dynamic_cast ‘& SubBase’ (of type ‘class subbase*’) to type ‘class  base*’ (source type is not polymorphic)
  
  //base *ptr = new subbase;
  //subbase *s1 = dynamic_cast<subbase*>(ptr); // throws compilaiton error: (source type is not polymorphic)
  
  /*    
  base *pBase, Base;
  subbase *pSubBase, SubBase;
  
  pBase = dynamic_cast<base *>(&SubBase);
    if (pBase == nullptr)
      cout << "Invalid dynamic cast\n";
    else
      cout << pBase << endl;

  pSubBase = dynamic_cast<subbase *>(&Base);
  if (pSubBase == nullptr)
    cout << "Invalid dynamic cast\n";
  else
    cout << pSubBase << endl;
  */
 
  // REINTERPRET CAST ========================================================
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


  // CONST CAST ========================================================
  // remove the constantness of a constant
  cout << "\n4a: const_cast ---------------------------------------\n";
  //const int a1 = 20; // 
  int a1 = 20;
  const int* ptr1 = &a1;
  //int* pc = &a1; // error: cannot convert "const int*" to "int*"<<<<< important

  std::cout<< "old value is: " << *ptr1 << " and a1: " << a1 << " *&a1: " << *&a1 <<"\n";
  std::cout<< "address of the ptr: "<< ptr1 << std::endl;
  std::cout<< "address of the a1 : "<< &a1 << std::endl<< std::endl;

  //int* c=ptr1; // cannot convert const int* to int*
  int* c=const_cast<int *>(ptr1);
  *c=40;
  //int *c = new int;
  
  std::cout<<"new value is: "<< *ptr1 << " and a1: " << a1 << " c: " << *c <<std::endl<< std::endl;

  std::cout<< "address of the ptr: "<< ptr1 << std::endl;
  std::cout<< "address of      a1: "<< &a1 << std::endl;
  std::cout<< "address of       c: "<< &c << std::endl<< std::endl;

  c=nullptr;
  std::cout<< "address of the ptr: "<< ptr1 << std::endl;
  std::cout<< "address of      a1: "<< &a1 << std::endl<< std::endl;  
  //std::cout<< "address of       c: "<< &c << std::endl<< std::endl;

  //int a2 = const_cast<int>(a1); // error: const_cast only works with references and pointers.
  //std::cout<<"const cast a var: "<< a2 << std::endl;
  int *ptr_non_const = const_cast<int *>(ptr1);
  
  int out = func(ptr_non_const);
  
  std::cout<< "pass a const pointer to a func: "<< out << std::endl;  
  std::cout<< "pass a const pointer to a func: "<< *ptr1 << std::endl;
//  std::cout<< "pass a const pointer to a func: "<< *c << std::endl;    
  std::cout<< "pass a const pointer to a func: "<< a1 << std::endl;    
  //*ptr1=48; //error

  cout << "\n4b: const_cast ---------------------------------------\n";
  const int a2 = 51;
  const int* ptr2 = &a2;
  int *ptr_non_const2 = const_cast<int *>(ptr2);
  
  int out2 = func2(ptr_non_const2);
  
  std::cout<< "pass a const pointer to a func: "<< out2 << std::endl;  
  std::cout<< "pass a const pointer to a func: "<< *ptr2 << std::endl;
  std::cout<< "pass a const pointer to a func: "<< a2 << std::endl;    
  //*ptr1=48; //error


  cout << "\n4c: const_cast ---------------------------------------\n";
  int jj = 58;
  int &ref_jj= jj;
  std::cout << " jj: " << jj << " ref_jj: " << ref_jj << '\n';
  ref_jj+= 5;
  std::cout << "after jj: " << jj << " ref_jj: " << ref_jj << '\n';

  int ii = 3;                    // i is not declared const
  const int& cref_i = ii; 
  //cref_i +=5; // error
  const_cast<int&>(cref_i) = 4; // OK: modifies i
  std::cout << "i = " << ii << '\n';
  int& ref_ii = const_cast<int&>(cref_i); // OK: modifies i
  ref_ii=12;
  std::cout << "i = " << ii << '\n';
 

  //========================================================
  cout << "\n5: all_casts -----\n";
  parent *obj1 = new brother;
  parent *obj2 = new sister;

  obj1->speak();
  //obj1->listen();
  obj2->speak();
  //obj2->listen();  

  parent *s1 = static_cast<parent*> (obj1);
  parent *s2 = dynamic_cast<parent*> (obj1);
  parent *s3 = reinterpret_cast<parent*> (obj1);

  s1->speak();
  s2->speak();
  s3->speak();

  cout << " \n ends\n";

  return 0;
}
