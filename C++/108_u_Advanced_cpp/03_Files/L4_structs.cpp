
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

struct abc3 {
  char a;   // 1byte
  double b; // 8byte
  char c;   // 1byte
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

class with_virtual{
int *ptr;
float fl;
bool bl;
virtual void print(){std::cout << " print this\n";};
};

int main() {
  puts(" starts \n");

  cout << "abc1: " << sizeof(abc1) << endl;
  cout << "abc2: " << sizeof(abc2) << endl;
  cout << "abc3: " << sizeof(abc3) << endl;

  cout << "Person: " << sizeof(Person) << endl;

  cout << "abc4: " << sizeof(abc4) << endl;

 cout << "===============\n";
 cout << "no_func: " << sizeof(no_func) << endl;  // 16
 cout << "no_virtual: " << sizeof(no_virtual) << endl; // 16
 cout << "with_virtual: " << sizeof(with_virtual) << endl; // 24

  puts(" \n ends");

  return 0;
}
