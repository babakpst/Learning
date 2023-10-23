
// Babak Poursartip
// 09/28/2020

// warp divergence

//>>>>>>>>>>>>>>. to check the branch_efficiency:
// nvcc -G 2_warp_divergence.cu  -o 2_warp_divergence.out
// sudo nvprof --metrics branch_efficiency  ./2_warp_divergence.out
// here is the outpu:

/*
starts ...
size: 4194304 - block.x: 128 - grid.x: 32768
==32934== NVPROF is profiling process 32934, command: ./2_warp_divergence.out
execution time without warp divergence: 0.192828 
execution time with warp divergence: 0.008774 
done.
==32934== Profiling application: ./2_warp_divergence.out
==32934== Profiling result:
==32934== Metric result:
Invocations                               Metric Name                        Metric Description         Min         Max         Avg
Device "NVIDIA GeForce GT 1030 (0)"
   Kernel: code_without_divergence(void)
         1                         branch_efficiency                         Branch Efficiency     100.00%     100.00%     100.00%
   Kernel: code_with_divergence(void)
         1                         branch_efficiency                         Branch Efficiency      83.33%      83.33%      83.33%

*/

#include <iostream>
#include <time.h>

__global__ void code_without_divergence() 
{
  int gid = blockDim.x * blockIdx.x + threadIdx.x;

  float a = 0, b = 0;

  int warp_id = gid / 64;

  if (warp_id % 2 == 0) {
    a = 100.0;
    b = 50.0;
  } else {
    a = 200.0;
    b = 72.0;
  }
}

__global__ void code_with_divergence() 
{
  int gid = blockDim.x * blockIdx.x + threadIdx.x;

  float a = 0, b = 0;

  if (gid % 2 == 0) {
    a = 100.0;
    b = 50.0;
  } else {
    a = 200.0;
    b = 72.0;
  }
}

int main() {
  printf(" starts ...\n");

  int size = 1 << 22;
  
  dim3 block(128);
  dim3 grid((size + block.x - 1) / block.x);
  printf(" size: %d - block.x: %d - grid.x: %d\n", size, block.x, grid.x);
  
  clock_t start, end;

  start = clock();
  code_without_divergence<<<grid, block>>>();
  cudaDeviceSynchronize();
  end = clock();
  printf(" execution time without warp divergence: %4.6f \n", (double)((double)(end - start) / CLOCKS_PER_SEC));

  start = clock();
  code_with_divergence<<<grid, block>>>();
  cudaDeviceSynchronize();
  end = clock();
  printf(" execution time with warp divergence: %4.6f \n", (double)((double)(end - start) / CLOCKS_PER_SEC));

  cudaDeviceSynchronize();
  printf(" done.\n");

  return 0;
}