
// Babak Poursartip
// 09/29/2020

// section 2: video 24

/*
- If each warp is not fully occupant, that would be a wast of resources.
- We need to calculate the occupancy of SM which is equal to:
   occupancy = active warps/max warps
  * max warps can be obtained from the device manual.
  * active warps needs to be calculated: it is equal to the min of warps
obtained based on the size of register and shared memory. Refer to the slides
2-6

- To get the value of the shared memory and register, use the following command:
nvcc --ptxas-options=-v -o 4_occupancy_test.out 4_occupancy_test.cu


- Warp allocation granularity means that warps are allocated in multiples of a
number. For example, multiples of 4.

- Use the excel sheet to calculate the CUDA occupancy.

*/
#include <iostream>

__global__ void occupancy_test(int *results) {
  int gid = blockDim.x * blockIdx.x + threadIdx.x;

  int x1 = 1;
  int x2 = 2;
  int x3 = 3;
  int x4 = 4;
  int x5 = 5;
  int x6 = 6;
  int x7 = 7;
  int x8 = 8;
  results[gid] = x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8;
}

int main() {
  int size = 1 << 16;
  printf(" size: %d \n", size);

  int byte_size = size * sizeof(int);

  int *d_results;
  cudaMalloc((void **)&d_results, byte_size);
  cudaMemset(d_results, 0, byte_size);

  dim3 block(128);
  dim3 grid((size + block.x - 1) / block.x);
  printf(" grids: %d, block: %d \n", grid.x, block.x);
  occupancy_test<<<grid, block>>>(d_results);
  cudaDeviceSynchronize();
  return 0;
}