#include <error.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  unsigned int index;
  double* array0;
  double* array1;

  // Allocate memory
  array0 = malloc(16*sizeof(double));
  array1 = malloc(16*sizeof(double));
  if (!array0 || !array1)
    error(1, errno, "unable to allocate array");

  // Initialize second array
  for (index = 0; index < 16; index += 1)
    array1[index] = 0.0;

  // Overrun first array into second
  array0[18] = 1.0;

  // Print second array
  printf("array[1] = {");
  for (index = 0; index < 16; index += 1)
    printf(" %g", array1[index]);
  printf(" }\n");

  // Free memory
  free(array1);
  free(array0);

  return 0;
}
