
// Babak Poursartip
// 09/28/2020

// warp divergence

#include <iostream>

__global__ void code_without_divergence() {
  int gid = blockDim.x * blockIdx.x + threadIdx.x;

  float a = 0, b = 0;

  int warp_id = gid / 32;

  if (warp_id % 2 == 0) {
    a = 100.0;
    b = 50.0;
  } else {
    a = 200.0;
    b = 72.0;
  }
}

__global__ void code_with_divergence() {
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
  printf("size: %d \n", size);

  dim3 block(128);
  dim3 grid((size + block.x - 1) / block.x);

  code_without_divergence<<<grid, block>>>();
  cudaDeviceSynchronize();

  code_with_divergence<<<grid, block>>>();
  cudaDeviceSynchronize();

  cudaDeviceSynchronize();
  printf(" finished.\n");

  return 0;
}