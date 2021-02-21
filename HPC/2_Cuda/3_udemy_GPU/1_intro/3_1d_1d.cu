
// Babak Poursartip
// 09/14/2020

// Udemy Cuda
// unique index calculation
#include <cstdio>

// ===========================================
__global__ void unique_idx_calc_threadIdx(int *input) {
  int tid = threadIdx.x;
  printf(" my threadIdx: %d,value: %d \n", tid, input[tid]);
}

// ===========================================
// 1d grid, 1d block
__global__ void unique_gid_calculation(int *input) {
  int tid = threadIdx.x;
  int offset = blockIdx.x * blockDim.x;
  int gid = tid + offset;
  printf(" blockIdx.x: %d, threadIdx.x: %d, gid: %d, value: %d \n", blockIdx.x,
         tid, gid, input[gid]);
}

// ===========================================
int main() {
  printf(" starts ...");

  int array_size = 8;
  int array_byte_size = sizeof(int) * array_size;
  int h_data[] = {1, 2, 3, 4, 5, 6, 7, 8}; // array on the host

  printf(" data on the host: \n");
  for (int i = 0; i < array_size; ++i)
    printf(" %d", h_data[i]);
  printf("\n\n");

  int *d_data; // array on the device

  cudaMalloc((void **)&d_data, array_byte_size);
  cudaMemcpy(d_data, h_data, array_byte_size, cudaMemcpyHostToDevice);

  /*
  dim3 block(8);
  dim3 grid(1);
  printf(" data on the device: \n");
  unique_idx_calc_threadIdx<<<grid, block>>>(d_data);
  */

  dim3 block(4);
  dim3 grid(2);
  printf(" data on the device: \n");
  unique_gid_calculation<<<grid, block>>>(d_data);

  cudaDeviceSynchronize();

  cudaDeviceReset();
  printf(" finished.\n");
  return 0;
}
