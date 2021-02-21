#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <iostream>
#include <numeric>
using namespace std;

__global__ void sumSingleBlock(int* d)
{
  int tid = threadIdx.x;

  // number of participating threads halves on each iteration
  for (int tc = blockDim.x, stepSize = 1; tc > 0; tc >>= 1, stepSize <<= 1)
  {
    // thread must be allowed to write
    if (tid < tc)
    {
      int pa = tid * stepSize * 2;
      int pb = pa + stepSize;
      d[pa] += d[pb];
    }
  }
}

__global__ void sumSingleBlock2(int* d)
{
  extern __shared__ int dcopy[];
  int tid = threadIdx.x;
  dcopy[tid*2] = d[tid*2];
  dcopy[tid*2+1] = d[tid*2+1];

  // number of participating threads halves on each iteration
  for (int tc = blockDim.x, stepSize = 1; tc > 0; tc >>= 1, stepSize <<= 1)
  {
    // thread must be allowed to write
    if (tid < tc)
    {
      int pa = tid * stepSize * 2;
      int pb = pa + stepSize;
      dcopy[pa] += dcopy[pb];
    }
  }

  if (tid == 0)
  {
    d[0] = dcopy[0];
  }
}

int main()
{
  cudaError_t status;

  const int count = 256;
  const int size = count * sizeof(int);
  int* h = new int[count];
  for (int i = 0; i < count; ++i)
    h[i] = i+1;

  int* d;
  status = cudaMalloc(&d, size);

  status = cudaMemcpy(d,h,size, cudaMemcpyHostToDevice);
    
  sumSingleBlock2<<<1,count/2,size>>>(d);

  int result;
  status = cudaMemcpy(&result,d,sizeof(int),cudaMemcpyDeviceToHost);

  cout << "Sum is " << result << endl;

  getchar();

  cudaFree(d);
  delete [] h;
  
  return 0;
}