
// Babak Poursartip
// 09/28/2020

// warp divergence

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