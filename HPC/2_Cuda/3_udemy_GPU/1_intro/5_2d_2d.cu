
// Babak Poursartip
// 09/14/2020

// Udemy Cuda
// unique index calculation
#include <cstdio>

// ===========================================
// 2d grid, 2d block
__global__ void unique_gid_calculation_2d_2d(int *input) {

  int tid = blockDim.x * threadIdx.y + threadIdx.x;

  int num_threads_in_a_block = blockDim.x * blockDim.y;
  int block_offset = blockIdx.x * num_threads_in_a_block;

  int num_threads_in_a_row = num_threads_in_a_block * gridDim.x;
  int row_offset = num_threads_in_a_row * blockIdx.y;

  int gid = tid + block_offset + row_offset;

  printf("blockIdx.x : %d, blockIdx.y : %d, threadIdx.x : %d, threadIdx.y : "
         "%d, gid : %d - data: %d \n",
         blockIdx.x, blockIdx.y, threadIdx.x, threadIdx.y, gid, input[gid]);
}

// ===========================================
int main() {
  printf(" starts ...");

  int array_size = 16;
  int array_byte_size = sizeof(int) * array_size;
  int h_data[] = {1, 2,  3,  4,  5,  6,  7,  8,
                  9, 10, 11, 12, 13, 14, 15, 16}; // array on the host

  printf(" data on the host: \n");
  for (int i = 0; i < array_size; ++i)
    printf(" %d", h_data[i]);
  printf("\n\n");

  int *d_data; // array on the device

  cudaMalloc((void **)&d_data, array_byte_size);
  cudaMemcpy(d_data, h_data, array_byte_size, cudaMemcpyHostToDevice);

  dim3 block(2, 2);
  dim3 grid(2, 2);
  printf(" data on the device: \n");
  unique_gid_calculation_2d_2d<<<grid, block>>>(d_data);

  cudaDeviceSynchronize();

  cudaDeviceReset();
  printf(" finished.");
  return 0;
}