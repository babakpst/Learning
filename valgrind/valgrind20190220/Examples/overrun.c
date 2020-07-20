#include <error.h>
#include <errno.h>
#include <stdlib.h>

int main() {
  double* array;

  // Allocate memory
  array = malloc(10*sizeof(double));
  if (!array)
    error(1, errno, "unable to allocate array");

  // Overrun buffer
  array[10] = 1.0;

  // Free memory
  free(array);

  return 0;
}
