
// Babak Poursartip
// 09/14/2020

// Udemy Cuda
// unique index calculation
#include <cstdio>

// ===========================================
// 2d grid, 1d block
__global__ void unique_gid_calculation_2d(int *input) {

  int tid = threadIdx.x;

  int block_offset = blockIdx.x * blockDim.x;
  int row_offset = blockIdx.y * (blockDim.x * gridDim.x);

  int gid = row_offset + block_offset + tid;
  printf(" blockIdx.x: %3d,  blockIdx.y: %3d, threadIdx.x: %3d, gid: %3d, "
         "value: %4d \n",
         blockIdx.x, blockIdx.y, tid, gid, input[gid]);
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

  dim3 block(4);
  dim3 grid(2, 2);
  printf(" data on the device: \n");
  unique_gid_calculation_2d<<<grid, block>>>(d_data);

  cudaDeviceSynchronize();

  cudaDeviceReset();
  printf(" finished.");
  return 0;
}