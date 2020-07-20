#include <error.h>
#include <errno.h>
#include <stdlib.h>

int main() {
  double* array;

  // Allocate memory
  array = malloc(10*sizeof(double));
  if (!array)
    error(1, errno, "unable to allocate array");

  // Free memory
  free(array);

  // Access released memory
  array[4] = 1.0;

  return 0;
}
