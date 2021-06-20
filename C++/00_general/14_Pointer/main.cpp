
#include <iostream>
#include <sstream>
#include <stdio.h>

// pointer to function

// ======================================================================
void func1(int *ptr)
{
*ptr = 12;
}

// ======================================================================
int globalVar =13;
void func2(int **ptr)
{
  *ptr = &globalVar; // the one level dereference of ptr(which would be the value of the pointer) points to global
}

// ======================================================================
void func3(const int *ptr)
{
//*ptr = 12; // error
int aa = *ptr;
std::cout << aa << '\n';
}



// ======================================================================
//pass a “Reference to a pointer” to a function
// function to change Reference to pointer value
void changeReferenceValue(int*& pp)
{
    pp = &globalVar;
}

// ======================================================================
void changeReferenceValue2(int*& pp)
{
    *pp = 124578;
}




float *tax4;
// ======================================================================
// ======================================================================
// ======================================================================
int main() {

  std::cout << "this is inside the code \n";

  puts("checkpoint 000 ================================");
  int pp = 10;
  int *p1;

  p1 = &pp;

  std::cout << " here is the pointer: " << p1 << "\n";
  std::cout << " here is value the pointer is pointing: " << *p1 << "\n";

  p1++;

  std::cout << " here is the pointer: " << p1 << "\n";
  std::cout << " here is value the pointer is pointing: " << *p1 << "\n";
  std::cout << " ====================== \n";

  // =========
  puts("checkpoint 100 ================================");
  float mintax = 12.0f;
  float *tax = &mintax;

  std::cout << " here is the pointer: " << tax << "\n";
  std::cout << " here is value the pointer is pointing: " << *tax << "\n";
  *tax += 0.1 * mintax;
  std::cout << " here is value the pointer is pointing: " << *tax << " " << mintax <<"\n";
  std::cout << " ====================== \n";

  puts("checkpoint 101 ================================");
  /*
  ==important ===
  Directly assigning values to C Pointers
  https://stackoverflow.com/questions/17665793/directly-assigning-values-to-c-pointers

  The problem is that you're not initializing the pointer. You've created a
  pointer to "anywhere you want"—which could be the address of some other
  variable, or the middle of your code, or some memory that isn't mapped at all.
  float *tax2;
  *tax2 = 6325.1;
  */
  //float *p2=nullptr; //points nowhere
  //*p2 = 4.0;
  
  //float *p2; //points to random number
  //*p2 = 4.0;
  //std::cout << " uninitialized pointer: " << *p2 <<"\n";
  //std::cout << " ====================== \n";

  puts("checkpoint 200 ================================");

  float *tax2;
  tax2 = &mintax;
  *tax2 = 6325.1;

  std::cout << " here is value the pointer is pointing: " << *tax2 << "\n";
  *tax2 += 0.1 * mintax;
  std::cout << " here is value the pointer is pointing: " << *tax2 << "\n";
  std::cout << " ====================== \n";

  //======
  puts("checkpoint 300 ================================");
  float value = 0.0f;
  tax4 = &value;
  std::cout << " tax4: here is value the pointer is pointing: " << *tax4 << "\n";
  // value += 0.1 * mintax;
  *tax4 += 0.1 * mintax;
  std::cout << " tax4: here is value the pointer is pointing: " << *tax4  << "\n";
  std::cout << " ====================== \n";

  //    ======
  puts("checkpoint 400 ================================");
  const int i = 9;
  const int *p11 = &i; // data is const, not the pointer

  std::cout << " here is the pointer: " << p11 << "\n";
  std::cout << " here is the value of the pointer: " << *p11 << "\n";
  p11++;
  std::cout << " here is the pointer: " << *p11 << "\n";
  std::cout << " ====================== \n";

  // int* const p2; // pointer is const, not the data
  // const int* const p3; // pointer and the data is const

  // if const is on the left of *, data is const
  // if const is on the right of *, pointer is const

  // These are equivalent: const int *p = &i   ====== int const *p=&i

  //    ======
  puts("checkpoint 500 ================================");
  int *p13, *p12 = new int;
  p13 = new int;

  std::cout << " here is the pointer: " << p12 << "\n";
  *p12 = 1456;
  std::cout << " here is the value of the pointer: " << *p12 << "\n";
  p12++;
  std::cout << " here is the pointer: " << *p12 << "\n";
  std::cout << " here is the pointer: " << p13 << "\n";
  *p13 = 18;
  std::cout << " here is the value of the pointer: " << *p13 << "\n";

  //    ======
  puts("checkpoint 600 ================================");
  int iVar = 1234;
  int *myPtr = &iVar;
  std::cout << " start: " << iVar << "\n";

  func1(myPtr);
  std::cout << " after func1 return: " << *myPtr<< " " << iVar << "\n";      

  iVar =123;
  std::cout << " reset: " << *myPtr<< " " << iVar << "\n";      

  func1(&iVar);
  std::cout << " func1 return: " << *myPtr<< " " << iVar << "\n";      

  func2(&myPtr); // myPtr then points to the address of globalVar and it does not point to the address of iVar.
  std::cout << " func2 return: " << *myPtr<< " " << iVar << "\n";
 
  iVar =123;
  myPtr = &iVar;
  std::cout << " reset: " << *myPtr<< " " << iVar << "\n";       
 
  changeReferenceValue(myPtr);
  std::cout << " reference return *&: " << *myPtr<< " " << iVar << "\n";       

  iVar =123;
  myPtr = &iVar;
  std::cout << " reset: " << *myPtr<< " " << iVar << "\n";       
 
  changeReferenceValue2(myPtr);
  std::cout << " reference2 return *&: " << *myPtr<< " " << iVar << "\n";       
  
  iVar =123;
  myPtr = &iVar;
  std::cout << " reset: " << *myPtr<< " " << iVar << "\n";       
 
  func3(myPtr);
  std::cout << " const int *: " << *myPtr<< " " << iVar << "\n";       
  
  const int *constPtr = &iVar;
  //func1(constPtr); cannot convert const int* to int*.
  func3(constPtr);
  
  puts("End of the code.");
  return 0;
}
