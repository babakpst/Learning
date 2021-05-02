
// Babak Poursartip
// 09/28/2020

// section 2: video 20

#include <iostream>

__global__ void print_details_of_warps() {

  int gid = blockIdx.y + gridDim.x * blockDim.x + blockIdx.x * blockDim.x +
            threadIdx.x;

  int warp_id = threadIdx.x / 32;
  int gbid = blockIdx.y * gridDim.x + blockIdx.x;
  printf(" tid: %d, bid.x: %2d, bid.y: %d, gid: %3d, warp_id: %d, gbid: %d\n",
         threadIdx.x, blockIdx.x, blockIdx.y, gid, warp_id, gbid);
}

int main() {

  printf(" starts ...\n");

  dim3 block(42);
  dim3 grid(2, 2);

  print_details_of_warps<<<grid, block>>>();
  cudaDeviceSynchronize();

  printf(" finished \n");

  cudaDeviceReset();
  return EXIT_SUCCESS;
}
