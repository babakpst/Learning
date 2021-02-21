
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <iostream>
using namespace std;

__global__ void runningSum(int* d)
{
  int threads = blockDim.x;
  int tid = threadIdx.x;

  for (int tc = threads, step = 1; tc > 0; step *= 2)
  {
    // check this thread is allowed to do things
    if (tid < tc)
    {
      d[tid+step] += d[tid];
    }
    tc -= step;
  }
}

int main()
{
  const int count = 16;
  const int size = count * sizeof(int);

  int h[count];
  for (int i = 0; i < count; ++i)
    h[i] = i + 1;

  int* d;
  cudaMalloc(&d, size);
  cudaMemcpy(d,h,size,cudaMemcpyHostToDevice);

  runningSum<<<1,count-1>>>(d);

  cudaMemcpy(h,d,size,cudaMemcpyDeviceToHost);
  

  for (int i = 0; i < count; ++i)
    cout << h[i] << '\t';

  cudaFree(d);

  getchar();

  return 0;
}