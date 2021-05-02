
// Babak Poursartip
// 09/14/2020

// Udemy Cuda
// dimensions, blockIdx, threadIdx, blockDim, gridDim
// blockDim.x,~.y,~.z: no. of threads in each direction of the block
// gridDim.x,~.y,~.z: no. of block in each direction of the grid

/*

    <<============== gridDim.x =  3  ========>>

                                   <blocDim.x=4>
/\   |--|--|--|--|  |--|--|--|--|  |--|--|--|--|      /\
||   |  |  |  |  |  |  |  |  |  |  |  |  |  |  |      ||
||   |--|--|--|--|  |--|--|--|--|  |--|--|--|--|  blockDim.y=2
||   |  |  |  |  |  |  |  |  |  |  |  |  |  |  |      ||
||   |--|--|--|--|  |--|--|--|--|  |--|--|--|--|      \/

gridDim.y = 2

||   |--|--|--|--|  |--|--|--|--|  |--|--|--|--|
||   |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
||   |--|--|--|--|  |--|--|--|--|  |--|--|--|--|
||   |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
\/   |--|--|--|--|  |--|--|--|--|  |--|--|--|--|

*/

#include <cstdio>
//#include <iostream>

#include <cuda_device_runtime_api.h>
#include <cuda_runtime_api.h>

__global__ void print_threadIds() {
  printf("blockDim.x=%d, blockDim.y=%d <> "
         "gridDim.x=%d, girdDim.y=%d <> "
         "blockIdx.x=%d, blockIdx.y=%d, blockIdx.z=%d <>"
         "threadIdx.x=%d, threadIdx.y=%d, threadIdx.z=%d"
         "\n",
         blockDim.x, blockDim.y, gridDim.x, gridDim.y, blockIdx.x, blockIdx.y,
         blockIdx.z, threadIdx.x, threadIdx.y, threadIdx.z);
}

// ================================================
int main() {
  printf(" starts ... ");

  int nx, ny, nz;
  nx = 4;
  ny = 4;
  nz = 4;

  dim3 block(2, 2, 2);
  dim3 grid(nx / block.x, ny / block.y, nz / block.z);

  print_threadIds<<<grid, block>>>();
  cudaDeviceSynchronize();

  cudaDeviceReset();
  return 0;
}