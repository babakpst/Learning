#include <sstream>
#include <stdlib.h>

// =============================================================================
void f() {

  int n = 10, m = n + 2;
  int *x = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; ++i)
    x[i] = i;

  x[10] = 0, x[11] = 0; // problem 1: heap block overrun
                        // problem 2: memory leak -- x not freed

  puts(" vector: ");
  for (int i = 0; i < m; ++i)
    printf(" %d ", x[i]);

  puts("");
  // free(x);
}

// main ========================================================================
int main() {
  puts(" code strats here: ");

  f();

  puts(" Terminated successfully. ");
  return 0;
}
