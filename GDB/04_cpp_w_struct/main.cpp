
/*
Babak Poursartip
14 July 2020

struct pointer

 */

#include <iostream>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>


struct var_list {
  int ivar1, ivar2;
  float fvar1, fvar2;
  std::vector<int> myVec;
  char *name;
};

void func(var_list *spnt) {
  printf("inside the function %d, %d, %f, %f \n", spnt->ivar1, spnt->ivar2,
         spnt->fvar1, spnt->fvar2);

  printf(" vector inside: ");
  for (std::vector<int>::iterator it = spnt->myVec.begin();
       it != spnt->myVec.end(); ++it) {
    printf(" %d ", *it);
  }
  printf("\n");

  spnt->fvar1 = spnt->fvar1 * 2.0;
  spnt->fvar2 = spnt->fvar2 * 2.0;
}

void func2(const var_list *spnt) {
  printf("inside the function %d, %d, %f, %f \n", spnt->ivar1, spnt->ivar2,
         spnt->fvar1, spnt->fvar2);
}

int main() {

  int watch_var =0;
  std::cout << " the code starts ...\n";

  var_list v, *vl = &v; // defining the pointer to the struct var_list

  // filling out the struct
  vl->ivar1 = 10;
  vl->ivar2 = 12;

  vl->fvar1 = 110.1;
  vl->fvar2 = 112.2;


  watch_var =1;
  // puts(" vector ");
  // printf(" vector ");
  std::cout << " vector\n";
  vl->myVec.resize(10);
  int i = 0;
  for (std::vector<int>::iterator it = vl->myVec.begin(); it != vl->myVec.end();
       ++it) {
    *it = i++;
  }

  printf("before %d, %d, %f, %f \n", vl->ivar1, vl->ivar2, vl->fvar1,
         vl->fvar2);
  printf(" vector: ");
  watch_var =2;
  for (std::vector<int>::iterator it = vl->myVec.begin(); it != vl->myVec.end();
       ++it) {
    printf(" %d ", *it);
  }
  printf("\n");

  func(vl);
  printf("after 1 %d, %d, %f, %f \n", vl->ivar1, vl->ivar2, vl->fvar1,
         vl->fvar2);
  func2(vl);
  printf("after 2 %d, %d, %f, %f \n", vl->ivar1, vl->ivar2, vl->fvar1,
         vl->fvar2);

  watch_var =3;
  std::cout << " watch " << watch_var << std::endl;
  std::cout << " vector and loop ==================\n";
  int arr_size = 10;
  int add=5;
  std::vector<int> myVec(arr_size);
  iota(begin(myVec),end(myVec),1);
  for (int i =0; i<arr_size+add; ++i)
    std::cout << " v[" << i << "]=" << myVec[i] << std::endl;

  std::cout << " Terminates successfully. "
            << "\n";
  return 0;
}


