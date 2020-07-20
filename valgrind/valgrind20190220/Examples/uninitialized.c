#include <stdio.h>

int main() {
  double array[10];

  // Execution depends on uninitialized value
  if (array[4] < 0.0)
    printf("the results is negative\n");
  else if (array[4] == 0.0)
    printf("the results is zero\n");
  else if (array[4] > 0.0)
    printf("the results is positive\n");
  else
    printf("the results are special\n");

  return 0;
}
