// From: https://owlcation.com/stem/Copy-Constructor-shallow-copy-vs-deep-copy

// TestIt.cpp : Defines the entry point for the console application.
//
 

#include <iostream>
 
// =======================================================================
class Shallow_Copy{
private:
  int *x; //Sample 01: Private Data Member
 
public:
  Shallow_Copy(int m){ //Sample 02: Constructor with single parameter
    x = new int;       // initialize the pointer
    *x = m;
    std::cout << "ctor\n";
  }
 
  //Sample 08: Introduce Copy Constructor and perform Deep Copy
  // without this copy constructor it is a shollow copy, with it is deep constructor
  // This is the default copy constructor, which leads to a shallow copy. 
  Shallow_Copy(const Shallow_Copy &obj) {
    x = new int;
    std::cout << "default copy ctor address of x: " << x << "\n";
    x = obj.x;
    std::cout << "default copy ctor address of x: " << x << "\n";  
    std::cout << "default copy ctor\n";  
  }

  // This needs to be written by the developer to have a deep copy
  //Shallow_Copy(const Shallow_Copy &obj) {
  //  x = new int;
  //  std::cout << "default copy ctor address of x: " << x << "\n";  
  //  *x = obj.GetX();
  //  std::cout << "default copy ctor address of x: " << x << "\n";  
  //  std::cout << "copy ctor\n";  
  //}
 

  //Sample 03: Get and Set Functions
  int GetX() const {
      return *x;
  }

  void SetX(int m){
    *x = m;
  }
 
  //Sample 04: Print Function
  void PrintX() {
    std::cout << "Int X=" << *x << std::endl;
  }
 
    //Sample 05: DeAllocate the heap
  ~Shallow_Copy()  {
    delete x;
    std::cout << "dtor\n"; 
  }
};
 
// =======================================================================
int main()
{
    //Sample 06: Create Object 1 and copy that to Object 2.
    //           Print the data member for both Object 1 & 2.
    Shallow_Copy ob1(10);

    //Shallow_Copy ob2 = ob1 ; // copy constructor
    Shallow_Copy ob2(ob1) ; // copy constructor
    ob1.PrintX();
    ob2.PrintX();

    std::cout << "\n change ======\n";
    //Sample 07: Change the Data member value of Object 1
    //           And print both Object 1 and Object 2
    ob1.SetX(12);
    ob1.PrintX();
    ob2.PrintX();
}
