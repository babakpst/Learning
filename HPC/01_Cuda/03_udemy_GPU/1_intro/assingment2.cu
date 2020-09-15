#include <ctime>
#include <stdio.h>

__global__ void print_3d(int *vector) {

  int threads_per_block = blockDim.x * blockDim.y * blockDim.z;

  int index = threadIdx.x + (threadIdx.y * (blockDim.z * blockDim.x)) +
              (threadIdx.z * blockDim.z) + (blockIdx.x * threads_per_block) +
              (blockIdx.z * gridDim.x * threads_per_block) +
              (blockIdx.y * gridDim.z * gridDim.x * threads_per_block);

  printf("index: %d value: %d\n", index, vector[index]);
}

int main() {

  printf(" starts ... \n");

  int size = 64;
  int byte_size = size * sizeof(int);
  int *h_input;

  h_input = (int *)malloc(byte_size);

  for (int i = 0; i < size; i++) {
    h_input[i] = rand() % 1000;
  }

  int *d_input;

  cudaMalloc((void **)&d_input, byte_size);
  cudaMemcpy(d_input, h_input, byte_size, cudaMemcpyHostToDevice);

  int nx, ny, nz;
  nx = 4;
  ny = 4;
  nz = 4;

  dim3 block(2, 2, 2);
  dim3 grid(nx / block.x, ny / block.y, nz / block.z);
  print_3d<<<grid, block>>>(d_input);

  cudaDeviceSynchronize();

  cudaDeviceReset();

  printf(" finished. \n");
  return 0;
}