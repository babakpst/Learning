
// Babak Poursartip
// 09/15/2020

// udemy CUDA
// sum array

#include "common.h"
#include <cstdio>
#include <time.h>

// =================================
__global__ void sum_array_gpu(int *a, int *b, int *c, const int size) {
  // 1d grid, 1d block thread
  int gid = blockIdx.x * blockDim.x + threadIdx.x;
  if (gid < size) {
    c[gid] = a[gid] + b[gid];
  }
}

// =================================
void sum_array_cpu(int *a, int *b, int *c, const int size) {
  for (int i = 0; i < size; ++i) {
    c[i] = a[i] + b[i];
  }
}

// =================================
int main() {
  printf(" starts ... \n");

  int size = 10000;
  int block_size = 128;
  const int NO_BYTES = size * sizeof(int);

  int *h_a, *h_b, *h_output, *h_cpu_out;

  // allocate arrays on the host
  h_a = (int *)malloc(NO_BYTES);
  h_b = (int *)malloc(NO_BYTES);
  h_output = (int *)malloc(NO_BYTES);
  h_cpu_out = (int *)malloc(NO_BYTES);

  // initialize arrays on the host
  time_t t;
  srand((unsigned)time(&t));

  for (int i = 0; i < size; ++i) {
    h_a[i] = (int)(rand() & 0xFF);
  }

  for (int i = 0; i < size; ++i) {
    h_b[i] = (int)(rand() & 0xFF);
  }

  memset(h_output, 0, NO_BYTES);
  memset(h_cpu_out, 0, NO_BYTES);

  sum_array_cpu(h_a, h_b, h_cpu_out, size);

  // device arrays;
  int *d_a, *d_b, *d_output;

  cudaMalloc((void **)&d_a, NO_BYTES);
  cudaMalloc((void **)&d_b, NO_BYTES);
  cudaMalloc((void **)&d_output, NO_BYTES);

  cudaMemcpy(d_a, h_a, NO_BYTES, cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b, NO_BYTES, cudaMemcpyHostToDevice);

  dim3 block(block_size);
  // +1 to guarantee that we have more threads than array size
  dim3 grid(size / block.x + 1);

  sum_array_gpu<<<grid, block>>>(d_a, d_b, d_output, size);
  cudaDeviceSynchronize();

  cudaMemcpy(h_output, d_output, NO_BYTES, cudaMemcpyDeviceToHost);

  // comparison the results of cpu and gpu
  compare_arrays(h_output, h_cpu_out, size);

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_output);

  free(h_a);
  free(h_b);
  free(h_output);

  cudaDeviceReset();
  printf(" finished. \n");
  return 0;
}
