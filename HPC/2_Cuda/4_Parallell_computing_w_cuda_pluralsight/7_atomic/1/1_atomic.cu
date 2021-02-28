
// Babak Poursartip
// 02/27/2021

// CUDA
//topic: atomic

#include <iostream>
#include "sm_20_atomic_functions.h"

// ==============================
__device__ int dSum=0;

__global__ void sumArray(int* d)
{
  int tid = threadIdx.x;
  dSum +=d[tid];

}

// ==============================
__global__ void sumArrayAtomic(int* d)
{
  int tid = threadIdx.x;
  atomicAdd(&dSum, d[tid]);

}

// ==============================
int main()
{
printf(" starts \n");

const int count = 256;
const int size = count * sizeof(int);

int h[count];

for (int i = 0; i < count; ++i) h[i] = i+1;

int* d;
cudaMalloc(&d, size);
cudaMemcpy(d,h, size, cudaMemcpyHostToDevice);

int Sum;
sumArray<<<1, count>>>(d);
cudaMemcpyFromSymbol(&Sum, dSum, sizeof(int));
std::cout << " sum is: " << Sum << std::endl;

sumArrayAtomic<<<1, count>>>(d);
cudaMemcpyFromSymbol(&Sum, dSum, sizeof(int));
std::cout << " sum is: " << Sum << std::endl;

cudaFree(d);

printf(" done \n");
return 0;
} 
