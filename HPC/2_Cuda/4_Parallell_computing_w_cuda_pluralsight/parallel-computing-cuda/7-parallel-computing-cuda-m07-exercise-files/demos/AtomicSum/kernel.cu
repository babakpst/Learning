
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "sm_20_atomic_functions.h"

#include <iostream>
using namespace std;

__device__ int dSum = 0;

__global__ void sum(int* d)
{
  int tid = threadIdx.x;
  //dSum += d[tid];
  atomicAdd(&dSum, d[tid]);
}

int main()
{
  const int count = 256;
  const int size = count * sizeof(int);

  int h[count];
  for (int i = 0; i < count; ++i)
    h[i] = i+1;

  int* d;
  cudaMalloc(&d, size);
  cudaMemcpy(d,h,size,cudaMemcpyHostToDevice);

  cudaEvent_t start, end;
  cudaEventCreate(&start);
  cudaEventCreate(&end);

  cudaEventRecord(start);

  sum<<<1,count>>>(d);

  cudaEventRecord(end);
  cudaEventSynchronize(end);

  float elapsed;
  cudaEventElapsedTime(&elapsed, start, end);

  int hSum;
  cudaMemcpyFromSymbol(&hSum, dSum, sizeof(int));
  cout << "The sum of numbers from 1 to " << count 
    << " is " << hSum << " and it took " << elapsed << " msec" << endl;
  getchar();

  cudaFree(d);

  return 0;
}