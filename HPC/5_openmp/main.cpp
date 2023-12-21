

#include <omp.h>

#include <iostream>

int main()
{
  std::cout << " starts \n";

#pragma omp parallel
  {
    int mts = omp_get_max_threads();
    int its = omp_get_thread_num();
    std::cout << " hello " << std::endl;
    // std::cout << mts << "-- " << its << std::endl;
  }

  std::cout << " end \n";
  return 0;
}
