
// Babak Poursartip
// 09/16/2020

// udemy CUDA
// Error: cudaError
// We cannot use cudaError to check the launch part of the function.

#include "common.h"
#include <cstdio>
#include <time.h>

// =================================
// cuda error check macro
#define gpuErrchk(ans)                                                         \
  { gpuAssert(ans, __FILE__, __LINE__); }

inline void gpuAssert(cudaError_t code, const char *file, int line,
                      bool abort = true) {
  if (code != cudaSuccess) {
    fprintf(stderr, "GPUassert: %s. File: %s, line: %d. \n",
            cudaGetErrorString(code), file, line);
    if (abort) {
      // printf(" Exists from the gpuErrorCheck func.\n");
      exit(code);
    }
  }
}

// =================================
__global__ void sum_array_gpu(int *a, int *b, int *c, int *out,
                              const int size) {
  // 1d grid, 1d block thread
  int gid = blockIdx.x * blockDim.x + threadIdx.x;
  if (gid < size) {
    out[gid] = a[gid] + b[gid] + c[gid];
  }
}

// =================================
void sum_array_cpu(int *a, int *b, int *c, int *out, const int size) {
  for (int i = 0; i < size; ++i) {
    out[i] = a[i] + b[i] + c[i];
  }
}

// =================================
int main() {
  printf(" starts ... \n");

  int size = 1 << 20;
  const int NO_BYTES = size * sizeof(int);
  //  int block_size = 64;
  int block_size;
  printf(" Enter block size: ");
  scanf("%d", &block_size);

  printf(" size: %d, block_size: %d \n", size, block_size);

  int *h_a, *h_b, *h_c; // input arrays
  int *h_gpu_output, *h_cpu_output;

  // allocate arrays on the host
  h_a = (int *)malloc(NO_BYTES);
  h_b = (int *)malloc(NO_BYTES);
  h_c = (int *)malloc(NO_BYTES);

  h_gpu_output = (int *)malloc(NO_BYTES);
  h_cpu_output = (int *)malloc(NO_BYTES);

  // initialize arrays on the host
  time_t t;
  srand((unsigned)time(&t));

  for (int i = 0; i < size; ++i) {
    h_a[i] = (int)(rand() & 0xFF);
    h_b[i] = (int)(rand() & 0xFF);
    h_c[i] = (int)(rand() & 0xFF);
  }

  // for (int i = 0; i < size; ++i) {
  // h_b[i] = (int)(rand() & 0xFF);
  // }

  memset(h_gpu_output, 0, NO_BYTES);
  memset(h_cpu_output, 0, NO_BYTES);

  // cpu vector summation
  clock_t cpu_start, cpu_end;
  cpu_start = clock();
  sum_array_cpu(h_a, h_b, h_c, h_cpu_output, size);
  cpu_end = clock();

  // device arrays;
  int *d_a, *d_b, *d_c, *d_output;

  gpuErrchk(cudaMalloc((void **)&d_a, NO_BYTES));
  gpuErrchk(cudaMalloc((void **)&d_b, NO_BYTES));
  gpuErrchk(cudaMalloc((void **)&d_c, NO_BYTES));
  gpuErrchk(cudaMalloc((void **)&d_output, NO_BYTES));

  clock_t htod_start, htod_end;
  htod_start = clock();
  gpuErrchk(cudaMemcpy(d_a, h_a, NO_BYTES, cudaMemcpyHostToDevice));
  gpuErrchk(cudaMemcpy(d_b, h_b, NO_BYTES, cudaMemcpyHostToDevice));
  gpuErrchk(cudaMemcpy(d_c, h_c, NO_BYTES, cudaMemcpyHostToDevice));
  htod_end = clock();

  dim3 block(block_size);
  // +1 to guarantee that we have more threads than array size
  dim3 grid(size / block.x + 1);

  clock_t gpu_start, gpu_end;
  gpu_start = clock();
  sum_array_gpu<<<grid, block>>>(d_a, d_b, d_c, d_output, size);
  gpuErrchk(cudaDeviceSynchronize());
  gpu_end = clock();

  clock_t dtoh_start, dtoh_end;
  dtoh_start = clock();
  gpuErrchk(
      cudaMemcpy(h_gpu_output, d_output, NO_BYTES, cudaMemcpyDeviceToHost));
  dtoh_end = clock();

  // comparison the results of cpu and gpu
  compare_arrays(h_gpu_output, h_cpu_output, size);

  // printing execution time

  printf(" htod mem transfer time: %4.6f \n",
         (double)((double)(htod_end - htod_start) / CLOCKS_PER_SEC));

  printf(" dtoh mem transfer time: %4.6f \n",
         (double)((double)(dtoh_end - dtoh_start) / CLOCKS_PER_SEC));

  printf(" Sum array GPU execution time: %4.6f \n",
         (double)((double)(gpu_end - gpu_start) / CLOCKS_PER_SEC));

  printf(" Sum array GPU total execution time: %4.6f \n",
         (double)((double)(dtoh_end - htod_start) / CLOCKS_PER_SEC));

  printf(" Sum array CPU execution time: %4.6f \n",
         (double)((double)(cpu_end - cpu_start) / CLOCKS_PER_SEC));

  gpuErrchk(cudaFree(d_a));
  gpuErrchk(cudaFree(d_b));
  gpuErrchk(cudaFree(d_c));
  gpuErrchk(cudaFree(d_output));

  free(h_a);
  free(h_b);
  free(h_c);
  free(h_gpu_output);
  free(h_cpu_output);

  cudaDeviceReset();
  printf(" finished. \n");
  return 0;
}
