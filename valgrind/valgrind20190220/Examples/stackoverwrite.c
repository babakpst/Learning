#include <error.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  unsigned int index;
  double array0[16];
  double array1[16];

  // Initialize first array
  for (index = 0; index < 16; index += 1)
    array0[index] = 0.0;

  // Overrun second array into first
  array1[18] = 1.0;

  // Print first array
  printf("array0 = {");
  for (index = 0; index < 16; index += 1)
    printf(" %g", array0[index]);
  printf(" }\n");

  return 0;
}
