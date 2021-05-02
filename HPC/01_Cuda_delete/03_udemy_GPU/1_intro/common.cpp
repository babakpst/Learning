
#include "common.h"

void compare_arrays(const int *a, const int *b, const int size) {
  for (int i = 0; i < size; ++i) {
    if (a[i] != b[i]) {
      printf("\n Arrays are not equal!! \n");
      return;
    }
  }
  printf("\n Arrays are identical!! \n");
}
