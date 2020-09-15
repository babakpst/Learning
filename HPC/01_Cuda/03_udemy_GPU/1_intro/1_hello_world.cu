

// Babak Poursartip
// 09/14/2020

// Udemy Cuda
// launch hello world

#include <iostream>

// The kernel needs a modifier before the function type, in this case __global__
// other options: __host__, __device__, __shared__
// The return type is always void !?
__global__ void hello_cuda() { printf(" Hello, CUDA is here!\n"); }

int main() {
  std::cout << " starts ...\n";

  // launch the kernal: this is an asyn function call, means that the host does
  // not need to wait until the kernel finishes its job.

  // max no. of threads/block x<=1024, y<=1024m, z<=64, and x*y*z<=1024
  // max no. grids: up to (2^31 - 1) blocks in the x, and at most 65535 blocks
  // in the y and z dimensions

  // dim3 block(4); // equivalent to block(4,1,1)
  // dim3 grid(8);  // equivalent to grid(4,1,1)

  // It is more convenient to specify the number of threads in each direction,
  // separately.
  int nx, ny;
  nx = 16;
  ny = 4;

  dim3 block(8, 2);                      // equivalent to block(4,1,1)
  dim3 grid(nx / block.x, ny / block.y); // equivalent to grid(4,1,1)

  hello_cuda<<<grid, block>>>();

  // If we want the host to wait until the kernel finishes its job, we need to
  // explicity ask the host. Host will wait here, until all previous launch
  // kernels finish their executions.
  cudaDeviceSynchronize();

  cudaDeviceReset();

  std::cout << " Finished.\n";

  return 0;
}
