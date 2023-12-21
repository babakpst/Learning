
#include <stdio.h>

#include <iostream>
#include <sstream>

// pointer to function

// ======================================================================
void func1(int *ptr) { *ptr = 12; }

// ======================================================================
int globalVar = 13;
void func2(int **ptr)
{
  *ptr = &globalVar;  // the one level dereference of ptr(which would be the value of the pointer) points to global
}

// ======================================================================
void func3(const int *ptr)
{
  //*ptr = 12; // error
  int aa = *ptr;
  std::cout << aa << '\n';
}

// ======================================================================
// pass a “Reference to a pointer” to a function
// function to change Reference to pointer value
void changeReferenceValue(int *&pp) { pp = &globalVar; }

// ======================================================================
void changeReferenceValue2(int *&pp) { *pp = 124578; }

float *tax4;
// ======================================================================
// ======================================================================
// ======================================================================
int main()
{
  std::cout << "this is inside the code \n";

  puts("checkpoint 000 ================================");
  int pp = 10;
  int *p1;

  p1 = &pp;

  std::cout << " here is the pointer: " << p1 << "\n";                     // prints the address of the pointer
  std::cout << " here is value the pointer is pointing: " << *p1 << "\n";  // 10

  p1++;  // moving to the next address

  std::cout << " here is the pointer: " << p1 << "\n";  // prints another address
  std::cout << " here is value the pointer is pointing: " << *p1
            << "\n";  // prints some random number, bcs it has not been initialized.

  puts("checkpoint 100 ================================");
  float mintax = 12.0f;
  float *tax = &mintax;

  std::cout << " here is the pointer: " << tax << "\n";                     // prints an address
  std::cout << " here is value the pointer is pointing: " << *tax << "\n";  // 12
  *tax += 0.1 * mintax;  // changes the content of the memory that the tax pointer is pointing (i.e. mintax)
  std::cout << " here is value the pointer is pointing: " << *tax << " " << mintax << "\n";  // 13.2 13.2

  puts("checkpoint 101 ================================");
  /*
  ==important ===
  Directly assigning values to C Pointers
  https://stackoverflow.com/questions/17665793/directly-assigning-values-to-c-pointers

  The problem is that you're not initializing the pointer. You've created a
  pointer to "anywhere you want"—which could be the address of some other
  variable, or the middle of your code, or some memory that isn't mapped at all.
  */
  // float *wrong;
  //*wrong = 6325.1; // runtime error, segmentation fault

  // float *p2=nullptr; //points nowhere
  //*p2 = 4.0; // runtime error, segmentation fault

  // std::cout << " uninitialized pointer: " << *p2 <<"\n";
  // std::cout << " ====================== \n";

  puts("checkpoint 200 ================================");
  float value = 0.0f;
  tax4 = &value;                                                                   // global pointer
  std::cout << " tax4: here is value the pointer is pointing: " << *tax4 << "\n";  // 0
  // value += 0.1 * mintax;
  *tax4 += 0.1 * mintax;
  std::cout << " tax4: here is value the pointer is pointing: " << *tax4 << "\n";  // 1.32

  puts("checkpoint 300 ================================");
  const int const_i = 9;
  int nonconst_i = 9;
  const int *p11 = &const_i;  // data is const, not the pointer, so pointer can point to another address

  std::cout << " here is the pointer: " << p11 << "\n";  // prints the address
  std::cout << " here is the value of the pointer: " << *p11 << "\n";
  p11++;  // changing the pointer
  std::cout << " here is the pointer: " << *p11 << "\n";

  p11 = &nonconst_i;
  // if const is on the left of *, data is const
  // if const is on the right of *, pointer is const. A const pointer should be initialized at the moment it is defined.

  // int* const p2; // pointer is const, not the data. Compile error:  uninitialized ‘const p2’
  // const int* const p3; // pointer and the data is const. Compile error:  uninitialized ‘const p2’
  // int* const p2 =&const_i; // compile error: invalid conversion from ‘const int*’ to ‘int*’
  int *const p2 = &nonconst_i;  // ok

  // These are equivalent: const int *p = &i   ====== int const *p=&i

  puts("checkpoint 400 ================================");
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

  puts("checkpoint 500 ================================");
  int iVar = 1234;
  int *myPtr = &iVar;
  std::cout << " start: " << iVar << "\n";

  func1(myPtr);
  std::cout << " after func1 return: " << *myPtr << " " << iVar << "\n";

  iVar = 123;
  std::cout << " reset: " << *myPtr << " " << iVar << "\n";

  func1(&iVar);
  std::cout << " func1 return: " << *myPtr << " " << iVar << "\n";

  func2(&myPtr);  // myPtr then points to the address of globalVar and it does not point to the address of iVar.
  std::cout << " func2 return: " << *myPtr << " " << iVar << "\n";

  iVar = 123;
  myPtr = &iVar;
  std::cout << " reset: " << *myPtr << " " << iVar << "\n";

  changeReferenceValue(myPtr);
  std::cout << " reference return *&: " << *myPtr << " " << iVar << "\n";

  iVar = 123;
  myPtr = &iVar;
  std::cout << " reset: " << *myPtr << " " << iVar << "\n";

  changeReferenceValue2(myPtr);
  std::cout << " reference2 return *&: " << *myPtr << " " << iVar << "\n";

  iVar = 123;
  myPtr = &iVar;
  std::cout << " reset: " << *myPtr << " " << iVar << "\n";

  func3(myPtr);
  std::cout << " const int *: " << *myPtr << " " << iVar << "\n";

  const int *constPtr = &iVar;
  // func1(constPtr); cannot convert const int* to int*.
  func3(constPtr);

  puts("checkpoint 600 ================================");
  int *pvec = new int[6];  // defining a vector of size 6
  pvec[0] = 10, pvec[1] = 11, pvec[2] = 12, pvec[3] = 13, pvec[4] = 14, pvec[5] = 15;
  std::cout << " vector: " << pvec[0] << " - " << pvec[1] << " - " << pvec[2] << " - " << pvec[3] << " - " << pvec[4]
            << " - " << pvec[5] << " - " << std::endl;

  std::cout << " vector: " << *pvec << " - " << *(pvec + 1) << " - " << *(pvec + 2) << " - " << *(pvec + 3) << " - "
            << *(pvec + 4) << " - " << *(pvec + 5) << " - " << std::endl;
  delete[] pvec;

  int *pvec2 = new int(6);  // defining an int pointer an initialize it with 6

  std::cout << " vector: " << *pvec2 << " - " << *(pvec2 + 1) << " - " << *(pvec2 + 2) << " - " << *(pvec2 + 3) << " - "
            << *(pvec2 + 4) << " - " << *(pvec2 + 5) << " - " << std::endl;

  puts("End of the code.");
  return 0;
}
