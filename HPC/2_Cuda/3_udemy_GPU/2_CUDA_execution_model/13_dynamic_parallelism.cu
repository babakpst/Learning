
// to build
// nvcc 13_dynamic_parallelism.cu -arch=sm_61 -rdc=true -o 13
// For profiler:  sudo nvvp ./exec 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #include "cuda.h"
// #include "cuda_runtime.h"
// #include "devive_launch_parameters.h"

__global__ void dynamic_parallelism(int size, int depth)
{
  printf("depth: %d - tid: %d \n", depth, threadIdx.x);

  if (size==1) return;

  if (threadIdx.x==0)
  {
    dynamic_parallelism<<<1,size/2>>>(size/2, depth+1);
  }
}


int main(int argc, char* argbv[])
{

  dynamic_parallelism<<<1,16>>>(16,0);
  cudaDeviceSynchronize();
  cudaDeviceReset();

  printf(" done\n");

  return 0;
}

