

// Babak Poursartip
// 09/15/2020

// udemy CUDA
// memory management in cude
// start thread in a multiple of 32

#include <cstdio>
#include <cstdlib>
#include <time.h>

// =================================
__global__ void mem_trs_test(int *input) {
  // 1d grid, 1d block
  int gid = blockDim.x * blockIdx.x + threadIdx.x;
  printf(" tid: %3d, gid: %3d, value: %4d \n", threadIdx.x, gid, input[gid]);
}

// =================================
__global__ void mem_trs_test2(int *input, int size) {
  // 1d grid, 1d block
  int gid = blockDim.x * blockIdx.x + threadIdx.x;
  if (gid < size)
    printf(" tid: %3d, gid: %3d, value: %4d \n", threadIdx.x, gid, input[gid]);
}

// =================================
int main() {
  printf(" starts ... \n");

  //  int size = 128;
  int size = 150;
  int byte_size = sizeof(int) * size;

  int *h_input;
  h_input = (int *)malloc(byte_size);

  time_t t;
  srand((unsigned)time(&t));

  for (int i = 0; i < size; ++i) {
    h_input[i] = (int)(rand() & 0xff);
  }

  int *d_input;

  // (void*) double pointer
  cudaMalloc((void **)&d_input, byte_size);
  cudaMemcpy(d_input, h_input, byte_size, cudaMemcpyHostToDevice);

  dim3 block(64);
  dim3 grid(2);

  mem_trs_test<<<grid, block>>>(d_input);
  cudaDeviceSynchronize();

  printf("\n second part ========\n \n");

  block.x = 32;
  grid.x = 5;

  mem_trs_test2<<<grid, block>>>(d_input, size);
  cudaDeviceSynchronize();

  cudaFree(d_input);
  free(h_input);

  cudaDeviceReset();
  printf(" finished. \n");
  return 0;
}
