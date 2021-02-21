#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

void check(cudaError_t e)
{
	if (e != cudaSuccess)
	{
		printf(cudaGetErrorString(e));
	}
}

__global__ void addArraysGPU(int* a, int* b, int* c)
{
  int i = threadIdx.x;
  c[i] = a[i] + b[i];
}

void main()
{
  const int count = 5;
  int ha[] = { 1, 2, 3, 4, 5 };
  int hb[] = { 10, 20, 30, 40, 50 };
  int hc[count];

  int *da, *db, *dc;
  int size = sizeof(int)*count;

  cudaMalloc(&da, size);
  cudaMalloc(&db, size);
  cudaMalloc(&dc, size);

  cudaMemcpy(da,ha,size,cudaMemcpyHostToDevice);
  cudaMemcpy(db,hb,size,cudaMemcpyHostToDevice);

  addArraysGPU<<<1,count>>>(da,db,dc);

  cudaMemcpy(hc,dc,size,cudaMemcpyDeviceToHost);

  printf("%d %d %d %d %d",
	  hc[0],
	  hc[1],
	  hc[2],
	  hc[3],
	  hc[4]);

  cudaFree(da);
  cudaFree(db);
  cudaFree(dc);

  //getchar();

}