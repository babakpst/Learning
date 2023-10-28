// #include "cuda_runtime.h"
// #include "device_launch_parameters.h"
#include <stdio.h>
#include <iostream>

#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }

inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort = true)
{
	if (code != cudaSuccess)
	{
		fprintf(stderr, "GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
		if (abort) exit(code);
	}
}

__global__ void scan_efficient_1G(int * input, int* auxiliry_array, int input_size);
__global__ void scan_summation(int * input, int * auxiliry_array, int input_size);

__global__ void testprint(float *d_input, int size)
{
  int tid = threadIdx.x;
  int gid = blockDim.x*blockIdx.x +tid;
  printf(" gid: %d, tid: %d, value: %f\n",gid, tid, d_input[gid]);
}


int main()
{

  int size = 64;
  float *h_input=new float[size];
  for (int i = 0; i< size; ++i)
  {
    h_input[i] = i*1.1;
    printf(" -- %f", h_input[i]);
  }
  printf("\n");

  float *d_input;
  int byte_size = size*sizeof(float);
  gpuErrchk(cudaMalloc(&d_input, byte_size));  
  gpuErrchk(cudaMemcpy(d_input, h_input, byte_size,	cudaMemcpyHostToDevice));


  dim3 block(32,1,1);
  dim3 grid(2,1,1);
  
  testprint<<<grid,block>>>(d_input, size);
  
  gpuErrchk(cudaDeviceSynchronize());

  gpuErrchk(cudaFree(d_input));
	free(h_input);
	gpuErrchk(cudaDeviceReset());

  printf(" done \n");  
  return 0;
}