
// Babak Poursartip
// 02/28/2021

// CUDA
//topic: event- measure the time in CUDA.

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


// adding the events to this kernel <<<<<<<<<<<<<<<<<<<<<<<<<
cudaEvent_t start, end;
cudaEventCreate(&start);
cudaEventCreate(&end);

cudaEventRecord(start);

sumArrayAtomic<<<1, count>>>(d);

cudaEventRecord(end);
cudaEventSynchronize(end);

float elapsed;
cudaEventElapsedTime(&elapsed, start, end); // converts the event into milisecond.

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

cudaMemcpyFromSymbol(&Sum, dSum, sizeof(int));
std::cout << " sum is: " << Sum << std::endl;

std::cout << " The operation took: " << elapsed << "ms\n";

cudaFree(d);

printf(" done \n");
return 0;
} 
