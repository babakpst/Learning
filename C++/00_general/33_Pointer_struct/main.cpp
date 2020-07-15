
/*
Babak Poursartip
14 July 2020

struct pointer

 */

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>


struct var_list {
  int ivar1, ivar2;
  float fvar1, fvar2;
  std::vector<int> myVec;
  char *name;
};


void func( var_list *spnt){
  printf("inside the function %d, %d, %f, %f \n", spnt->ivar1, spnt->ivar2, spnt->fvar1, spnt->fvar2);

  printf(" vector inside: ");
  for (std::vector<int>::iterator it = spnt->myVec.begin(); it !=spnt->myVec.end(); ++it){
    printf(" %d ", *it);
  }
  printf("\n");

  spnt->fvar1 = spnt->fvar1*2.0;
  spnt->fvar2 = spnt->fvar2*2.0;
}

void func2(const var_list *spnt){
  printf("inside the function %d, %d, %f, %f \n", spnt->ivar1, spnt->ivar2, spnt->fvar1, spnt->fvar2);

}


int main() {

  std::cout << " the code starts ...\n";

  var_list v, *vl=&v;  // defining the pointer to the struct var_list

  // filling out the struct
  vl->ivar1 = 10;
  vl->ivar2 = 12;

  vl->fvar1 = 110.1;
  vl->fvar2 = 112.2;
  
  puts(" vector ");
  vl->myVec.resize(10);
  int i = 0;
  for (std::vector<int>::iterator it = vl->myVec.begin(); it !=vl->myVec.end(); ++it){
    *it = i++;
  }

  printf("before %d, %d, %f, %f \n", vl->ivar1,vl->ivar2,vl->fvar1,vl->fvar2);
  printf(" vector: ");
  for (std::vector<int>::iterator it = vl->myVec.begin(); it !=vl->myVec.end(); ++it){
    printf(" %d ", *it);
  }
  printf("\n");


  func(vl);
  printf("after 1 %d, %d, %f, %f \n", vl->ivar1,vl->ivar2,vl->fvar1,vl->fvar2);
  func2(vl);
  printf("after 2 %d, %d, %f, %f \n", vl->ivar1,vl->ivar2,vl->fvar1,vl->fvar2);

  std::cout << " Terminates successfully. "
            << "\n";
  return 0;
}

