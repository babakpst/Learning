
/*

Babak Poursartip
11/04/2020

source: advanced c programming, linkedin

topic: nested tenary operation.

*/
#include <stdio.h>

int main(){

  int age;
  const char *out;
  
  printf("your age?\n");
  scanf("%d", &age);

  //(age<19)? out = "kid": ((age<50? out="adult":out="old"));
  out = (age<19)? "kid": ((age<50? "adult":"old"));

  printf(" you are: %s \n",out);

  return 0;
}
