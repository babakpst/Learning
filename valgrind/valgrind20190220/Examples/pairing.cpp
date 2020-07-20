#include <error.h>
#include <errno.h>
#include <stdlib.h>

int main() {
  // Allocate memory
  double* array = new double[10];
  if (!array)
    error(1, errno, "unable to allocate array");

  // Free memory
  delete array;

  return 0;
}
