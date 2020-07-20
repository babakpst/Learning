#include <error.h>
#include <errno.h>
#include <stdlib.h>

int main() {
  double* array;

  // Allocate memory
  array = malloc(16);
  if (!array)
    error(1, errno, "unable to allocate array");

  // Underrun buffer
  array[-1] = 10;

  // Free memory
  free(array);

  return 0;
}
