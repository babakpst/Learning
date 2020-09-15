
// Babak Poursartip
// 09/14/2020

/*
From geeksforgeeks.

void pointer: void * – a pointer that points to some data location in storage,
which doesn’t have any specific type.

Important Points:
1- void pointers cannot be dereferenced. It can however be done using
typecasting the void pointer 2- Pointer arithmetic is not possible on pointers
of void due to lack of concrete value and thus size.
*/

#include <iostream>

using namespace std;

//====================================================
int main() {
  cout << " starts \n";
  cout << "\n1-----\n";

  int x = 4;
  float y = 5.5;

  // A void pointer
  void *ptr;
  ptr = &x;

  // (int*)ptr - does type casting of void
  // *((int*)ptr) dereferences the typecasted void pointer variable.
  printf("Integer variable is = %d", *((int *)ptr));

  // void pointer is now float
  ptr = &y;
  printf("\nFloat variable is= %f", *((float *)ptr));

  cout << " \n ends\n";

  return 0;
}
