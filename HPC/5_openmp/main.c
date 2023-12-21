

//#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // std::cout << " starts \n";
  printf("starts\n");
#pragma omp parallel
  {
    int mts = omp_get_max_threads();
    int its = omp_get_thread_num();
    printf("here \n");
    // std::cout << mts << " " << its << std::endl;
  }
  printf("ends\n");
  // std::cout << " end \n";
  return 0;
}
