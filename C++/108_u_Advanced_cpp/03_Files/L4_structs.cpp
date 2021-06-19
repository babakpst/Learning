
// Babak Poursartip
// 08/28/2020

// Files
// Udemy: Advanced c++
// struct padding structure padding

#include <iostream>
using namespace std;

// When an object of some structure type is declared then some contiguous block
// of memory will be allocated to struct members.

// cpp pads structs to make it more efficient. Processor does not read one byte
// at a time. It reads one word. It accesses one word at a time.

// consider the following struct
struct abc1 {
  char a;
  char b;
  int c;
};

/*
NO PADDING: To access c, CPU needs to read TWO words, i.e. TWO cycles.
   a   b <-------c-------->
 | 1 | 2 | 3 | 4 || 5 | 6 | 7 | 8 |
 <---word 1------><---word 2------>
sizeof(abc) = 6

WITH PADDING: To access c, CPU needs to read ONE word, i.e. ONE cycles.
   a   b <-EMPTY-><-------c------->
 | 1 | 2 | 3 | 4 || 5 | 6 | 7 | 8 |
 <---word 1------><---word 2------>

 sizeof(abc) = 8

*/


struct abc2 {
  char a;
  int b;
  char c;
};

/*
WITH PADDING: To access c, CPU needs to read ONE word, i.e. ONE cycles.
 <-a-><-EMPTY----><-------b-------><-c-><-EMPTY---->
 | 1 | 2 | 3 | 4 || 5 | 6 | 7 | 8 || 9 | 10| 11| 12|
 <---word 1------><---word 2------><---word 3------>

 sizeof(abc) = 12
*/

/*
How data gets memory slots
1 Byte ==> can be stored at multiple of 1 memory slots
2 Byte ==> can be stored at multiple of 2 memory slots
4 Byte ==> can be stored at multiple of 4 memory slots
8 Byte ==> can be stored at multiple of 8 memory slots

*/
/*
There are member functions AND static data members. Do those have any contribution to the size of the class, objects?

The answer is no. Only the non-static data members contribute to the size of class and objects.
*/

struct abc3 {
  static double obj; // has no effects on the size
  char a;   // 1byte
  double b; // 8byte
  char c;   // 1byte ==> 24 bytes
};

struct abc5 {
  char a;   // 1byte
  double b; // 8byte
  int c;   // 1byte
};

/*
NO PADDING: double is 8 byte, and can only be stored in multiples of 8.
 <-a-><-----------b-------------------><-c->
 | 1 | 2 | 3 | 4 || 5 | 6 | 7 | 8 || 9 | 10| 11| 12 |
 <---word 1------><---word 2------><---word 3------>

sizeof(abc) = 10


WITH PADDING:
 <a><----EMPTY---><-----------b----------><-c-><------EMPTY---->
 |1|2|3|4|5|6|7|8||9|10|11|12|13|14|15|16||17|18|19|20|22|23|24|
 <---word 1------><---word 2-------------><--------word 3------>

 sizeof(abc) = 24

*/

// ========================================================================
struct parent
{
char a1;
int a2;
char a3;
};

struct child:public parent
{
char b1;
double b2;
int b3;
};

// ========================================================================
struct Person0 {
  char c;
  char name[50];
  // string name; // we cannot use string in struct bcs it is a pointer.
  int age;
  double weight;
};


// ========================================================================
#pragma pack(push, 1) // align the following with the boundary of one byte.

struct Person {
  char c;
  char name[50];
  // string name; // we cannot use string in struct bcs it is a pointer.
  int age;
  double weight;
};

struct abc4 {
  char a;   // 1byte
  double b; // 8byte
  char c;   // 1byte
};

#pragma pack(pop) // terminate the effects of pack.

class no_func{
int *ptr;
float fl;
bool bl;
};

class no_virtual{
int *ptr;
float fl;
bool bl;
void print(){std::cout << " print this\n";};
};

// vtable vptr size
class with_virtual{
int *ptr;
float fl;
bool bl;
virtual void print(){std::cout << " print this\n";};
};

// struct in class
class struct_class{
float fl;

char obj1;
//double obj3;
char obj4;

abc3 obj;
abc1 obj2;
bool bl;
bool bl2;
//char obj5;
//int obj6;
double obj6;
};


int main() {
  puts(" starts \n");

  cout << "abc1: " << sizeof(abc1) << endl;
  cout << "abc2: " << sizeof(abc2) << endl;
  cout << "abc3: " << sizeof(abc3) << endl;
  cout << "abc5: " << sizeof(abc5) << endl;

  cout << "parent: " << sizeof(parent) << endl;
  cout << "child: "  << sizeof(child) << endl;

  cout << "Person0: " << sizeof(Person0) << endl;
  cout << "Person: " << sizeof(Person) << endl;
  cout << "abc4: " << sizeof(abc4) << endl;


 cout << "===============\n";
 cout << "SIZEOF:: no_func: " << sizeof(no_func) << 
                  "- int: " << sizeof(int) << 
                  "- int*: " << sizeof(int*) << 
                  "- float: " << sizeof(float) <<
                  "- bool: " << sizeof(bool) <<  
                  "- char: " << sizeof(char) <<  
                  endl;  // 16
 cout << "===============\n";
 cout << "SIZEOF::   int*: "    << sizeof(int*)    << 
                  "- float*: "  << sizeof(float*)  << 
                  "- double*: " << sizeof(double*) <<
                  "- abc1*: "    << sizeof(abc1*)  <<
                  "- void*: "    << sizeof(void*)  <<                      
                                     endl;  // 16
 cout << "no_virtual: " << sizeof(no_virtual) << endl; // 16
 cout << "with_virtual: " << sizeof(with_virtual) << endl; // 24
 cout << "class with struct: " << sizeof(struct_class) << endl; // 24

  puts(" \n ends");

  return 0;
}
